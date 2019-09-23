
    /**
     * @file NRE_Effect.hpp
     * @brief Declaration of Micro's API's Object : Effect
     * @author Louis ABEL
     * @date 18/08/2019
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

            class LedController;

            /**
             * @class Effect
             * @brief Represent a light effect
             */
            class Effect {
                public :    // Methods
                    //## Methods ##//
                        /**
                         * Called when the effect is set to a controller
                         * @param controller the master controller
                         */
                        virtual void start(LedController& controller) = 0;
                        /**
                         * Called at each loop iteration
                         * @param controller the master controller
                         */
                        virtual void run(LedController& controller) = 0;
                        /**
                         * Called when the effect is replaced by another one in a controller
                         * @param controller the master controller
                         */
                        virtual void stop(LedController& controller) = 0;
            };

        }
    }
