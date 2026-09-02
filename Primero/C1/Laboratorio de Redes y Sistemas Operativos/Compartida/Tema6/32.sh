#!/bin/bash

potenciacion() {
	result=$1
	for ((i=1; i<$2; i++));
	do
		echo $i
		((result=result*$1))
		echo $result
	done
	echo "Resultado = $result"
}

conversor() {
	((gradosf=((18*$1)+320)/10 ))
	echo $gradosf
}

while true
do
	echo "Seleccion de Operaciones:"
	echo "1. Potenciacion"
	echo "2. Conversor de Celsius a Farenheit"
	echo "q. Salir"

	read -p "Opcion: " opcion

	case $opcion in
		1)
			while [ -z $base ] || [ -z $exp  ]
			do
				base=
				exp= 
				read -p "Introduce la base: " base
				read -p "Introduce el exponente: " exp
			done
			echo $(potenciacion $base $exp)
		;;
		2)
			while [ -z $celsius ]
			do
				celsius=
				read -p "Introduce la temperatura en Celsius: " celsius
			done
			echo $(conversor $celsius)
		;;
		"q")
			exit
		;;
		*)
			echo "Entrada no valida"
		;;
	esac
done
