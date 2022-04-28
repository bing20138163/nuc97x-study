#!/bin/sh
num=1
flag=1
while [ "$num" -lt 5 ]; do
	if [ "$flag" = 1 ];then
		flag=2
		echo "nuc970-ehci" > /sys/bus/platform/drivers/nuc970-ehci/unbind
	elif [ "$flag" = 2 ];then
		flag=1
		echo "nuc970-ehci" > /sys/bus/platform/drivers/nuc970-ehci/bind
	fi
	sleep 5
done