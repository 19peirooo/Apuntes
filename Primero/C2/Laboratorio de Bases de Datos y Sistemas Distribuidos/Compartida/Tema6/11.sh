#!/bin/bash

#Calcular el seno hiperbolico de 2. sinh(x) = (e^x -e^(-x))/2


x=2
((y=-1 * x))

echo $y

sinh=$(echo " scale=3; shx=(( (e($x)-e($y))/2 )); shx " | bc -l)

echo "Resultado: $sinh"
