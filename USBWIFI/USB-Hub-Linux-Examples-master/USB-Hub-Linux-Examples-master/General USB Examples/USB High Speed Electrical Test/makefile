#Simple makefile for libusb application
# this is a proper pound sign! jolly good!

CC = arm-linux-gcc

INCLUDELIBUSB= -I/home/yxb/libusb/dir/include -L/home/yxb/libusb/dir/lib
 
USB_Linux_HSET : USB_Linux_HSET.c
		$(CC) USB_Linux_HSET.c -o usb-hset -lusb-1.0 -lpthread -lm $(INCLUDELIBUSB)
 
clean:
		rm ./usb-hset

