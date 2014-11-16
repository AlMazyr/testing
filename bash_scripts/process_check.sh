#!/bin/bash

if pgrep $1 > /dev/null 2>&1  
then
	echo Process $1 is executing.
else
	echo Process $1 is fail. Restart.
fi

exit 0
