

    /**
     * axis2_skel_DmsServer.c
     *
     * This file was auto-generated from WSDL for "DmsServer|http://webser.com" service
     * by the Apache Axis2/C version: 1.4.1  Built on : Aug 13, 2008 (05:03:35 LKT)
     * axis2_skel_DmsServer Axis2/C skeleton for the axisService
     */

#include "axis2_skel_DmsServer.h"
#include <server-marshal.h>


     

		 
        /**
         * auto generated function definition signature
         * for "ProductComplete|http://webser.com" operation.
         
         *
         * @param productComplete
         *
         * @return adb_ProductCompleteResponse_t** @param productComplete
         */
         adb_ProductCompleteResponse_t* axis2_skel_DmsServer_ProductComplete (const axutil_env_t *env  ,
                                              adb_ProductComplete_t* productComplete )
        { return (ProductCompleteMarshal(productComplete, env)); }
     

