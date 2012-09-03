

        /**
         * adb_ProductComplete.c
         *
         * This file was auto-generated from WSDL
         * by the Apache Axis2/C version: SNAPSHOT  Built on : Mar 10, 2008 (08:35:52 GMT+00:00)
         */

        #include "adb_ProductComplete.h"
        
               /*
                * implmentation of the ProductComplete|http://webser.com element
                */
           


        struct adb_ProductComplete
        {
            
                axutil_qname_t* qname;
            adb_ProductCompleteType_t* property_productInfo;

                
                axis2_bool_t is_valid_productInfo;


            
        };


       /************************* Private Function prototypes ********************************/
        


       /************************* Function Implmentations ********************************/
        adb_ProductComplete_t* AXIS2_CALL
        adb_ProductComplete_create(
            const axutil_env_t *env)
        {
            adb_ProductComplete_t *_ProductComplete = NULL;
            
                axutil_qname_t* qname = NULL;
            
            AXIS2_ENV_CHECK(env, NULL);

            _ProductComplete = (adb_ProductComplete_t *) AXIS2_MALLOC(env->
                allocator, sizeof(adb_ProductComplete_t));

            if(NULL == _ProductComplete)
            {
                AXIS2_ERROR_SET(env->error, AXIS2_ERROR_NO_MEMORY, AXIS2_FAILURE);
                return NULL;
            }

            memset(_ProductComplete, 0, sizeof(adb_ProductComplete_t));

            _ProductComplete->property_productInfo  = NULL;
                  _ProductComplete->is_valid_productInfo  = AXIS2_FALSE;
            
                  qname =  axutil_qname_create (env,
                        "ProductComplete",
                        "http://webser.com",
                        NULL);
                _ProductComplete->qname = qname;
            

            return _ProductComplete;
        }

        axis2_status_t AXIS2_CALL
        adb_ProductComplete_free (
                adb_ProductComplete_t* _ProductComplete,
                const axutil_env_t *env)
        {
            

            AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
            AXIS2_PARAM_CHECK(env->error, _ProductComplete, AXIS2_FAILURE);

            adb_ProductComplete_reset_productInfo(_ProductComplete, env);
            
              if(_ProductComplete->qname)
              {
                  axutil_qname_free (_ProductComplete->qname, env);
                  _ProductComplete->qname = NULL;
              }
            

            if(_ProductComplete)
            {
                AXIS2_FREE(env->allocator, _ProductComplete);
                _ProductComplete = NULL;
            }
            return AXIS2_SUCCESS;
        }


        

        axis2_status_t AXIS2_CALL
        adb_ProductComplete_deserialize(
                adb_ProductComplete_t* _ProductComplete,
                const axutil_env_t *env,
                axiom_node_t **dp_parent,
                axis2_bool_t *dp_is_early_node_valid,
                axis2_bool_t dont_care_minoccurs)
        {
          axiom_node_t *parent = *dp_parent;
          
          axis2_status_t status = AXIS2_SUCCESS;
          
              void *element = NULL;
           
             axis2_char_t* text_value = NULL;
             axutil_qname_t *qname = NULL;
          
            axutil_qname_t *element_qname = NULL; 
            
               axiom_node_t *first_node = NULL;
               axis2_bool_t is_early_node_valid = AXIS2_TRUE;
               axiom_node_t *current_node = NULL;
               axiom_element_t *current_element = NULL;
            
            AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
            AXIS2_PARAM_CHECK(env->error, _ProductComplete, AXIS2_FAILURE);

            
              
              while(parent && axiom_node_get_node_type(parent, env) != AXIOM_ELEMENT)
              {
                  parent = axiom_node_get_next_sibling(parent, env);
              }
              if (NULL == parent)
              {
                /* This should be checked before everything */
                AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                            "Failed in building adb object for ProductComplete : "
                            "NULL elemenet can not be passed to deserialize");
                return AXIS2_FAILURE;
              }
              

                    current_element = (axiom_element_t *)axiom_node_get_data_element(parent, env);
                    qname = axiom_element_get_qname(current_element, env, parent);
                    if (axutil_qname_equals(qname, env, _ProductComplete-> qname))
                    {
                        
                          first_node = axiom_node_get_first_child(parent, env);
                          
                    }
                    else
                    {
                        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, 
                              "Failed in building adb object for ProductComplete : "
                              "Expected %s but returned %s",
                              axutil_qname_to_string(_ProductComplete-> qname, env),
                              axutil_qname_to_string(qname, env));
                        
                        return AXIS2_FAILURE;
                    }
                    

                     
                     /*
                      * building productInfo element
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
                                   
                                 element_qname = axutil_qname_create(env, "productInfo", "http://webser.com", NULL);
                                 

                           if (adb_ProductCompleteType_is_particle() ||  
                                (current_node   && current_element && (axutil_qname_equals(element_qname, env, qname))))
                           {
                              if( current_node   && current_element && (axutil_qname_equals(element_qname, env, qname)))
                              {
                                is_early_node_valid = AXIS2_TRUE;
                              }
                              
                                 
                                      element = (void*)adb_ProductCompleteType_create(env);

                                      status =  adb_ProductCompleteType_deserialize((adb_ProductCompleteType_t*)element,
                                                                            env, &current_node, &is_early_node_valid, AXIS2_FALSE);
                                      if(AXIS2_FAILURE == status)
                                      {
                                          AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in building adb object for element productInfo");
                                      }
                                      else
                                      {
                                          status = adb_ProductComplete_set_productInfo(_ProductComplete, env,
                                                                   (adb_ProductCompleteType_t*)element);
                                      }
                                    
                                 if(AXIS2_FAILURE ==  status)
                                 {
                                     AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "failed in setting the value for productInfo ");
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
          adb_ProductComplete_is_particle()
          {
            
                 return AXIS2_FALSE;
              
          }


          void AXIS2_CALL
          adb_ProductComplete_declare_parent_namespaces(
                    adb_ProductComplete_t* _ProductComplete,
                    const axutil_env_t *env, axiom_element_t *parent_element,
                    axutil_hash_t *namespaces, int *next_ns_index)
          {
            
                  /* Here this is an empty function, Nothing to declare */
                 
          }

        
        
        axiom_node_t* AXIS2_CALL
        adb_ProductComplete_serialize(
                adb_ProductComplete_t* _ProductComplete,
                const axutil_env_t *env, axiom_node_t *parent, axiom_element_t *parent_element, int parent_tag_closed, axutil_hash_t *namespaces, int *next_ns_index)
        {
            
            
         
         axiom_node_t *current_node = NULL;
         int tag_closed = 0;

         
         
                axiom_namespace_t *ns1 = NULL;

                axis2_char_t *qname_uri = NULL;
                axis2_char_t *qname_prefix = NULL;
                axis2_char_t *p_prefix = NULL;
                axis2_bool_t ns_already_defined;
            
                    axis2_char_t text_value_1[64];
                    
               axis2_char_t *start_input_str = NULL;
               axis2_char_t *end_input_str = NULL;
               unsigned int start_input_str_len = 0;
               unsigned int end_input_str_len = 0;
            
            
               axiom_data_source_t *data_source = NULL;
               axutil_stream_t *stream = NULL;

             
                int next_ns_index_value = 0;
            

            AXIS2_ENV_CHECK(env, NULL);
            AXIS2_PARAM_CHECK(env->error, _ProductComplete, NULL);
            
             
                    namespaces = axutil_hash_make(env);
                    next_ns_index = &next_ns_index_value;
                     
                           ns1 = axiom_namespace_create (env,
                                             "http://webser.com",
                                             "n"); 
                           axutil_hash_set(namespaces, "http://webser.com", AXIS2_HASH_KEY_STRING, axutil_strdup(env, "n"));
                       
                     
                    parent_element = axiom_element_create (env, NULL, "ProductComplete", ns1 , &parent);
                    
                    
                    axiom_element_set_namespace(parent_element, env, ns1, parent);


            
                    data_source = axiom_data_source_create(env, parent, &current_node);
                    stream = axiom_data_source_get_stream(data_source, env);
                  
                       if(!(p_prefix = (axis2_char_t*)axutil_hash_get(namespaces, "http://webser.com", AXIS2_HASH_KEY_STRING)))
                       {
                           p_prefix = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof (axis2_char_t) * ADB_DEFAULT_NAMESPACE_PREFIX_LIMIT);
                           sprintf(p_prefix, "n%d", (*next_ns_index)++);
                           axutil_hash_set(namespaces, "http://webser.com", AXIS2_HASH_KEY_STRING, p_prefix);
                           
                           axiom_element_declare_namespace_assume_param_ownership(parent_element, env, axiom_namespace_create (env,
                                            "http://webser.com",
                                            p_prefix));
                       }
                      

                   if (!_ProductComplete->is_valid_productInfo)
                   {
                      
                           /* no need to complain for minoccurs=0 element */
                            
                          
                   }
                   else
                   {
                     start_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (4 + axutil_strlen(p_prefix) + 
                                  axutil_strlen("productInfo"))); 
                                 
                                 /* axutil_strlen("<:>") + 1 = 4 */
                     end_input_str = (axis2_char_t*)AXIS2_MALLOC(env->allocator, sizeof(axis2_char_t) *
                                 (5 + axutil_strlen(p_prefix) + axutil_strlen("productInfo")));
                                  /* axutil_strlen("</:>") + 1 = 5 */
                                  
                     

                   
                   
                     
                     /*
                      * parsing productInfo element
                      */

                    
                    
                            sprintf(start_input_str, "<%s%sproductInfo",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":""); 
                            
                        start_input_str_len = axutil_strlen(start_input_str);
                        sprintf(end_input_str, "</%s%sproductInfo>",
                                 p_prefix?p_prefix:"",
                                 (p_prefix && axutil_strcmp(p_prefix, ""))?":":"");
                        end_input_str_len = axutil_strlen(end_input_str);
                     
                            if(!adb_ProductCompleteType_is_particle())
                            {
                                axutil_stream_write(stream, env, start_input_str, start_input_str_len);
                            }
                            
                            adb_ProductCompleteType_serialize(_ProductComplete->property_productInfo, 
                                                                                 env, current_node, parent_element,
                                                                                 adb_ProductCompleteType_is_particle() || AXIS2_FALSE, namespaces, next_ns_index);
                            
                            if(!adb_ProductCompleteType_is_particle())
                            {
                                axutil_stream_write(stream, env, end_input_str, end_input_str_len);
                            }
                            
                     
                     AXIS2_FREE(env->allocator,start_input_str);
                     AXIS2_FREE(env->allocator,end_input_str);
                 } 

                 
                   if(namespaces)
                   {
                       axutil_hash_index_t *hi;
                       void *val;
                       for (hi = axutil_hash_first(namespaces, env); hi; hi = axutil_hash_next(env, hi)) 
                       {
                           axutil_hash_this(hi, NULL, NULL, &val);
                           AXIS2_FREE(env->allocator, val);
                       }
                       axutil_hash_free(namespaces, env);
                   }
                

            return parent;
        }


        

            /**
             * getter for productInfo.
             */
            adb_ProductCompleteType_t* AXIS2_CALL
            adb_ProductComplete_get_productInfo(
                    adb_ProductComplete_t* _ProductComplete,
                    const axutil_env_t *env)
             {
                
                    AXIS2_ENV_CHECK(env, NULL);
                    AXIS2_PARAM_CHECK(env->error, _ProductComplete, NULL);
                  

                return _ProductComplete->property_productInfo;
             }

            /**
             * setter for productInfo
             */
            axis2_status_t AXIS2_CALL
            adb_ProductComplete_set_productInfo(
                    adb_ProductComplete_t* _ProductComplete,
                    const axutil_env_t *env,
                    adb_ProductCompleteType_t*  arg_productInfo)
             {
                

                AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
                AXIS2_PARAM_CHECK(env->error, _ProductComplete, AXIS2_FAILURE);
                
                if(_ProductComplete->is_valid_productInfo &&
                        arg_productInfo == _ProductComplete->property_productInfo)
                {
                    
                    return AXIS2_SUCCESS; 
                }

                adb_ProductComplete_reset_productInfo(_ProductComplete, env);

                
                if(NULL == arg_productInfo)
                {
                    /* We are already done */
                    return AXIS2_SUCCESS;
                }
                _ProductComplete->property_productInfo = arg_productInfo;
                        _ProductComplete->is_valid_productInfo = AXIS2_TRUE;
                    
                return AXIS2_SUCCESS;
             }

             

           /**
            * resetter for productInfo
            */
           axis2_status_t AXIS2_CALL
           adb_ProductComplete_reset_productInfo(
                   adb_ProductComplete_t* _ProductComplete,
                   const axutil_env_t *env)
           {
               int i = 0;
               int count = 0;
               void *element = NULL;

               AXIS2_ENV_CHECK(env, AXIS2_FAILURE);
               AXIS2_PARAM_CHECK(env->error, _ProductComplete, AXIS2_FAILURE);
               

               
            
                
                if(_ProductComplete->property_productInfo != NULL)
                {
                   
                   
                        adb_ProductCompleteType_free(_ProductComplete->property_productInfo, env);
                     _ProductComplete->property_productInfo = NULL;
                }
            
                
                
                _ProductComplete->is_valid_productInfo = AXIS2_FALSE; 
               return AXIS2_SUCCESS;
           }

           /**
            * Check whether productInfo is nill
            */
           axis2_bool_t AXIS2_CALL
           adb_ProductComplete_is_productInfo_nil(
                   adb_ProductComplete_t* _ProductComplete,
                   const axutil_env_t *env)
           {
               AXIS2_ENV_CHECK(env, AXIS2_TRUE);
               AXIS2_PARAM_CHECK(env->error, _ProductComplete, AXIS2_TRUE);
               
               return !_ProductComplete->is_valid_productInfo;
           }

           /**
            * Set productInfo to nill (currently the same as reset)
            */
           axis2_status_t AXIS2_CALL
           adb_ProductComplete_set_productInfo_nil(
                   adb_ProductComplete_t* _ProductComplete,
                   const axutil_env_t *env)
           {
               return adb_ProductComplete_reset_productInfo(_ProductComplete, env);
           }

           

