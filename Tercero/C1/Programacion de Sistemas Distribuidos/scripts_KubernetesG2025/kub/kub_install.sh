#!/bin/bash

if [ ! -f "./labsuser.pem" ]; then
    echo "Missing key file: ./labsuser.pem ..."
	echo "Exitting..."
    exit 1
fi


INDEX=0
if [ -z "$1" ]; then
	echo  "Enter k8s node index: "
	echo  "  0   - master"
	echo  "1..10 - slaves"

	read INDEX
else
	INDEX=$1
fi

echo ">>>"
echo "♻️  Resetting installation..."
./kub_reset.sh

HOSTNAME="$INDEX"

if [ "$INDEX" -eq 0 ]; then
	ssh-keygen -t rsa
	# cache password
        if ! pgrep -u "$USER" ssh-agent > /dev/null; then
        	eval "$(ssh-agent -s)" >/dev/null 2>&1
	fi
	ssh-add ~/.ssh/id_rsa

	ssh-copy-id -f -o "IdentityFile=./labsuser.pem" ubuntu@localhost

    HOSTNAME="k8smaster${HOSTNAME}.psdi.org"
elif [ "$INDEX" -gt 0 ]; then
    HOSTNAME="k8sslave${HOSTNAME}.psdi.org"
fi

echo ">>>"
echo "🏷️  Setting hostname as : $HOSTNAME"
sudo hostnamectl set-hostname "$HOSTNAME"

# ---------------------------------------------------------------------
# Add current node to /etc/hosts (after kub_reset has already cleaned)
# ---------------------------------------------------------------------

LOCAL_IP=$(ip route get 1 | awk '{print $7; exit}')
HOSTNAME=$(hostname)
HOSTSFILE="/etc/hosts"

echo ">>>"
echo "➕ Adding $HOSTNAME ($LOCAL_IP) to /etc/hosts..."
# Just append the new entry (kub_reset already cleaned any old one)
echo "$LOCAL_IP $HOSTNAME" | sudo tee -a "$HOSTSFILE" > /dev/null
echo "✅ /etc/hosts entry created for $HOSTNAME"

#disable swap
echo ">>>"
echo "💤 Disabling swap (required for Kubernetes)..."
sudo swapoff -a
sudo sed -i '/ swap / s/^\(.*\)$/#\1/g' /etc/fstab

#configure kernel's containerd modules 
echo ">>>"
echo "🧩 Configuring kernel modules for containerd..."
sudo tee /etc/modules-load.d/containerd.conf <<EOF
overlay
br_netfilter
EOF

sudo modprobe overlay
sudo modprobe br_netfilter

#configure kubernetes network kernel parameters
echo ">>>"
echo "🌐 Configuring Kubernetes network kernel parameters..."
sudo tee /etc/sysctl.d/kubernetes.conf <<EOT
net.bridge.bridge-nf-call-ip6tables = 1
net.bridge.bridge-nf-call-iptables = 1
net.ipv4.ip_forward = 1
EOT

#update sysctl
echo ">>>"
echo "⚙️  Updating sysctl parameters..."
sudo sysctl --system

#install containerd
echo ">>>"
echo "🐳 Installing Docker and containerd runtime..."
sudo apt install -y curl gnupg2 software-properties-common apt-transport-https ca-certificates

sudo curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo gpg --dearmour -o /etc/apt/trusted.gpg.d/docker.gpg
sudo add-apt-repository -y "deb [arch=amd64] https://download.docker.com/linux/ubuntu $(lsb_release -cs) stable"

sudo apt update
sudo apt install -y  docker-ce docker-ce-cli containerd.io
#sudo apt install -y docker.io
sudo mkdir -p /etc/containerd
containerd config default | sudo tee /etc/containerd/config.toml >/dev/null 2>&1
sudo sed -i 's/SystemdCgroup \= false/SystemdCgroup \= true/g' /etc/containerd/config.toml
#sudo sed -i 's|registry.k8s.io/pause:3.8|registry.k8s.io/pause:3.9|g' /etc/containerd/config.toml

sudo chmod 666 /var/run/containerd/containerd.sock
echo ">>>"
echo "🚀 Starting Docker and containerd services..."
sudo systemctl daemon-reload

sudo systemctl enable docker
sudo systemctl restart docker

sudo systemctl restart containerd
sudo systemctl enable containerd

#install kubernetes
echo ">>>"
echo "☸️ Installing Kubernetes components (kubeadm, kubelet, kubectl)..."
curl -fsSL https://pkgs.k8s.io/core:/stable:/v1.28/deb/Release.key | sudo gpg --dearmor -o /etc/apt/keyrings/kubernetes-apt-keyring.gpg

echo 'deb [signed-by=/etc/apt/keyrings/kubernetes-apt-keyring.gpg] https://pkgs.k8s.io/core:/stable:/v1.28/deb/ /' | sudo tee /etc/apt/sources.list.d/kubernetes.list

sudo apt update
sudo apt install -y kubelet kubeadm kubectl
sudo apt-mark hold kubelet kubeadm kubectl


#if master node, install control-plane

if [ "$INDEX" -eq 0 ]; then
	if sudo lsof -i:6443 >/dev/null 2>&1; then
    		echo "⚠️ Port 6443 still in use. Killing any stray processes..."
    		sudo fuser -k 6443/tcp
    		sleep 2
	fi

	#init control plane, cross fingers
	echo ">>>"
	echo "🧭 Initializing Kubernetes control plane... 🤞 Cross your fingers!"
	sudo kubeadm init --control-plane-endpoint=$HOSTNAME --apiserver-advertise-address= --cri-socket=/var/run/containerd/containerd.sock --pod-network-cidr=192.168.0.0/16

	#install local configuration
	mkdir -p $HOME/.kube
	sudo cp -i /etc/kubernetes/admin.conf $HOME/.kube/config
	sudo chown $(id -u):$(id -g) $HOME/.kube/config

	#check configuration
	kubectl cluster-info
	kubectl get nodes

	#install Calico CNI
	echo ">>>"
	echo "🐆 Installing Calico CNI (Container Network Interface)..."
	kubectl apply -f https://raw.githubusercontent.com/projectcalico/calico/v3.26.0/manifests/calico.yaml
	echo "✅ Calico CNI deployed successfully!"
	#check k8s status
	kubectl get pods -n kube-system

	#taint for master to be able to run pods
	kubectl taint nodes --all node-role.kubernetes.io/control-plane:NoSchedule-
	# you can revert it with: kubectl taint nodes k8smaster0.psdi.org node-role.kubernetes.io/control-plane:NoSchedule

	echo ">>>"
	echo "✅ Kubernetes control-plane setup on $HOSTNAME completed!"
	echo "👉 Run 'kubectl get nodes' to verify node readiness."
	echo ""
fi

# Remove duplicate self-entry if present
sudo awk '!seen[$0]++' /etc/hosts | sudo tee /etc/hosts.tmp >/dev/null && sudo mv /etc/hosts.tmp /etc/hosts
