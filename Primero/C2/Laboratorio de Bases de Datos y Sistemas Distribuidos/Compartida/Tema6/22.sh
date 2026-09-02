#!/bin/bash

ping -c 5 abc.es

if [ $? -eq 0 ]
then
	echo "Conexion Exitosa"
else
	echo "Conexion Fallida"
fi
