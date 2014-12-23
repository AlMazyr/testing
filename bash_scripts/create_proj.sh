#!/bin/bash

# This script creates simple c or cpp makefile project.
# Author: Mazyrin Alexander.

if [ $# -ne 2 ]
then
    echo "Bad args. Usage $0 <PROJ_NAME> <PROJ_TYPE(c or cpp)>."
    exit 1
fi

#names
WORKSPACE_NM="workspace_stuff"
PATTERNS_DIR_NM="patterns"
C_SRC_NM="main_pattern.c"
CPP_SRC_NM="main_pattern.cpp"

#paths
WORK_DIR_PATH=`pwd`/$1
PATTERNS_DIR_PATH="$HOME/$WORKSPACE_NM/$PATTERNS_DIR_NM"
C_SRC_PATH=$PATTERNS_DIR_PATH/$C_SRC_NM
CPP_SRC_PATH=$PATTERNS_DIR_PATH/$CPP_SRC_NM
C_MAKE_PATH=$PATTERNS_DIR_PATH/c_makefile/Makefile
CPP_MAKE_PATH=$PATTERNS_DIR_PATH/cpp_makefile/Makefile

mkdir $WORK_DIR_PATH

case $2 in
    c)
        MAKE_FILE=$C_MAKE_PATH
        cp $C_SRC_PATH $WORK_DIR_PATH/$1.c
        ;;
    cpp)
        MAKE_FILE=$CPP_MAKE_PATH
        cp $CPP_SRC_PATH $WORK_DIR_PATH/$1.cpp
        ;;
    *)
        echo "Bad project type. Use \"c\" or \"cpp\"."
        exit 1
        ;;
esac

cp $MAKE_FILE $WORK_DIR_PATH/

exit 0

