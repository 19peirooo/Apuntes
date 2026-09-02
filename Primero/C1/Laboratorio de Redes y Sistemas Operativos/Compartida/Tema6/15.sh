#!/bin/bash

for i in $(ls ~)
do
	if [ $i == "README.md" ]
	then
		echo $i
	fi
done
