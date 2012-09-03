#!/bin/sh

gcc -o DMSClient_full -D_LARGEFILE64_SOURCE -Wall -Wno-unused-variable -DHAVE_CONFIG_H -g -DDEBUG  -I. -Iclient -I${AXIS2C_HOME}/include/axis2-1.6.0  -L${AXIS2C_HOME}lib/ -laxutil -laxis2_parser -lguththila -laxis2_http_sender -laxis2_http_receiver -laxis2_http_common -laxis2_engine -laxis2_axiom -lpthread DMSClient.c client-marshal-adb.c  client/*.c
