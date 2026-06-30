#!/bin/bash
# ---------------------------------------------------------------------
# Script: kub_addNode.sh
# Purpose: Automatically add a new Kubernetes worker node to the cluster.
# ---------------------------------------------------------------------

if [ ! -f "./labsuser.pem" ]; then
    echo "Missing key file: ./labsuser.pem ..."
    echo "Exiting..."
    exit 1
fi

if [ -z "$1" ]; then
    echo "Usage: ./kub_addNode.sh <NEW_WORKER_IP>"
    exit 1
fi

NEWWORKER=$1
HOST=$(hostname)

# Must run on the master
if [[ "$HOST" != *"k8smaster"* ]]; then
    echo "🚫 ERROR: This script must be executed from the control-plane node."
    exit 1
fi

MASTER_IP=$(hostname -I | awk '{print $1}')       # 💡 Get master IP
MASTER_HOST=$(hostname)                           # 💡 Get master hostname

# ---------------------------------------------------------------------
# Determine correct worker index (reuse if IP already present)
# ---------------------------------------------------------------------
EXISTING_ENTRY=$(grep -E "^${NEWWORKER}[[:space:]]" /etc/hosts)

if [ -n "$EXISTING_ENTRY" ]; then
    # IP already exists — extract existing slave index
    EXISTING_INDEX=$(echo "$EXISTING_ENTRY" | grep -oP 'k8sslave\K[0-9]+')
    if [ -n "$EXISTING_INDEX" ]; then
        NUMWORKERS=$EXISTING_INDEX
        echo "♻️  Worker IP ${NEWWORKER} already present as k8sslave${NUMWORKERS}.psdi.org — reusing index."
        # Clean up any duplicate lines for this IP before reusing
        sudo sed -i "/^${NEWWORKER}[[:space:]]/d" /etc/hosts
    else
        echo "⚠️  Existing entry for ${NEWWORKER} has no slave tag — cleaning up."
        sudo sed -i "/^${NEWWORKER}[[:space:]]/d" /etc/hosts
        LAST_INDEX=$(grep -oP 'k8sslave\K[0-9]+' /etc/hosts | sort -n | tail -1)
        NUMWORKERS=$((LAST_INDEX + 1))
    fi
else
    # New IP — assign next available index
    LAST_INDEX=$(grep -oP 'k8sslave\K[0-9]+' /etc/hosts | sort -n | tail -1)
    if [ -z "$LAST_INDEX" ]; then
        NUMWORKERS=1
    else
        NUMWORKERS=$((LAST_INDEX + 1))
    fi
fi

echo ">>>"
echo "👷‍♂️ Detected next available worker index: $NUMWORKERS"
echo "👷‍♂️ Adding new worker as k8sslave${NUMWORKERS}.psdi.org ($NEWWORKER)"

# --- Copy installer scripts and key to worker -------------------------
echo ">>>"
echo "📦 Copying installer scripts and .pem to worker..."
ssh -o StrictHostKeyChecking=no -i ./labsuser.pem ubuntu@$NEWWORKER "mkdir -p ~/kub"
ssh -i ./labsuser.pem ubuntu@$NEWWORKER "chmod u+w /home/ubuntu/kub/labsuser.pem 2>/dev/null || true"
scp -i ./labsuser.pem -q *.sh *.pem ubuntu@$NEWWORKER:/home/ubuntu/kub/
ssh -i ./labsuser.pem ubuntu@$NEWWORKER "chmod 400 /home/ubuntu/kub/labsuser.pem"
ssh -i ./labsuser.pem ubuntu@$NEWWORKER "chmod +x /home/ubuntu/kub/*.sh"

# --- 💡 Ensure master entry is present in new worker’s /etc/hosts before install ---
echo ">>>"
echo "➕ Adding master entry to worker /etc/hosts..."
ssh -i ./labsuser.pem ubuntu@$NEWWORKER "echo '${MASTER_IP} ${MASTER_HOST}' | sudo tee -a /etc/hosts"

# --- Install Kubernetes prerequisites on worker ------------------------
echo ">>>"
echo "🧱 Installing Kubernetes prerequisites on the worker node..."
ssh -i ./labsuser.pem ubuntu@$NEWWORKER "cd ~/kub && ./kub_install.sh $NUMWORKERS"

# ---------------------------------------------------------------------
# Ensure correct hostname mapping on new worker
# ---------------------------------------------------------------------
MASTER_IP=$(grep "k8smaster" /etc/hosts | awk '{print $1}')
MASTER_HOST=$(grep "k8smaster" /etc/hosts | awk '{print $2}')

echo ">>>"
echo "➕ Ensuring master entry exists in worker /etc/hosts..."
# 🧹 Remove any line with same IP before adding
ssh -i ./labsuser.pem ubuntu@$NEWWORKER "sudo sed -i \"/^${MASTER_IP}[[:space:]]/d\" /etc/hosts"
# 🧩 Add or re-add master entry cleanly
ssh -i ./labsuser.pem ubuntu@$NEWWORKER "grep -q '${MASTER_HOST}' /etc/hosts || echo '${MASTER_IP} ${MASTER_HOST}' | sudo tee -a /etc/hosts > /dev/null"

# ---------------------------------------------------------------------
# Propagate known slaves from master’s /etc/hosts
# ---------------------------------------------------------------------
echo ">>>"
echo "🔁 Propagating known cluster entries to new worker..."
grep 'k8s' /etc/hosts | while read -r line; do
    IP=$(echo "$line" | awk '{print $1}')
    # 🧹 Remove any previous mapping with same IP
    ssh -i ./labsuser.pem ubuntu@$NEWWORKER "sudo sed -i \"/^${IP}[[:space:]]/d\" /etc/hosts"
    # 🧩 Add the fresh line
    ssh -i ./labsuser.pem ubuntu@$NEWWORKER "echo '${line}' | sudo tee -a /etc/hosts > /dev/null"
done

# --- Join cluster -----------------------------------------------------
echo ">>>"
echo "🤝 Joining the worker node to the Kubernetes cluster. 🤞 Cross your fingers!"
JOIN_CMD=$(kubeadm token create --print-join-command)
ssh -i ./labsuser.pem ubuntu@$NEWWORKER "sudo $JOIN_CMD"

# --- Verify and label node --------------------------------------------
echo ">>>"
echo "🔍 Verifying cluster node status..."
if kubectl get nodes -o wide | grep -q "k8sslave${NUMWORKERS}.psdi.org"; then
    echo "✅ Node k8sslave${NUMWORKERS}.psdi.org successfully joined!"
    echo ">>>"
    echo "➕ Adding worker entry to master and other nodes..."

    # 🧹 Clean up any existing line with same IP locally before adding
    sudo sed -i "/^${NEWWORKER}[[:space:]]/d" /etc/hosts
    echo "${NEWWORKER} k8sslave${NUMWORKERS}.psdi.org" | sudo tee -a /etc/hosts > /dev/null

    for NODE_IP in $(grep -oP '^172\.\d+\.\d+\.\d+' /etc/hosts | sort -u); do
        if [[ "$NODE_IP" == "$(hostname -I | awk '{print $1}')" ]]; then
            continue
        fi
        echo "   ↪ Updating $NODE_IP ..."
        # 🧹 Clean up old mapping for same IP on remote node
        ssh -i ./labsuser.pem ubuntu@$NODE_IP "sudo sed -i \"/^${NEWWORKER}[[:space:]]/d\" /etc/hosts"
        # 🧩 Add or re-add correct entry
        ssh -i ./labsuser.pem ubuntu@$NODE_IP "echo '${NEWWORKER} k8sslave${NUMWORKERS}.psdi.org' | sudo tee -a /etc/hosts > /dev/null"
    done
else
    echo "⚠️ Node not yet visible in cluster (might take a few seconds to register)"
fi

# ---------------------------------------------------------------------
# 🧩 Final consistency sync: propagate full master /etc/hosts to new worker
# ---------------------------------------------------------------------
echo ">>>"
echo "🔁 Performing final consistency sync for /etc/hosts on ${NEWWORKER}..."
grep 'k8s' /etc/hosts | while read -r line; do
    IP=$(echo "$line" | awk '{print $1}')
    ssh -i ./labsuser.pem ubuntu@$NEWWORKER "sudo sed -i \"/^${IP}[[:space:]]/d\" /etc/hosts"
    ssh -i ./labsuser.pem ubuntu@$NEWWORKER "echo '${line}' | sudo tee -a /etc/hosts > /dev/null"
done

# ---------------------------------------------------------------------
# 🧩 Reciprocal sync: propagate the new worker entry to all other nodes
# ---------------------------------------------------------------------

for NODE_IP in $(grep -oP '^172\.\d+\.\d+\.\d+' /etc/hosts | sort -u); do
    if [[ "$NODE_IP" == "$(hostname -I | awk '{print $1}')" ]]; then
        continue
    fi
    ssh -i ./labsuser.pem ubuntu@$NODE_IP \
        "sudo sed -i \"/^${NEWWORKER}[[:space:]]/d\" /etc/hosts && echo '${NEWWORKER} k8sslave${NUMWORKERS}.psdi.org' | sudo tee -a /etc/hosts > /dev/null"
done

# ---------------------------------------------------------------------
# 🧹 Deduplicate /etc/hosts across all nodes
# ---------------------------------------------------------------------
echo ">>>"
echo "🧹 Deduplicating /etc/hosts across cluster..."
for NODE_IP in $(grep -oP '^172\.\d+\.\d+\.\d+' /etc/hosts | sort -u); do
    ssh -i ./labsuser.pem ubuntu@$NODE_IP \
        "sudo awk '!seen[\$0]++' /etc/hosts > /tmp/hosts && sudo mv /tmp/hosts /etc/hosts"
done

echo ">>>"
echo "🏷️ Labeling node k8sslave${NUMWORKERS}.psdi.org as worker..."
kubectl label node "k8sslave${NUMWORKERS}.psdi.org" node-role.kubernetes.io/worker=worker --overwrite || true

echo ">>>"
echo "✅ Node k8sslave${NUMWORKERS}.psdi.org added and labeled successfully!"
