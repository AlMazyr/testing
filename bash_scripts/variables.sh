#!/bin/bash

# How to use variables

a=123
HELLO=$a

echo HELLO      # HELLO
echo "HELLO"    # HELLO
echo $HELLO     # 123
echo ${HELLO}   # 123
echo '$HELLO'   # $HELLO

echo

HELLO="A  B CDE"

echo $HELLO     # A B CDE
echo "$HELLO"   # A  B CDE
