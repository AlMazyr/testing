#!/bin/bash

# TODO: Check count and correctness of args.

WORK_DIR=`pwd`/$1
PATTERNS_DIR="/home/mazyrin/testing_stuff/patterns"
C_SOURCE=$PATTERNS_DIR/main_pattern.c
CPP_SOURCE=$PATTERNS_DIR/main_pattern.cpp
C_MAKE=$PATTERNS_DIR/c_makefile/Makefile
CPP_MAKE=$PATTERNS_DIR/cpp_makefile/Makefile


mkdir $WORK_DIR

#TODO: Replace if on switch
if [ $2 = "c" ]
then 
    SOURCE_FILE=$C_SOURCE
    MAKE_FILE=$C_MAKE
else
    SOURCE_FILE=$CPP_SOURCE
    MAKE_FILE=$CPP_MAKE
fi


cp $SOURCE_FILE $WORK_DIR/$1.c
cp $MAKE_FILE $WORK_DIR/


exit 0

