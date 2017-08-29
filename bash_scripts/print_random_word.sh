#!/bin/bash

WORDS_FILE='/usr/share/cracklib/cracklib-small'
echo $(sed "${RANDOM}q;d" $WORDS_FILE)
