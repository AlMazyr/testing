#!/bin/bash

echo "File name $0"
echo "Full name `basename $0`"

echo "Count of params is $#"

if [ -n "$1" ]
then
echo $1 #param1
fi
if [ -n "$2" ]
then
echo $2 #param1
fi
if [ -n "$3" ]
then
echo $3 #param1
fi
if [ -n "$4" ]
then
echo $4 #param1
fi
if [ -n "$5" ]
then
echo $5 #param1
fi
if [ -n "$6" ]
then
echo $6 #param1
fi
if [ -n "$7" ]
then
echo $7 #param1
fi
echo "-------------"
echo "All arguments $*"

exit 0
