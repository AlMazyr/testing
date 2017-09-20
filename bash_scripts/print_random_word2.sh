#!/bin/bash

WORD_SIZE=$1
WORDS_FILE='/usr/share/cracklib/cracklib-small'

WORDS_TOTAL=$( cat $WORDS_FILE | egrep -x "\w{$WORD_SIZE}" | wc -l )
let "WORD_RAND_NUM = $RANDOM % $WORDS_TOTAL"

cat $WORDS_FILE | egrep -x "\w{$WORD_SIZE}" | head -n $WORD_RAND_NUM | tail -n 1
