#!/bin/bash

while read -r line 
do
	echo "Line from file - $line"
done < $1

