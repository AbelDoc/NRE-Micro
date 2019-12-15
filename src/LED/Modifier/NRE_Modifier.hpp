    
    /**
     * @file NRE_Modifier.hpp
     * @brief Declaration of Micro's API's Object : Modifier
     * @author Louis ABEL
     * @date 27/11/2019
     * @copyright CC-BY-NC-SA
     */
    
    #pragma once
    
    /**
    * @namespace NRE
    * @brief The NearlyRealEngine's global namespace
    */
    namespace NRE {
        
        /**
         * @namespace Micro
         * @brief Micro's API
         */
        namespace Micro {
            
            /**
             * @class Modifier
             * @brief Represent a light color modifier
             */
            class Modifier {
                public :    // Methods
                    //## Methods ##//
                        virtual void onStart() = 0;
                        virtual void onStop() = 0;
                        virtual void onRun() = 0;
                        /**
                         * @return if the modifier has done his work
                         */
                        virtual bool isFinished() = 0;
            };
            
        }
    }
