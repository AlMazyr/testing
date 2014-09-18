#!/bin/bash
LOG=/tmp/$USER$(date +%Y%m%d).txt
echo System information: > $LOG
echo "$(date) " >> $LOG
echo "$(who) " >> $LOG
echo "$(uptime)" >> $LOG
