#!/bin/bash

for i in {1..100}
do
	factores=0;
	for ((j=1; j<=$i; j++))
	do
		if [ $(( $i % $j )) -eq 0 ]
		then
			(( factores++ ))
		fi
	done
	if [ $factores -ne 2 ]
	then
		echo "El numero $i no es primo"
	else
		echo "El numero $i es primo"
	fi
done

