#!/bin/bash

if [ $# -ne 2 ]
then
	echo $*
	echo Usage $0 programm start/stop.
	exit 1
fi

case $2 in

'start')
	./$1 > /dev/null 2>&1 &
	;;
'stop')
	PID=`pgrep $1`
	kill $PID
	;;
*)
	echo Usage $0 programm start/stop.
esac

exit 0

