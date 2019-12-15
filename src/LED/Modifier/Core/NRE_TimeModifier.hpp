    
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
                    Date relaunchTimer;
                    bool done;
                
                public :    // Methods
                    //## Constructor ##//
                        /**
                         * Construct the time modifier from the given time target
                         * @param sto      the modifier stop time
                         * @param sta      the modifier start time
                         * @param relaunch the timer relaunch time
                         */
                        TimeModifier(Date sto, Date sta, Date relaunch) : stop(sto), start(sta), relaunchTimer(relaunch), done(false) {
                        }
                        
                    //## Methods ##//
                        void onStart() override {
                        }
                        void onStop() override {
                            MicroManager::get<LedManager>().setActive(true);
                        }
                        void onRun() override {
                            Date const& current = MicroManager::get<TimeManager>().getCurrent();
                            if (!done && current >= stop && current <= start) {
                                MicroManager::get<LedManager>().setActive(false);
                                done = true;
                            } else {
                                if (current > start) {
                                    onStop();
                                    stop += relaunchTimer;
                                    start += relaunchTimer;
                                    done = false;
                                }
                            }
                        }
                        /**
                         * @return if the modifier has done his work
                         */
                        bool isFinished() override {
                            Date const& current = MicroManager::get<TimeManager>().getCurrent();
                            return relaunchTimer == Date(0, 0, 0, 0, 0, 0, 0) && current > start;
                        }
            };
            
        }
    }
