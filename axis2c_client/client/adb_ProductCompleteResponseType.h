

        #ifndef ADB_PRODUCTCOMPLETERESPONSETYPE_H
        #define ADB_PRODUCTCOMPLETERESPONSETYPE_H

       /**
        * adb_ProductCompleteResponseType.h
        *
        * This file was auto-generated from WSDL
        * by the Apache Axis2/Java version: 1.4.1  Built on : Aug 13, 2008 (05:03:41 LKT)
        */

       /**
        *  adb_ProductCompleteResponseType class
        */
        typedef struct adb_ProductCompleteResponseType adb_ProductCompleteResponseType_t;

        

        #include <stdio.h>
        #include <axiom.h>
        #include <axis2_util.h>
        #include <axiom_soap.h>
        #include <axis2_client.h>

        #ifdef __cplusplus
        extern "C"
        {
        #endif

        #define ADB_DEFAULT_DIGIT_LIMIT 64
        #define ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT 64
        

        /******************************* Create and Free functions *********************************/

        /**
         * Constructor for creating adb_ProductCompleteResponseType_t
         * @param env pointer to environment struct
         * @return newly created adb_ProductCompleteResponseType_t object
         */
        adb_ProductCompleteResponseType_t* AXIS2_CALL
        adb_ProductCompleteResponseType_create(
            const axutil_env_t *env );

        /**
         * Free adb_ProductCompleteResponseType_t object
         * @param  _ProductCompleteResponseType adb_ProductCompleteResponseType_t object to free
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ProductCompleteResponseType_free (
            adb_ProductCompleteResponseType_t* _ProductCompleteResponseType,
            const axutil_env_t *env);



        /********************************** Getters and Setters **************************************/
        
        

        /**
         * Getter for result. 
         * @param  _ProductCompleteResponseType adb_ProductCompleteResponseType_t object
         * @param env pointer to environment struct
         * @return axis2_bool_t
         */
        axis2_bool_t AXIS2_CALL
        adb_ProductCompleteResponseType_get_result(
            adb_ProductCompleteResponseType_t* _ProductCompleteResponseType,
            const axutil_env_t *env);

        /**
         * Setter for result.
         * @param  _ProductCompleteResponseType adb_ProductCompleteResponseType_t object
         * @param env pointer to environment struct
         * @param arg_result axis2_bool_t
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ProductCompleteResponseType_set_result(
            adb_ProductCompleteResponseType_t* _ProductCompleteResponseType,
            const axutil_env_t *env,
            axis2_bool_t  arg_result);

        /**
         * Resetter for result
         * @param  _ProductCompleteResponseType adb_ProductCompleteResponseType_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ProductCompleteResponseType_reset_result(
            adb_ProductCompleteResponseType_t* _ProductCompleteResponseType,
            const axutil_env_t *env);

        
        

        /**
         * Getter for message. 
         * @param  _ProductCompleteResponseType adb_ProductCompleteResponseType_t object
         * @param env pointer to environment struct
         * @return axis2_char_t*
         */
        axis2_char_t* AXIS2_CALL
        adb_ProductCompleteResponseType_get_message(
            adb_ProductCompleteResponseType_t* _ProductCompleteResponseType,
            const axutil_env_t *env);

        /**
         * Setter for message.
         * @param  _ProductCompleteResponseType adb_ProductCompleteResponseType_t object
         * @param env pointer to environment struct
         * @param arg_message axis2_char_t*
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ProductCompleteResponseType_set_message(
            adb_ProductCompleteResponseType_t* _ProductCompleteResponseType,
            const axutil_env_t *env,
            const axis2_char_t*  arg_message);

        /**
         * Resetter for message
         * @param  _ProductCompleteResponseType adb_ProductCompleteResponseType_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ProductCompleteResponseType_reset_message(
            adb_ProductCompleteResponseType_t* _ProductCompleteResponseType,
            const axutil_env_t *env);

        


        /******************************* Checking and Setting NIL values *********************************/
        

        /**
         * NOTE: set_nil is only available for nillable properties
         */

        

        /**
         * Check whether result is nill
         * @param  _ProductCompleteResponseType adb_ProductCompleteResponseType_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_ProductCompleteResponseType_is_result_nil(
                adb_ProductCompleteResponseType_t* _ProductCompleteResponseType,
                const axutil_env_t *env);


        

        /**
         * Check whether message is nill
         * @param  _ProductCompleteResponseType adb_ProductCompleteResponseType_t object
         * @param env pointer to environment struct
         * @return AXIS2_TRUE if the element is nil or AXIS2_FALSE otherwise
         */
        axis2_bool_t AXIS2_CALL
        adb_ProductCompleteResponseType_is_message_nil(
                adb_ProductCompleteResponseType_t* _ProductCompleteResponseType,
                const axutil_env_t *env);


        
        /**
         * Set message to nill (currently the same as reset)
         * @param  _ProductCompleteResponseType adb_ProductCompleteResponseType_t object
         * @param env pointer to environment struct
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ProductCompleteResponseType_set_message_nil(
                adb_ProductCompleteResponseType_t* _ProductCompleteResponseType,
                const axutil_env_t *env);
        

        /**************************** Serialize and Deserialize functions ***************************/
        /*********** These functions are for use only inside the generated code *********************/

        
        /**
         * Deserialize an XML to adb objects
         * @param  _ProductCompleteResponseType adb_ProductCompleteResponseType_t object
         * @param env pointer to environment struct
         * @param dp_parent double pointer to the parent node to deserialize
         * @param dp_is_early_node_valid double pointer to a flag (is_early_node_valid?)
         * @param dont_care_minoccurs Dont set errors on validating minoccurs, 
         *              (Parent will order this in a case of choice)
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axis2_status_t AXIS2_CALL
        adb_ProductCompleteResponseType_deserialize(
            adb_ProductCompleteResponseType_t* _ProductCompleteResponseType,
            const axutil_env_t *env,
            axiom_node_t** dp_parent,
            axis2_bool_t *dp_is_early_node_valid,
            axis2_bool_t dont_care_minoccurs);
                            
            

       /**
         * Declare namespace in the most parent node 
         * @param  _ProductCompleteResponseType adb_ProductCompleteResponseType_t object
         * @param env pointer to environment struct
         * @param parent_element parent element
         * @param namespaces hash of namespace uri to prefix
         * @param next_ns_index pointer to an int which contain the next namespace index
         */
       void AXIS2_CALL
       adb_ProductCompleteResponseType_declare_parent_namespaces(
                    adb_ProductCompleteResponseType_t* _ProductCompleteResponseType,
                    const axutil_env_t *env, axiom_element_t *parent_element,
                    axutil_hash_t *namespaces, int *next_ns_index);

        

        /**
         * Serialize to an XML from the adb objects
         * @param  _ProductCompleteResponseType adb_ProductCompleteResponseType_t object
         * @param env pointer to environment struct
         * @param ProductCompleteResponseType_om_node node to serialize from
         * @param ProductCompleteResponseType_om_element parent element to serialize from
         * @param tag_closed whether the parent tag is closed or not
         * @param namespaces hash of namespace uri to prefix
         * @param next_ns_index an int which contain the next namespace index
         * @return AXIS2_SUCCESS on success, else AXIS2_FAILURE
         */
        axiom_node_t* AXIS2_CALL
        adb_ProductCompleteResponseType_serialize(
            adb_ProductCompleteResponseType_t* _ProductCompleteResponseType,
            const axutil_env_t *env,
            axiom_node_t* ProductCompleteResponseType_om_node, axiom_element_t *ProductCompleteResponseType_om_element, int tag_closed, axutil_hash_t *namespaces, int *next_ns_index);

        /**
         * Check whether the adb_ProductCompleteResponseType is a particle class (E.g. group, inner sequence)
         * @return whether this is a particle class.
         */
        axis2_bool_t AXIS2_CALL
        adb_ProductCompleteResponseType_is_particle();


     #ifdef __cplusplus
     }
     #endif

     #endif /* ADB_PRODUCTCOMPLETERESPONSETYPE_H */
    

