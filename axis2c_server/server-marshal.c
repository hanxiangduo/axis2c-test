
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"server-marshal.h"
#include"handler.h"
#include "misc.h"


adb_ProductCompleteResponse_t* ProductCompleteMarshal(adb_ProductComplete_t* productComplete, const axutil_env_t *env)
{
    adb_ProductCompleteResponse_t *ret = NULL;
    adb_ProductCompleteResponseType_t *type_ret = NULL;

    adb_ProductCompleteType_t *req_type = NULL;
    char *productCategory, *productName;
    axis2_bool_t status;
    char message[256];

    init_localstate();

    req_type = adb_ProductComplete_get_ProductComplete(productComplete, env);
    productCategory = adb_ProductCompleteType_get_productCategory(req_type, env);
    productName = adb_ProductCompleteType_get_productName(req_type, env);
    
    logprintf("the product category is:%s\n", productCategory);
    logprintf("the product name is:%s\n", productName);
    
    type_ret = adb_ProductCompleteResponseType_create(env);
    status = AXIS2_TRUE;
    snprintf(message, 256, "category is:%s, name is :%s", productCategory, productName);
    logprintf("the return message is :%s\n", message);
    adb_ProductCompleteResponseType_set_result(type_ret, env, status);
    adb_ProductCompleteResponseType_set_message(type_ret, env, message);
    ret = adb_ProductCompleteResponse_create(env);
    adb_ProductCompleteResponse_set_ProductCompleteResponse(ret, env, type_ret);

    return ret;
}
