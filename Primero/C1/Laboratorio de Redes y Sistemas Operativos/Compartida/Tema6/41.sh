#!/bin/bash

suma=0
num=

while [ -z $num ]
do
	read -p "Introduce un numero: " num
done

for ((i=1; i<$num; i++))
do
	if [[ $((num%i)) -eq 0 ]]
	then
		suma=$suma+$i
	fi
done

if [[ $suma -eq $num ]] || [[ $num -eq 1 ]]
then
	echo "El numero ${num} es perfecto"
else
	echo "El numero ${num} no es perfecto"
fi
