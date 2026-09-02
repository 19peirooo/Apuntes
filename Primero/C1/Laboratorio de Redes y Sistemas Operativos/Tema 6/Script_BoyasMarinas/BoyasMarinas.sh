#!/bin/bash

calculo_Hs () {

		echo
		echo "MaxB1: ${MaxB1[@]}"
		echo "MaxB2: ${MaxB2[@]}"
		echo "MaxB3: ${MaxB3[@]}"
		echo
		total1=0
		total2=0
		total3=0
		echo
		for (( i=0; i<=3; i++ )); do
			total1=$(( $total1 + ${MaxB1[i]} ))
			total2=$(( $total2 + ${MaxB2[i]} ))
			total3=$(( $total3 + ${MaxB3[i]} ))
		done
		Hs[0]=$(( $total1/$num_olas_altas ))
		Hs[1]=$(( $total2/$num_olas_altas ))
		Hs[2]=$(( $total3/$num_olas_altas ))
		echo ">>>>>  Hs Boya 1: ${Hs[0]}" 
		echo ">>>>>  Hs Boya 2: ${Hs[1]}" 
		echo ">>>>>  Hs Boya 3: ${Hs[2]}" 
		echo	
		echo
}

function ola_mas_alta_Hs {

	total1=0
	total2=0
	total3=0
	echo
	for (( i=0; i<=3; i++ )); do
		total1=$(( $total1 + ${MaxB1[i]} ))
		total2=$(( $total2 + ${MaxB2[i]} ))
		total3=$(( $total3 + ${MaxB3[i]} ))
	done
	Hs[0]=$(( $total1/$num_olas_altas ))
	Hs[1]=$(( $total2/$num_olas_altas ))
	Hs[2]=$(( $total3/$num_olas_altas ))

	echo "Las alturas significativas de las boyas son: "
	echo "Hs1: ${Hs[0]}"	
	echo "Hs2: ${Hs[1]}"	
	echo "Hs3: ${Hs[2]}"	
	echo
	echo "==> Boya1"
	for ola in "${Boya1[@]}"; do
 		if [[ $ola -gt ${Hs[0]} ]]; then
			echo -e ">>>>>  La ola de la Boya 1 de altura $ola es mayor que su Hs1: ${Hs[0]}"
  		fi
	done
	echo

	echo "==> Boya2"
	for ola in "${Boya2[@]}"; do
 		if [[ $ola -gt ${Hs[1]} ]]; then
			echo -e ">>>>>  La ola de la Boya 2 de altura $ola es mayor que su Hs2: ${Hs[1]}"
  		fi
	done
	echo

	echo "==> Boya3"
	for ola in "${Boya3[@]}"; do
 		if [[ $ola -gt ${Hs[2]} ]]; then
			echo -e ">>>>>  La ola de la Boya 3 de altura $ola es mayor que su Hs3: ${Hs[2]}"
  		fi
	done
	echo

}


function generar_fichero() {
		total1=0
		total2=0
		total3=0
		echo
		for (( i=0; i<=3; i++ )); do
			total1=$(( $total1 + ${MaxB1[i]} ))
			total2=$(( $total2 + ${MaxB2[i]} ))
			total3=$(( $total3 + ${MaxB3[i]} ))
		done
		Hs[0]=$(( $total1/$num_olas_altas ))
		Hs[1]=$(( $total2/$num_olas_altas ))
		Hs[2]=$(( $total3/$num_olas_altas ))
                echo
                echo ">>> El resultado se guardará en el fichero: fichero_boyas.txt de este directorio"
                echo
                if [ -f fichero_boyas.txt ]
                then
                        rm fichero_boyas.txt
                fi
		n=1
                for (( i=0; i<$n_boyas; i++ )); do
                        echo "Boya: $n >>> Hs$1: ${Hs[$i]}" >> fichero_boyas.txt
                        ((n++))
                done
                echo
                echo "El contenido del fichero es: "
                cat fichero_boyas.txt

}





echo "BOYAS MARINAS"
echo "============="
echo 
echo "Podrás elegir alguna de las siguientes opciones del menu prinicpal"

Boya1=(35 41 90 65 66 100 41 39 39 57 31 37)
Boya2=(37 41 43 58 59 46 45 66 41 39 39 57)
Boya3=(23 27 35 63 68 57 23 56 53 56 67 69)

MaxB1=(90 65 66 100)
MaxB2=(58 59 66 57)
MaxB3=(63 68 67 69)

n_boyas=3
num_olas_altas=4

while true; do
echo
echo
echo "Elige la opción del informe que quieras obtener:"
echo
echo "1. 	Calcular e imprimir el valor de las 3 Alturas Significativas"	
echo "2.	Calcular las olas (del conjunto de 12) con una media superior a la Altura Signficativa (Hs)"
echo "3.	Generar un fichero que contenga una linea por boya con su Hz." 
echo "4.	Salir"
read opcion

if [[ $opcion = 1 ]] 
	then
		echo "Has elegido la opcion: $opcion"
		echo
		calculo_Hs
		echo
	elif [[ $opcion = 2 ]]
		then
			echo "Has elegido la opcion: $opcion"
			echo
			ola_mas_alta_Hs 
			echo
		elif [[ $opcion = 3 ]]
			then
				echo "Has elegido la opcion: $opcion"
				echo
				generar_fichero
				echo
			elif [[ $opcion = 4 ]]
				then
					echo "Opcion: $opcion, Bye!!!!"
					break
				else
					echo "Opcion incorrecta"
	fi
done
