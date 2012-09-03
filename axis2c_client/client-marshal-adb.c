#include<stdlib.h>
#include<stdio.h>

#include "axis2_stub_DmsServer.h"
#include "client-marshal.h"

dmsStub * dmsStubCreate (char *endpoint_uri, char *logfile, char *homedir)
{
    axutil_env_t * env = NULL;
    axis2_char_t * client_home;
    axis2_stub_t * stub;
    dmsStub * st = NULL;

    if ( logfile ) {
      env =  axutil_env_create_all (logfile, AXIS2_LOG_LEVEL_TRACE);
    } else {
      env =  axutil_env_create_all (NULL, 0);
    }
    if ( homedir ) {
        client_home = (axis2_char_t *)homedir;
    } else {
        client_home = AXIS2_GETENV("AXIS2C_HOME");
    }

    if (client_home == NULL) {
        printf ("ERROR: cannot get AXIS2C_HOME");
        return NULL;
    }
    if (endpoint_uri == NULL) {
        printf ("ERROR: empty endpoint_url");
        return NULL;
    }
    char * uri = endpoint_uri;

    // extract node name from the endpoint
    char * p = strstr (uri, "://"); // find "http[s]://..."
    if (p==NULL) {
      printf ("dmsStubCreate received invalid URI %s\n", uri);
      return NULL;
    }
    char * node_name = strdup (p+3); // copy without the protocol prefix
    if (node_name==NULL) {
      printf ("dmsStubCreate is out of memory\n");
      return NULL;
    }
    if ((p = strchr (node_name, ':')) != NULL) *p = '\0'; // cut off the port
    if ((p = strchr (node_name, '/')) != NULL) *p = '\0'; // if there is no port

    printf ("DEBUG: requested URI %s\n", uri);

/*
    // see if we should redirect to the VMware broker
    if (strstr (uri, "VMwareBroker")) {
      uri = "http://localhost:8773/services/VMwareBroker";
      printf (EUCADEBUG, "DEBUG: redirecting request to %s\n", uri);
    }
*/
    // TODO: what if endpoint_uri, home, or env are NULL?
    stub = axis2_stub_create_DmsServer(env, client_home, (axis2_char_t *)uri);

    if (stub && (st = malloc (sizeof(dmsStub)))) {
        st->env=env;
        st->client_home=strdup((char *)client_home);
        st->endpoint_uri=(axis2_char_t *)strdup(endpoint_uri);
        st->node_name=(axis2_char_t *)strdup(node_name);
        st->stub=stub;
        if (st->client_home == NULL || st->endpoint_uri == NULL) {
            printf ("WARNING: out of memory");
        }
    } else {
        printf ("WARNING: out of memory");
    }

    free (node_name);
    return st;
}


int dmsStubDestroy (dmsStub * st)
{
    if (st->client_home) free(st->client_home);
    if (st->endpoint_uri) free(st->endpoint_uri);
    if (st->node_name) free(st->node_name);
    free (st);
    return 0;
}

int dmsProductCompleteStub(dmsStub *st, char *productCategory, char *productName)
{
	axutil_env_t * env = st->env;
	axis2_stub_t * stub = st->stub;
	adb_ProductComplete_t *input = adb_ProductComplete_create(env);
	adb_ProductCompleteType_t *request = adb_ProductCompleteType_create(env);
	adb_ProductCompleteType_set_productCategory(request, env, productCategory);
	adb_ProductCompleteType_set_productName(request, env, productName);
	adb_ProductComplete_set_ProductComplete(input, env, request);
	// start the web service call
	int status = 0;
	{
		adb_ProductCompleteResponse_t *output = axis2_stub_op_DmsServer_ProductComplete(stub, env, input);
		if(!output) {
			printf("ERROR: get productcomplete error\n");
			status = -1;
		} else {
			adb_ProductCompleteResponseType_t *response = adb_ProductCompleteResponse_get_ProductCompleteResponse(output, env);
            axis2_bool_t result = adb_ProductCompleteResponseType_get_result(response, env);
            axis2_char_t *message = adb_ProductCompleteResponseType_get_message(response, env);
            if(result ==  AXIS2_TRUE){
                printf("call the server success\n");
                printf("the return message is %s\n", message);
            } else {
                printf("call the server failed\n");
                printf("the error message is %s\n", message);
                status = -1;
            }
			// check the return message hereXIS2_TRUE
		}
	}
    return status;
}
