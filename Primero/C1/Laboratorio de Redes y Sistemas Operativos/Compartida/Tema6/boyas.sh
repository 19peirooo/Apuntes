#!/bin/bash

Boya1=(35 41 90 65 66 100 41 39 39 57 31 37)
Boya2=(37 41 43 58 59 46 45 66 41 39 39 57)
Boya3=(23 27 35 63 68 57 23 56 53 56 67 69)

MaxB1=(90 65 66 100)
MaxB2=(58 59 66 57)
MaxB3=(63 68 67 69)

Hs=()

calcular_Hs() {
    local media=0
	media=$(( (${MaxB1[0]} + ${MaxB1[1]} + ${MaxB1[2]} + ${MaxB1[3]}) / 4 ))
	Hs[0]=$media
	media=$(( (${MaxB2[0]} + ${MaxB2[1]} + ${MaxB2[2]} + ${MaxB2[3]}) / 4 ))
    Hs[1]=$media
	media=$(( (${MaxB3[0]} + ${MaxB3[1]} + ${MaxB3[2]} + ${MaxB3[3]}) / 4 ))
    Hs[2]=$media
}

mayor_Hs() {
	for ola in "${Boya1[@]}"
	do
		if [ $ola -gt ${Hs[0]} ]
		then
			echo "La Ola de la Boya 1 con altura $ola es mas alta que el Hs"
		fi
	done
	echo
	for ola in "${Boya2[@]}"
        do
                if [ $ola -gt ${Hs[1]} ]
                then
                        echo "La Ola de la Boya 2 con altura $ola es mas alta que el Hs"
                fi
        done
	echo
	for ola in "${Boya3[@]}"
        do
                if [ $ola -gt ${Hs[2]} ]
                then
                        echo "La Ola de la Boya 3 con altura $ola es mas alta que el Hs"
                fi
        done
}

generar_Fichero() {
	if [ ! -f datos_boyas.txt ]
	then
		touch datos_boyas.txt
	else
		truncate -s 0 datos_boyas.txt
	fi
	echo "Boya: 1 - Hs: ${Hs[0]}" > datos_boyas.txt
	echo "Boya: 2 - Hs: ${Hs[1]}" >> datos_boyas.txt
	echo "Boya: 3 - Hs: ${Hs[2]}" >> datos_boyas.txt
}
while true
do
	opcion=
	echo -e "\n1. Hs de Cada Boya."
	echo "2. Olas con altura mayor que Hs"
	echo "3. Fichero con Hs de cada boya"
	echo -e "4. Salir del Programa\n"
	while [ -z $opcion ]
	do
		read -p "Introduce un opcion: " opcion
	done
	case $opcion in
		1)
			calcular_Hs
			j=1
			for i in "${Hs[@]}"
			do
				echo "Boya $j: $i"
				(( j++ ))	
			done
		;;
		2)
			if [ ${#Hs[@]} -eq 0 ]
			then
				calcular_Hs
			fi
			mayor_Hs
		;;
		3)
			if [ ${#Hs[@]} -eq 0 ]
                        then
                                calcular_Hs
                        fi

			generar_Fichero
		;;
		4)
			exit
		;;
		*)
			echo -e "\nEntrada invalida, prueba de nuevo"
		;;
	esac
done
