

        /**
         * adb_ProductCompleteResponseType.c
         *
         * This file was auto-generated from WSDL
         * by the Apache Axis2/C version: SNAPSHOT  Built on : Mar 10, 2008 (08:35:52 GMT+00:00)
         */

        #include "adb_ProductCompleteResponseType.h"
        
                /*
                 * This type was generated from the piece of schema that had
                 * name = ProductCompleteResponseType
                 * Namespace URI = http://server.ips.com
                 * Namespace Prefix = ns1
                 */
           


        struct adb_ProductCompleteResponseType
        {
            axis2_bool_t property_result;

                
                axis2_bool_t is_valid_result;


            axis2_char_t* property_message;

                
                axis2_bool_t is_valid_message;


            
        };


       /************************* Private Function prototypes ********************************/
        

                axis2_status_t AXIS2_CALL
                adb_ProductCompleteResponseType_set_result_nil(
                        adb_ProductCompleteResponseType_t* _ProductCompleteResponseType,
                        const axutil_env_t *env);
            


       /************************* Function Implmentations ********************************/
        adb_ProductCompleteResponseType_t* AXIS2_CALL
        adb_ProductCompleteResponseType_create(
            const axutil_env_t *env)
        {
            adb_ProductCompleteResponseType_t *_ProductCompleteResponseType = NULL;
            
            AXIS2_ENV_CHECK(env, NULL);

            _ProductCompleteResponseType = (adb_ProductCompleteResponseType_t *) AXIS2_MALLOC(env->
                allocator, sizeof(adb_ProductCompleteResponseType_t));

            if(NULL == _ProductCompleteResponseType)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                return NULL;
            }

            memset(_ProductCompleteResponseType, 0, sizeof(adb_ProductCompleteResponseType_t));

            _ProductCompleteResponseType->is_valid_result  = AXIS2_FALSE;
            _ProductCompleteResponseType->property_message  = NULL;
                  _ProductCompleteResponseType->is_valid_message  = AXIS2_FALSE;
            

            return _ProductCompleteResponseType;
        }

        axis2_status_t AXIS2_CALL
        adb_ProductCompleteResponseType_free (
                adb_ProductCompleteResponseType_t* _ProductCompleteResponseType,
                const axutil_env_t *env)
        {
            

            AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
            AXIS2_PARAM_CHECK(env->error, _ProductCompleteResponseType, AXIS2_FAILURE);

            adb_ProductCompleteResponseType_reset_result(_ProductCompleteResponseType, env);
            adb_ProductCompleteResponseType_reset_message(_ProductCompleteResponseType, env);
            

            if(_ProductCompleteResponseType)
            {
                AXIS2_FREE(env->allocator, _ProductCompleteResponseType);
                _ProductCompleteResponseType = NULL;
            }
            return AXIS2_SUCCESS;
        }


        

        axis2_status_t AXIS2_CALL
        adb_ProductCompleteResponseType_deserialize(
                adb_ProductCompleteResponseType_t* _ProductCompleteResponseType,
                const axutil_env_t *env,
                axiom_node_t **dp_parent,
                axis2_bool_t *dp_is_early_node_valid,
                axis2_bool_t dont_care_minoccurs)
        {
          axiom_node_t *parent = *dp_parent;
          
          axis2_status_t status = AXIS2_SUCCESS;
           
             axis2_char_t* text_value = NULL;
             axutil_qname_t *qname = NULL;
          
            axutil_qname_t *element_qname = NULL; 
            
               axiom_node_t *first_node = NULL;
               axis2_bool_t is_early_node_valid = AXIS2_TRUE;
               axiom_node_t *current_node = NULL;
               axiom_element_t *current_element = NULL;
            
            AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
            AXIS2_PARAM_CHECK(env->error, _ProductCompleteResponseType, AXIS2_FAILURE);

            
              
              while(parent && axiom_node_get_node_type(parent, env) != AXIOM_ELEMENT)
              {
                  parent = axiom_node_get_next_sibling(parent, env);
              }
              if (NULL == parent)
              {
                /* This should be checked before everything */
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                            "Failed in building adb object for ProductCompleteResponseType : "
                            "NULL elemenet can not be passed to deserialize");
                return AXIS2_FAILURE;
              }
              
                      
                      first_node = axiom_node_get_first_child(parent, env);
                      
                    

                     
                     /*
                      * building result element
                      */
                     
                     
                     
                                   current_node = first_node;
                                   is_early_node_valid = AXIS2_FALSE;
                                   
                                   
                                    while(current_node && axiom_node_get_node_type(current_node, env) != AXIOM_ELEMENT)
                                    {
                                        current_node = axiom_node_get_next_sibling(current_node, env);
                                    }
                                    if(current_node != NULL)
                                    {
                                        current_element = (axiom_element_t *)axiom_node_get_data_element(current_node, env);
                                        qname = axiom_element_get_qname(current_element, env, current_node);
                                    }
                                   
                                 element_qname = axutil_qname_create(env, "result", "http://server.ips.com", NULL);
                                 

                           if ( 
                                (current_node   && current_element && (axutil_qname_equals(element_qname, env, qname))))
                           {
                              if( current_node   && current_element && (axutil_qname_equals(element_qname, env, qname)))
                              {
                                is_early_node_valid = AXIS2_TRUE;
                              }
                              
                                 
                                      text_value = axiom_element_get_text(current_element, env, current_node);
                                      if(text_value != NULL)
                                      {
                                            if (!axutil_strcasecmp(text_value , "true"))
                                            {
                                                status = adb_ProductCompleteResponseType_set_result(_ProductCompleteResponseType, env,
                                                                 AXIS2_TRUE);
                                            }
                                            else
                                            {
                                                status = adb_ProductCompleteResponseType_set_result(_ProductCompleteResponseType, env,
                                                                      AXIS2_FALSE);
                                            }
                                      }
                                      
                                      else
                                      {
                                          AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "NULL value is set to a non nillable element result");
                                          status = AXIS2_FAILURE;
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for result ");
                                     if(element_qname)
                                     {
                                         axutil_qname_free(element_qname, env);
                                     }
                                     return AXIS2_FAILURE;
                                 }
                              }
                           
                  if(element_qname)
                  {
                     axutil_qname_free(element_qname, env);
                     element_qname = NULL;
                  }
                 

                     
                     /*
                      * building message element
                      */
                     
                     
                     
                                    /*
                                     * because elements are ordered this works fine
                                     */
                                  
                                   
                                   if(current_node != NULL && is_early_node_valid)
                                   {
                                       current_node = axiom_node_get_next_sibling(current_node, env);
                                       
                                       
                                        while(current_node && axiom_node_get_node_type(current_node, env) != AXIOM_ELEMENT)
                                        {
                                            current_node = axiom_node_get_next_sibling(current_node, env);
                                        }
                                        if(current_node != NULL)
                                        {
                                            current_element = (axiom_element_t *)axiom_node_get_data_element(current_node, env);
                                            qname = axiom_element_get_qname(current_element, env, current_node);
                                        }
                                       
                                   }
                                   is_early_node_valid = AXIS2_FALSE;
                                 
                                 element_qname = axutil_qname_create(env, "message", "http://server.ips.com", NULL);
                                 

                           if ( 
                                (current_node   && current_element && (axutil_qname_equals(element_qname, env, qname))))
                           {
                              if( current_node   && current_element && (axutil_qname_equals(element_qname, env, qname)))
                              {
                                is_early_node_valid = AXIS2_TRUE;
                              }
                              
                                 
                                      text_value = axiom_element_get_text(current_element, env, current_node);
                                      if(text_value != NULL)
                                      {
                                            status = adb_ProductCompleteResponseType_set_message(_ProductCompleteResponseType, env,
                                                               text_value);
                                      }
                                      
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for message ");
                                     if(element_qname)
                                     {
                                         axutil_qname_free(element_qname, env);
                                     }
                                     return AXIS2_FAILURE;
                                 }
                              }
                           
                  if(element_qname)
                  {
                     axutil_qname_free(element_qname, env);
                     element_qname = NULL;
                  }
                 
          return status;
       }

          axis2_bool_t AXIS2_CALL
          adb_ProductCompleteResponseType_is_particle()
          {
            
                 return AXIS2_FALSE;
              
          }


          void AXIS2_CALL
          adb_ProductCompleteResponseType_declare_parent_namespaces(
                    adb_ProductCompleteResponseType_t* _ProductCompleteResponseType,
                    const axutil_env_t *env, axiom_element_t *parent_element,
                    axutil_hash_t *namespaces, int *next_ns_index)
          {
            
                  /* Here this is an empty function, Nothing to declare */
                 
          }

        
        
        axiom_node_t* AXIS2_CALL
        adb_ProductCompleteResponseType_serialize(
                adb_ProductCompleteResponseType_t* _ProductCompleteResponseType,
                const axutil_env_t *env, axiom_node_t *parent, axiom_element_t *parent_element, int parent_tag_closed, axutil_hash_t *namespaces, int *next_ns_index)
        {
            
            
             axis2_char_t *string_to_stream;
            
         
         axiom_node_t *current_node = NULL;
         int tag_closed = 0;

         
         
                axiom_namespace_t *ns1 = NULL;

                axis2_char_t *qname_uri = NULL;
                axis2_char_t *qname_prefix = NULL;
                axis2_char_t *p_prefix = NULL;
                axis2_bool_t ns_already_defined;
            
                    axis2_char_t text_value_1[64];
                    
                    axis2_char_t *text_value_2;
                    axis2_char_t *text_value_2_temp;
                    
               axis2_char_t *start_input_str = NULL;
               axis2_char_t *end_input_str = NULL;
               unsigned int start_input_str_len = 0;
               unsigned int end_input_str_len = 0;
            
            
               axiom_data_source_t *data_source = NULL;
               axutil_stream_t *stream = NULL;

            

            AXIS2_ENV_CHECK(env, NULL);
            AXIS2_PARAM_CHECK(env->error, _ProductCompleteResponseType, NULL);
            
            
                    current_node = parent;
                    data_source = (axiom_data_source_t *)axiom_node_get_data_element(current_node, env);
                    if (!data_source)
                        return NULL;
                    stream = axiom_data_source_get_stream(data_source, env); /* assume parent is of type data source */
                    if (!stream)
                        return NULL;
                  
            if(!parent_tag_closed)
            {
            
              string_to_stream = ">"; 
              axutil_stream_write(stream, env, string_to_stream, axutil_strlen(string_to_stream));
              tag_closed = 1;
            
            }
            
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://server.ips.com", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://server.ips.com", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://server.ips.com",
                                            p_prefix));
                       }
                      

                   if (!_ProductCompleteResponseType->is_valid_result)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("result"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("result")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing result element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sresult>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sresult>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           strcpy(text_value_1, (_ProductCompleteResponseType->property_result)?"true":"false");
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                           axutil_stream_write(stream, env, text_value_1, axutil_strlen(text_value_1));
                           
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                           
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://server.ips.com", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://server.ips.com", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://server.ips.com",
                                            p_prefix));
                       }
                      

                   if (!_ProductCompleteResponseType->is_valid_message)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("message"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("message")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing message element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%smessage>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%smessage>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                    
                           text_value_2 = _ProductCompleteResponseType->property_message;
                           
                           axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                           
                            
                           text_value_2_temp = axutil_xml_quote_string(env, text_value_2, AXIS2_TRUE);
                           if (text_value_2_temp)
                           {
                               axutil_stream_write(stream, env, text_value_2_temp, axutil_strlen(text_value_2_temp));
                               AXIS2_FREE(env->allocator, text_value_2_temp);
                           }
                           else
                           {
                               axutil_stream_write(stream, env, text_value_2, axutil_strlen(text_value_2));
                           }
                           
                           axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                           
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 

            return parent;
        }


        

            /**
             * getter for result.
             */
            axis2_bool_t AXIS2_CALL
            adb_ProductCompleteResponseType_get_result(
                    adb_ProductCompleteResponseType_t* _ProductCompleteResponseType,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, (axis2_bool_t)0);
                    AXIS2_PARAM_CHECK(env->error, _ProductCompleteResponseType, (axis2_bool_t)0);
                  

                return _ProductCompleteResponseType->property_result;
             }

            /**
             * setter for result
             */
            axis2_status_t AXIS2_CALL
            adb_ProductCompleteResponseType_set_result(
                    adb_ProductCompleteResponseType_t* _ProductCompleteResponseType,
                    const axutil_env_t *env,
                    axis2_bool_t  arg_result)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ProductCompleteResponseType, AXIS2_FAILURE);
                
                if(_ProductCompleteResponseType->is_valid_result &&
                        arg_result == _ProductCompleteResponseType->property_result)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_ProductCompleteResponseType_reset_result(_ProductCompleteResponseType, env);

                _ProductCompleteResponseType->property_result = arg_result;
                        _ProductCompleteResponseType->is_valid_result = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for result
            */
           axis2_status_t AXIS2_CALL
           adb_ProductCompleteResponseType_reset_result(
                   adb_ProductCompleteResponseType_t* _ProductCompleteResponseType,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _ProductCompleteResponseType, AXIS2_FAILURE);
               

               _ProductCompleteResponseType->is_valid_result = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether result is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_ProductCompleteResponseType_is_result_nil(
                   adb_ProductCompleteResponseType_t* _ProductCompleteResponseType,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _ProductCompleteResponseType, AXIS2_TRUE);
               
               return !_ProductCompleteResponseType->is_valid_result;
           }

           /**
            * Set result to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_ProductCompleteResponseType_set_result_nil(
                   adb_ProductCompleteResponseType_t* _ProductCompleteResponseType,
                   const axutil_env_t *env)
           {
               return adb_ProductCompleteResponseType_reset_result(_ProductCompleteResponseType, env);
           }

           

            /**
             * getter for message.
             */
            axis2_char_t* AXIS2_CALL
            adb_ProductCompleteResponseType_get_message(
                    adb_ProductCompleteResponseType_t* _ProductCompleteResponseType,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _ProductCompleteResponseType, NULL);
                  

                return _ProductCompleteResponseType->property_message;
             }

            /**
             * setter for message
             */
            axis2_status_t AXIS2_CALL
            adb_ProductCompleteResponseType_set_message(
                    adb_ProductCompleteResponseType_t* _ProductCompleteResponseType,
                    const axutil_env_t *env,
                    const axis2_char_t*  arg_message)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ProductCompleteResponseType, AXIS2_FAILURE);
                
                if(_ProductCompleteResponseType->is_valid_message &&
                        arg_message == _ProductCompleteResponseType->property_message)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_ProductCompleteResponseType_reset_message(_ProductCompleteResponseType, env);

                
                if(NULL == arg_message)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _ProductCompleteResponseType->property_message = (axis2_char_t *)axutil_strdup(env, arg_message);
                        if(NULL == _ProductCompleteResponseType->property_message)
                        {
                            AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "Error allocating memeory for message");
                            return AXIS2_FAILURE;
                        }
                        _ProductCompleteResponseType->is_valid_message = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for message
            */
           axis2_status_t AXIS2_CALL
           adb_ProductCompleteResponseType_reset_message(
                   adb_ProductCompleteResponseType_t* _ProductCompleteResponseType,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _ProductCompleteResponseType, AXIS2_FAILURE);
               

               
            
                
                if(_ProductCompleteResponseType->property_message != NULL)
                {
                   
                   
                        AXIS2_FREE(env-> allocator, _ProductCompleteResponseType->property_message);
                     _ProductCompleteResponseType->property_message = NULL;
                }
            
                
                
                _ProductCompleteResponseType->is_valid_message = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether message is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_ProductCompleteResponseType_is_message_nil(
                   adb_ProductCompleteResponseType_t* _ProductCompleteResponseType,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _ProductCompleteResponseType, AXIS2_TRUE);
               
               return !_ProductCompleteResponseType->is_valid_message;
           }

           /**
            * Set message to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_ProductCompleteResponseType_set_message_nil(
                   adb_ProductCompleteResponseType_t* _ProductCompleteResponseType,
                   const axutil_env_t *env)
           {
               return adb_ProductCompleteResponseType_reset_message(_ProductCompleteResponseType, env);
           }

           

