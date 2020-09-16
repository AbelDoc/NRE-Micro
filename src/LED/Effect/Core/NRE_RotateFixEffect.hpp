
    /**
     * @file NRE_RotateFixEffect.hpp
     * @brief Declaration of Micro's API's Object : RotateFixEffect
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
             * @class RotateFixEffect
             * @brief Represent a rotate light effect, setting leds on one by one, leds remains on while the effect is running
             */
            class RotateFixEffect : public Effect {
                private :   // Fields
                    LedId current;                      /**< The current step */
                    bool clockwise;                     /**< Tell if the effect is going clockwise or not */
                    bool negateOrFill;                  /**< Tell if the effect turn all leds off when a cycle is complete, or turn them off one by one in the next cycle */
                    bool cycleComplete;                 /**< Tell that we have finish a cycle */

                public :    // Methods
                    //## Constructor ##//
                        /**
                         * Construct the effect
                         * @param clockwiseEffect    tell if the effect is rotating clockwise or not
                         * @param negateOrFillEffect tell if the effect turn all leds off when a cycle is complete or if each led is turn off in the next cycle
                         */
                        constexpr RotateFixEffect(bool clockwiseEffect = true, bool negateOrFillEffect = false) : current(0), clockwise(clockwiseEffect), negateOrFill(negateOrFillEffect), cycleComplete(false) {
                            if (clockwise) {
                                cycleComplete = true;
                            }
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
                                    if (!negateOrFill) {
                                        controller.setColor(BLACK);
                                    } else {
                                        cycleComplete = !cycleComplete;
                                    }
                                }
                            } else {
                                ++next;
                                if (next >= controller.getCount()) {
                                    next = 0;
                                    if (!negateOrFill) {
                                        controller.setColor(BLACK);
                                    } else {
                                        cycleComplete = !cycleComplete;
                                    }
                                }
                            }

                            current = static_cast <LedId> (next);

                            if (negateOrFill && cycleComplete) {
                                controller.setColor(current, BLACK);
                            } else {
                                controller.setColor(current, color);
                            }
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
