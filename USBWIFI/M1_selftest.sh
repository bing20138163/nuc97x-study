#!/bin/sh
#num=1
#while [ "$num" -lt 5 ]; do
#	sn=`ps | grep usbipd | grep -v grep`
#	if [ "${sn}" = "" ];then
#		/sbin/usbipd -D &
#	else
#		ps | grep usbipd | grep -v grep |awk '{print $1}'|xargs kill -9
#	fi
#	sleep 15
#done

#open usb port power PB.10 
#GPIOB NUM 0x020~0x03F//32~55
echo 42 > /sys/class/gpio/unexport
sleep 1
echo 42 > /sys/class/gpio/export
echo out > /sys/class/gpio/gpio42/direction
echo 0 > /sys/class/gpio/gpio42/value
sleep 1
echo 1 >/sys/class/gpio/gpio42/value
sleep 1
echo 0 > /sys/class/gpio/gpio42/value
sleep 1
echo 1 >/sys/class/gpio/gpio42/value

#read key state PD.7
#GPIOD NUM 0x060~0x07F//96~127
echo 103 > /sys/class/gpio/export
echo in > /sys/class/gpio/gpio103/direction
sleep 1

while true
do
	cat /sys/class/gpio/gpio103/value
	sleep 1
done	