
    /**
     * @file NRE_FixEffect.hpp
     * @brief Declaration of Micro's API's Object : FixEffect
     * @author Louis ABEL
     * @date 18/08/2019
     * @copyright CC-BY-NC-SA
     */

     #pragma once

     #include "../../Controller/NRE_LedController.hpp"

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
             * @class FixEffect
             * @brief Represent a fix light effect, setting all leds to the same color with no movement
             */
            class FixEffect : public Effect {
                public :    // Methods
                    //## Constructor ##//
                        /**
                         * Default constructor
                         */
                        FixEffect() = default;

                    //## Methods ##//
                        /**
                         * Called when the effect is set to a controller
                         * @param controller the master controller
                         */
                        void start(LedController& controller) override {
                        }
                        /**
                         * Called at each loop iteration
                         * @param controller the master controller
                         * @param delta      the delta time from last frame
                         */
                        void run(LedController& controller, long delta) override {
                            controller.sleep(1000);
                            controller.setColor(controller.getColor(0));
                        }
                        /**
                         * Called when the effect is replaced by another one in a controller
                         * @param controller the master controller
                         */
                        void stop(LedController& controller) override {
                        }
            };

        }
    }
