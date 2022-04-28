PWD 	:= `pwd`
#CC 		= gcc
CC	= arm-linux-gcc	

SRC_PATH 	:= .
CFLAGS 		= -Os

IOT_OBJS 	= $(wildcard $(SRC_PATH)/*.c)

targets = oled

#LIBS = -lsqlite3 -lpthread -lssl -lcrypto -lcurl -lpaho-mqtt3as -lxml2 -liconv -ltaxManager -lm -ldl -g

#INCLUDESSL = -I/home/yxb/tool/tooldir/include -L/home/yxb/tool/tooldir/lib
#INCLUDECURL = -I/home/yxb/tool/curldir/include -L/home/yxb/tool/curldir/lib
#INCLUDESQLITE = -I/home/cxp/tool/SQLite/install/include -L/home/cxp/tool/SQLite/install/lib
#INCLUDEMQTT = -I/home/yxb/tool/paho.mqtt.c-master/src -L/home/yxb/tool/paho.mqtt.c-master/build/output
#INCLUDEXML =  -I/home/yxb/tool/xmldir/include/libxml2 -L/home/yxb/tool/xmldir/lib
#INCLUDEICONV = -I/home/yxb/tool/iconvdir/include -L/home/yxb/tool/iconvdir/lib
#INCLUDETAX = -I/home/yxb/tool/taxdir -L/home/yxb/tool/taxdir
#INCLUDEJSON = -I/home/yxb/tool/cjsondir/include/cjson -L/home/yxb/tool/cjsondir/lib

all:$(targets)

$(targets):$(IOT_OBJS)
#	$(CC) $(CFLAGS) $(IOT_OBJS) $(LIBS) $(INCLUDESSL) $(INCLUDECURL) $(INCLUDESQLITE) $(INCLUDEMQTT) $(INCLUDEXML) $(INCLUDETAX) -o $@ 
	$(CC) $(CFLAGS) $(IOT_OBJS) -o $@ 
clean:
	rm -f *.o $(targets) 

