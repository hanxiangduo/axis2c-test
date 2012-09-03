#ifndef SERVER_MARSHAL_H
#define SERVER_MARSHAL_H
#include"axis2_skel_DmsServer.h"

adb_ProductCompleteResponse_t* ProductCompleteMarshal(adb_ProductComplete_t* productComplete, const axutil_env_t *env);

#endif
