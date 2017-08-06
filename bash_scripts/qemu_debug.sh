#!/bin/bash

# Author: Mazyrin Alexander <algoritmist1618@gmail.com>

if [ $# -ne 2 ]
then
	echo "Bad args. Usage $0 KERNEL INITRD"
	exit 1
fi

qemu-system-x86_64 -s -enable-kvm -kernel $1 -initrd $2 -append 'console=ttyS0' -nographic
