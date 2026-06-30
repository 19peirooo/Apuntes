#!/bin/bash

# ---------------------------------------------------------------------
# Kubernetes Reset Script (Propagated Clean, Safe Version)
# Removes Kubernetes and Docker, cleans hosts locally and across nodes.
# ---------------------------------------------------------------------

HOST=$(hostname)
LOCAL_IP=$(hostname -I | awk '{print $1}')
HOST_ENTRY="$LOCAL_IP $HOST"

echo ">>>"
echo "🧹 Resetting Kubernetes on $HOST ($LOCAL_IP)"

# --- Step 0: Ensure SSH agent is ready for propagation ---
if ! pgrep -u "$USER" ssh-agent > /dev/null; then
    eval "$(ssh-agent -s)" >/dev/null 2>&1
fi
ssh-add ~/kub/labsuser.pem 2>/dev/null

# --- Step 1: Reset Kubernetes ---
sudo kubeadm reset -f 2>/dev/null
sudo systemctl stop docker containerd 2>/dev/null

echo ">>>"
echo "🛑 Forcing termination of residual Kubernetes processes..."
sudo systemctl stop kubelet 2>/dev/null || true
sudo pkill -9 kube-apiserver kube-controller-manager kube-scheduler etcd kubelet 2>/dev/null || true
sudo fuser -k 6443/tcp 2>/dev/null || true


# --- Step 2: Remove Kubernetes and container directories ---
echo ">>>"
echo "🧹 Removing Kubernetes and container directories on $HOST"
for DIR in \
    /etc/kubernetes \
    /var/lib/etcd \
    /opt/cni \
    /etc/cni \
    /etc/containerd \
    /etc/apt/sources.list.d/kubernetes.list \
    /var/lib/docker \
    /var/lib/containerd \
    /etc/docker \
    /etc/default/kubelet \
    /etc/apt/trusted.gpg.d/docker.gpg \
    /etc/apt/keyrings/kubernetes-apt-keyring.gpg; do
    sudo rm -rf "$DIR" 2>/dev/null
done

# --- Step 3: Purge packages ---
echo ">>>"
echo "🧹 Purging Kubernetes and Docker packages on $HOST"
sudo apt-get purge -y docker.io docker-doc docker-compose docker-compose-plugin docker-ce docker-ce-cli containerd* 2>/dev/null || true
sudo snap remove docker 2>/dev/null
sudo apt-get purge -y kubelet kubectl kubeadm kubernetes-cni cri-tools --allow-change-held-packages 2>/dev/null || true

# --- Step 4: Clean up /etc/hosts locally and across cluster ---

IS_MASTER=false
if [[ "$(hostname)" == *"k8smaster"* ]]; then
    IS_MASTER=true
fi
echo ">>>"
echo "🧹 Cleaning /etc/hosts entry for $(hostname) on all nodes"

# Remove this host's line from all other nodes (safe directional cleanup)
NODE_IPS=$(grep -oP '^172\.\d+\.\d+\.\d+' /etc/hosts | sort -u)
LOCAL_IP=$(hostname -I | awk '{print $1}')
HOST=$(hostname)

for NODE_IP in $NODE_IPS; do
    if [[ "$NODE_IP" == "$LOCAL_IP" ]]; then
        continue
    fi
    echo "   ↪ Removing $HOST from $NODE_IP ..."
    ssh -o StrictHostKeyChecking=no -i ~/kub/labsuser.pem ubuntu@$NODE_IP \
        "sudo sed -i '/${HOST}/d' /etc/hosts" 2>/dev/null || \
        echo "     ⚠️ Could not connect to $NODE_IP (skipped)"
done


# --- Step 5: Clean up user configuration ---
echo ">>>"
echo "🧹 Cleaning Kubernetes configuration on $HOST"
rm -rf ~/.kube 2>/dev/null

echo ">>>"
echo "✅ Reset complete on $HOST"
