#!/bin/sh
num=1
while [ "$num" -lt 5 ]; do
	sn=`ps | grep oled | grep -v grep`
	if [ "${sn}" = "" ];then
		/root/oled &
	fi
	sleep 5
done