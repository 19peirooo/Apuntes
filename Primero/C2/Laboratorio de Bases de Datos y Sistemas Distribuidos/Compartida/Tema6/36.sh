#!/bin/bash

fichero=
while [ -z $fichero ]
do
	read -p "Introduce nombre del fichero: " fichero
done

ruta=$(echo "${HOME}/${fichero}") 

if [ -f $ruta ]
then
	echo "Fichero encontrado"
else
	echo "Fichero no encontrado"
	touch $ruta
fi
