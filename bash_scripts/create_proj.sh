#!/bin/bash

# This script creates simple c or cpp makefile project.
# Author: Mazyrin Alexander.

if [ $# -ne 2 ]
then
    echo "Bad args. Usage $0 <PROJ_NAME> <PROJ_TYPE(c or cpp)>."
    exit 1
fi

WORK_DIR=`pwd`/$1
PATTERNS_DIR="/home/mazyrin/testing_stuff/patterns"
C_SOURCE=$PATTERNS_DIR/main_pattern.c
CPP_SOURCE=$PATTERNS_DIR/main_pattern.cpp
C_MAKE=$PATTERNS_DIR/c_makefile/Makefile
CPP_MAKE=$PATTERNS_DIR/cpp_makefile/Makefile

mkdir $WORK_DIR

case $2 in
    c)
        MAKE_FILE=$C_MAKE
        cp $C_SOURCE $WORK_DIR/$1.c
        ;;
    cpp)
        MAKE_FILE=$CPP_MAKE
        cp $CPP_SOURCE $WORK_DIR/$1.cpp
        ;;
    *)
        echo "Bad project type. Use \"c\" or \"cpp\"."
        exit 1
        ;;
esac

cp $MAKE_FILE $WORK_DIR/

exit 0

