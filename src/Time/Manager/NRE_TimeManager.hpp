 
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

        #ifndef NRE_USE_ROM
            #pragma message("Enable the ROM module to enable desynchronization limitation by saving current date")
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
            
            enum TimeUnit : int {
                INVALID = -1,
                MILLISECONDS,
                SECONDS,
                MINUTES,
                HOURS,
                DAYS,
                MONTHS,
                YEARS,
            };
            
            /**
             * @class Date
             * Manage a simple date
             */
            class Date {
                public :    // Field
                    int milliseconds;   /**< The time milliseconds */
                    int seconds;        /**< The time seconds */
                    int minutes;        /**< The time minutes */
                    int hours;          /**< The time hours */
                    int day;            /**< The date day */
                    int month;          /**< The date month */
                    int year;           /**< The date years */

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
    
                    //## Comparison Operator ##//
                        /**
                         * Equality test between this and d
                         * @param d the other date to compare with this
                         * @return  the test's result
                         */
                        bool operator==(Date const& d) const;
                        /**
                         * Inequality test between this and d
                         * @param d the other date to compare with this
                         * @return  the test's result
                         */
                        bool operator!=(Date const& d) const;
                        /**
                         * Superiority test between this and d
                         * @param d the other date to compare with this
                         * @return  the test's result
                         */
                        bool operator>(Date const& d) const;
                        /**
                         * Inferiority test between this and d
                         * @param d the other date to compare with this
                         * @return  the test's result
                         */
                        bool operator<(Date const& d) const;
                        /**
                         * Superior or Equal test between this and d
                         * @param d the other date to compare with this
                         * @return  the test's result
                         */
                        bool operator>=(Date const& d) const;
                        /**
                         * Inferior or Equal test between this and d
                         * @param d the other date to compare with this
                         * @return  the test's result
                         */
                        bool operator<=(Date const& d) const;
                        
                private:    // Methods
                    /**
                     * Compute the current month days overflow
                     */
                    int getDaysOverflow() const;
    
                private :   // Static
                    static const int DAYS_OVERFLOW[];
                    static const int UNIT_OVERFLOW[];
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
    
            const int Date::UNIT_OVERFLOW[] = {
                    1000,
                    60,
                    60,
                    24
            };
            
            /**
             * @class TimeManager
             * @brief Manage the time from a user-defined reference, can be synchronize from the Web module
             */
            class TimeManager : public Module<TimeManager> {
                private :   // Fields
                    ObservedData<Date> current; /**< The time manager clock */
                
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
                        /**
                         * @return the manager clock
                         */
                        Date getCurrent() const;
    
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
                        #ifdef NRE_USE_ROM
                            /**
                             * Add manager data into rom
                             */
                            void addData() override;
                        #endif
            };

            static TimeManager _timeManager;
        }
    }

    #include "NRE_TimeManagerInl.hpp"
