#!/bin/bash

n=0
while [ $n == 0 ] || [ -z $n ]
do 
	read -p "Intrdouce un numero: " n
done


for ((i=0; i<n; i++))
do
	randnum=$((1 + RANDOM % 1000))
	echo $randnum
done
