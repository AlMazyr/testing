#!/bin/bash

# Different types of assignment

a=879

echo "Value of \"a\" is $a"

a=7+5

echo "Value of \"a=7+5\" is $a"

let a=7+5

echo "Using \"let\" command. Value of \"a=7+5\" is $a"

echo "Using \"for\" command" 
for a in 7 8 9 11
 do
       echo -n "$a "
 done
echo 

echo "Using \"read\" command."

echo -n "Please enter the value of \"a\" "
read a
echo "Value of \"a\" is $a"


echo "Using command substitution in assignments"
a=$(echo HELLO!)
echo "Value of \"a\" is $a"
a=$(ls -l)
echo $a
echo
echo
echo "$a"


exit 0
