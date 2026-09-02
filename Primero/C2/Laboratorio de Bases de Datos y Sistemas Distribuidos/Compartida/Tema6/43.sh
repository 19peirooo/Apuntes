#!/bin/bash

suma1=0
suma2=0
num1=
num2=

while [ -z $num1 ]
do
	read -p "Introduce el primero numero: " num1
done

while [ -z $num2 ] || [ $num1 -eq $num2 ]
do
	read -p "Introduce el segundo numero: " num2
	if [ $num1 -eq $num2 ]
	then
		echo "Los numeros no pueden ser iguales"
	fi
done

for ((i=1; i<$num1; i++))
do
	if [ $(( num1 % i )) -eq 0 ]
	then
		suma1=$(( suma1 + i ))
	fi
done

for ((j=1; j<$num2; j++ ))
do
	if [ $(( num2 % j )) -eq 0 ]
	then
		suma2=$(( suma2 + j ))
	fi
done

if [ $num1 -eq $suma2 ] && [ $num2 -eq $suma1 ]
then
	echo "Los numeros $num1 y $num2 son amigos"
else
	echo "Los numeros $num1 y $num2 no son amigos"
fi
