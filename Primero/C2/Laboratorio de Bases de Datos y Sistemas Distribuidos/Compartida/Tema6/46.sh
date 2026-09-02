#!/bin/bash

num_lineas() {
	numlineas=0
	while read linea
	do
		echo $linea
		((numlineas++))
	done < alumnos.txt
	echo "Numero de lineas: $numlineas"
}

while true
do
	echo " "
	echo "1. Numero de lineas"
	echo "2. Primer Campo"
	echo "q. Salir"
	opcion=
	while [ -z $opcion ]
	do
		read -p "Introduce la opcion: " opcion
	done
	case $opcion in
		1)
			echo "$(num_lineas)"
		;;
		2)
			cut -d ' ' -f 1 alumnos.txt
		;;
		"q")
			exit
		;;
		*)
			echo "Entrada no valida"
		;;
	esac
done
