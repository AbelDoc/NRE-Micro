
    /**
     * @file NRE_RotateEffect.hpp
     * @brief Declaration of Micro's API's Object : RotateEffect
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
             * @class RotateEffect
             * @brief Represent a rotate light effect, setting leds on one by one, only one led remain on at the same time
             */
            class RotateEffect : public Effect {
                private :   // Fields
                    LedId current;                      /**< The current step */
                    bool clockwise;                     /**< Tell if the effect is going clockwise or not */

                public :    // Methods
                    //## Constructor ##//
                        /**
                         * Construct the effect
                         * @param clockwiseEffect tell if the effect is rotating clockwise or not
                         */
                        RotateEffect(bool clockwiseEffect = true) : current(0), clockwise(clockwiseEffect) {
                        }

                    //## Methods ##//
                        /**
                         * Called when the effect is set to a controller
                         * @param controller the master controller
                         */
                        void start(LedController& controller) override {
                            controller.turnOff();
                        }
                        /**
                         * Called at each loop iteration
                         * @param controller the master controller
                         * @param delta      the delta time from last frame
                         */
                        void run(LedController& controller, long delta) override {
                            ObservedData<long>& speed = controller.getSpeed();
                            if (delta <= speed.get()) {
                                controller.sleep(speed.get() - delta);
                            }
                            ObservedData<Color>& color = controller.getColor(0);
    
                            int next = static_cast <int> (current);

                            if (clockwise) {
                                --next;
                                if (next < 0) {
                                    next = controller.getCount() - 1;
                                }
                            } else {
                                ++next;
                                if (next >= controller.getCount()) {
                                    next = 0;
                                }
                            }

                            controller.setColor(current, BLACK);
                            current = static_cast <LedId> (next);

                            controller.setColor(current, color);
                        }
                        /**
                         * Called when the effect is replaced by another one in a controller
                         * @param controller the master controller
                         */
                        void stop(LedController& controller) override {
                            controller.turnOff();
                        }
            };

        }
    }
