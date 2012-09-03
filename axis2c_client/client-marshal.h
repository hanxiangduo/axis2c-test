#include"axis2_stub_DmsServer.h"

typedef struct dmsStub_t {
  axutil_env_t * env;
  axis2_char_t * client_home;
  axis2_char_t * endpoint_uri;
  axis2_char_t * node_name;
  axis2_stub_t * stub;
} dmsStub;

dmsStub * dmsStubCreate  (char *endpoint, char *logfile, char *homedir);
int      dmsStubDestroy (dmsStub * stub);

int dmsProductCompleteStub(dmsStub *st, char *productCategory, char *productName);
