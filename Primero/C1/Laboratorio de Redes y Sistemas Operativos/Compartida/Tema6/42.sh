#!/bin/bash


declare -a perfectos

i=0
num=1

while [ $i -lt 5 ]
do
	suma=0
	for ((j=1; j<$num;j++))
	do
		if [ $((num % j)) -eq 0 ]
		then
			suma=$((suma + j))
		fi
	done
	if [ $suma -eq $num ] || [ $num -eq 1 ]
	then
		perfectos[$i]=$num
		((i++))
	fi
	((num++))
done

for nums in "${perfectos[*]}"
do
	echo $nums
done
