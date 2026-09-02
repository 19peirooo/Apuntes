#!/bin/bash

clear
error="n"

case $# in
	0)
	echo "Faltan parametros"
	read -p 'Introduce el valor de num1: ' num1
	read -p 'Introduce el valor de num2: ' num2
	if [ -z $num1 ] || [ -z $num2 ] #Comprueba si estan vacias
	then
		error="s"
		echo "Alguno de los valores introducidos no es correctos"
	fi
	;;
	1)
	num1=$1
	echo "Falta 1 parametro"
	read -p 'Introduce el valor de num2: ' num2
	if [ -z $num2 ]
	then
		error="s"
		echo "Valor erroneo"
	fi
	;;
	*)
	num1=$1
	num2=$2
	;;
esac

if [ $error == "n" ]
then
	echo $num1 + $num2 = $(($num1 +$num2))
else
	echo "Error"
	exit
fi 
