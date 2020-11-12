#!/bin/bash
respuestas="respuestas.txt"
while IFS= read -r line
do 
	sleep 2
	echo "$line"
done < "$respuestas" | ./client
