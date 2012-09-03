#ifndef INCLUDE_HANDLERS_H
#define INCLUDE_HANDLERS_H
#include <stdio.h>
#include <strings.h>

#include "misc.h"
#include "handler.h"

int local_init = 0;

/*int
main(int argc, char*argv[]){
    int count = 10;
    int i = 0;
    fprintf(stdout, "main start\n");
    init_localstate();
    for(i=0; i<count; i++){
        logprintf("info:get the num %d\n", i);
    }
    fprintf(stdout,"main end\n");
}
*/

int
init_localstate(void){
    int ret, log_level;
    char log_file[MAX_PATH];
    ret = 0;
    log_level = EUCADEBUG;
    if(local_init){
    }
    else
    {
        /*init the local setting*/
        bzero(log_file, MAX_PATH);
        snprintf(log_file, MAX_PATH, "/var/log/dms.log");
        logfile(log_file, log_level);
        local_init = 1;
    }
    return ret;
}

#endif
