#!/bin/bash
respuestas="client/respuestas.txt"
while read line
do 
	sleep 2
	echo "$line"
done < "$respuestas" | client/client
