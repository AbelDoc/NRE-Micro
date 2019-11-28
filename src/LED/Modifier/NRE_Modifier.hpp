    
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
                        /**
                         * Apply a modification on a target color
                         * @return the modified color
                         */
                        virtual Color modify(Color color) = 0;
                        /**
                         * @return if the modifier has done his work
                         */
                        virtual bool isFinished() = 0;
            };
            
        }
    }
