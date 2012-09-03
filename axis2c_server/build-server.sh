
gcc -g -shared -olibDmsServer.so -fPIC -I. -I $AXIS2C_HOME/include/axis2-1.6.0/ -I ./generated -L$AXIS2C_HOME/lib \
    -laxutil \
    -laxis2_axiom \
    -laxis2_engine \
    -laxis2_parser \
    -lpthread \
    -laxis2_http_sender \
    -laxis2_http_receiver \
    -lguththila \
    *.c ./generated/*.c
