#include<stdio.h>
#include<stdlib.h>

#include"client-marshal.h"

int
main(int argc, char** argv)
{
    axis2_char_t endpoint_uri[256];
    dmsStub *st  = NULL;
    int rc;
    if(argc < 3)
    {
        printf("USAGE: DMSClient <host:port> <command> <opts>\n");
        exit(1);
    }
    //get the server uri
    //should change the uri to your own use
    snprintf(endpoint_uri, 256, " http://%s/axis2c/services/DmsServer", argv[1]);
    
    st = dmsStubCreate(endpoint_uri, NULL, NULL);

   if(!strcmp(argv[2], "productComplete")) { 
        char *productCategory,*productName;
        if(argv[3]) productCategory = argv[3];
        if(argv[4]) productName = argv[4];
        rc = dmsProductCompleteStub(st, productCategory, productName);
        if(rc != 0) {
            printf("dms productComplete failed \n");
            exit(1);
        }
    }
    exit(0);
}
