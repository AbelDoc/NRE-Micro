    
    /**
     * @file NRE_TimeModifier.hpp
     * @brief Declaration of Micro's API's Object : TimeModifier
     * @author Louis ABEL
     * @date 27/11/2019
     * @copyright CC-BY-NC-SA
     */
    
    #pragma once

    #include "../NRE_Modifier.hpp"
    #include "../../../Time/Manager/NRE_TimeManager.hpp"
    
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
             * @class TimeModifier
             * @brief Represent a light color modifier, slowly decresing light intensity when the target time is passed
             */
            class TimeModifier : public Modifier {
                private :   // Fields
                    Date stop;
                    Date start;
                
                public :    // Methods
                    //## Constructor ##//
                        /**
                         * Construct the time modifier from the given time target
                         * @param sto the modifier stop time
                         * @param sta the modifier start time
                         */
                        TimeModifier(Date sto, Date sta) : stop(sto), start(sta) {
                        }
                        
                    //## Methods ##//
                        /**
                         * Apply a modification on a target color
                         * @return the modified color
                         */
                        Color modify(Color color) override {
                            Date const& current = MicroManager::get<TimeManager>().getCurrent();
                            if (current >= stop && current <= start) {
                                return 0;
                            } else {
                                return color;
                            }
                        }
            };
            
        }
    }
