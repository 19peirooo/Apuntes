#!/bin/bash

n=
factorial=0

num_factorial() {
	if [ $1 -eq 1 ]
	then
		echo 1
	else
		echo $(( $1 * $(num_factorial $(( $1 - 1 ))) ))
	fi
}


while [ -z $n ]
do
	read -p "Introduce un numero: " n
done

factorial=$(num_factorial $n)

echo "El factorial de $n es: $factorial"
