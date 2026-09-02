#!/bin/bash

potenciacion() {
        result=$1
        for ((i=1; i<$2; i++));
        do
                ((result=result*$1))
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

        if [ $opcion == "1" ]
        then
		 while [ -z $base ] || [ -z $exp  ]
                 do
                	 base=
                         exp= 
                         read -p "Introduce la base: " base
                         read -p "Introduce el exponente: " exp
                 done
                 echo $(potenciacion $base $exp)
	elif [ $opcion == "2" ]
	then
                 while [ -z $celsius ]
                 do
                         celsius=
                         read -p "Introduce la temperatura en Celsius: " celsius
                 done
                 echo $(conversor $celsius)

        elif [[ $opcion == "q" ]]
	then
                 exit
 
        else
                 echo "Entrada no valida"
        fi
done 
