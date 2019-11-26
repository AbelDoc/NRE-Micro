 
    /**
     * @file NRE_TimeManager.hpp
     * @brief Declaration of Micro's API's Object : TimeManager
     * @author Louis ABEL
     * @date 25/11/2019
     * @copyright CC-BY-NC-SA
     */

     #pragma once

        #ifndef NRE_USE_WEB
            #pragma message("Enable the Web module to get real time synchronization")
        #endif

     #include "../../Core/Module/NRE_Module.hpp"

     #include <ESP8266WiFi.h>

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
             * @class Time
             * Manage a simple time
             */
            struct Time {
                int hours;          /**< The time hours */
                int minutes;        /**< The time minutes */
                int seconds;        /**< The time seconds */
                int milliseconds;   /**< The time milliseconds */
            };
            
            /**
             * @class Date
             * Manage a simple date
             */
            struct Date {
                int month;          /**< The date month */
                int day;            /**< The date day */
                Time time;          /**< The date time : hours, minutes, seconds, milliseconds */
            };
            
            /**
             * @class TimeManager
             * @brief Manage the time from a user-defined reference, can be synchronize from the Web module
             */
            class TimeManager : public Module<TimeManager> {
                
                
                public :    // Methods
                    //## Constructor ##//
                        /**
                         * Construct the time module
                         */
                        TimeManager();
                        /**
                         * Setup the module
                         */
                        void setup() override;
            };

            static TimeManager _wiFiManager;
        }
    }

    #include "NRE_TimeManagerInl.hpp"
