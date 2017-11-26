#!/bin/bash

let x=0
while read -r line 
do
	let x=$x+$line
done < $1
echo $x
exit 0

