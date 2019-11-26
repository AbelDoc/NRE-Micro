 
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
            
            enum TimeUnit {
                MILLISECONDS,
                SECONDS,
                MINUTES,
                HOURS,
                DAYS,
                MONTHS,
                YEARS,
            };
            
            /**
             * @class Time
             * Manage a simple time
             */
            class Time {
                public :    // Field
                    int milliseconds;   /**< The time milliseconds */
                    int seconds;        /**< The time seconds */
                    int minutes;        /**< The time minutes */
                    int hours;          /**< The time hours */
                    
                public :    // Methods
                    //## Constructor ##//
                        /**
                         * Construct the time
                         */
                        Time();
                        /**
                         * Construct the time from given values
                         * @param h  the time hours
                         * @param m  the time minutes
                         * @param s  the time seconds
                         * @param ms the time milliseconds
                         */
                        Time(int h, int m, int s, int ms);
    
                    //## Methods ##//
                        /**
                         * Add a time amount from a given amount
                         * @param amount the amount to add
                         * @param unit   the time unit to add
                         * @return       hours overflow
                         */
                        int add(long amount, TimeUnit unit);
                        
            private :   // Static
                 static const int UNIT_OVERFLOW[];
            };
            
            const int Time::UNIT_OVERFLOW[] = {
                    1000,
                    60,
                    60,
                    24
            };
            
            /**
             * @class Date
             * Manage a simple date
             */
            class Date {
                public :    // Field
                    int day;            /**< The date day */
                    int month;          /**< The date month */
                    int year;           /**< The date years */
                    Time time;          /**< The date time : hours, minutes, seconds, milliseconds */

                public :    // Methods
                    //## Constructor ##//
                        /**
                         * Construct the date
                         */
                        Date();
                        /**
                         * Construct the date from given values
                         * @param y  the date year
                         * @param mt the date month
                         * @param d  the date day
                         * @param h  the time hours
                         * @param m  the time minutes
                         * @param s  the time seconds
                         * @param ms the time milliseconds
                         */
                        Date(int y, int mt, int d, int h, int m, int s, int ms);
        
                    //## Methods ##//
                        /**
                         * Add a time amount from a given amount
                         * @param amount the amount to add
                         * @param unit   the time unit to add
                         */
                        void add(long amount, TimeUnit unit);
                        
                private:    // Methods
                    /**
                     * Compute the current month days overflow
                     */
                    int getDaysOverflow() const;
    
                private :   // Static
                     static const int DAYS_OVERFLOW[];
            };
    
            const int Date::DAYS_OVERFLOW[] = {
                31,
                28,
                31,
                30,
                31,
                30,
                31,
                31,
                30,
                31,
                30,
                31
            };
            
            /**
             * @class TimeManager
             * @brief Manage the time from a user-defined reference, can be synchronize from the Web module
             */
            class TimeManager : public Module<TimeManager> {
                private :   // Fields
                    Date current;
                
                public :    // Methods
                    //## Constructor ##//
                        /**
                         * Construct the time module
                         */
                        TimeManager() = default;
    
                    //## Getter ##//
                        /**
                         * @return the manager info
                         */
                        String getInfo() const;
    
                    //## Setter ##//
                        /**
                         * Set the manager date reference
                         * @param ref the new reference
                         */
                        void setDate(Date const& ref);
    
                    //## Methods ##//
                        /**
                         * Loop through all controller
                         * @param delta the delta time from the last frame
                         */
                        void loop(long delta) override;
            };

            static TimeManager _timeManager;
        }
    }

    #include "NRE_TimeManagerInl.hpp"
