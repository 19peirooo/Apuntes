#/bin/bash

case $1 in
	"España")
		echo "Madrid"
	;;
	"Francia")
		echo "Paris"
	;;
	"Alemania")
		echo "Berlin"
	;;
	"Portugal")
		echo "Lisboa"
	;;
	"Italia")
		echo "Roma"
	;;
	*)
		echo "Pais no encontrado"
	;;
esac
