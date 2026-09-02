#!/bin/bash

MAC=$(ip a | awk '/link\/ether/ {print $2}')
IPv4 = $(ip a | awk '/inet/ {print $2}' | tail -n 2 | head -n 1)

echo $MAC
echo $IPV4
