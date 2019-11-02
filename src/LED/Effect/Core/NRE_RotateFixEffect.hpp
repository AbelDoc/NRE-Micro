
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
                    ObservedData<Color>& color;         /**< The effect color */
                    ObservedData<unsigned int>& speed;  /**< The effect speed */
                    LedId current;                      /**< The current step */
                    unsigned long lastTime;             /**< The last step time */
                    bool clockwise;                     /**< Tell if the effect is going clockwise or not */
                    bool negateOrFill;                  /**< Tell if the effect turn all leds off when a cycle is complete, or turn them off one by one in the next cycle */
                    bool cycleComplete;                 /**< Tell that we have finish a cycle */

                public :    // Methods
                    //## Constructor ##//
                        /**
                         * No default constructor
                         */
                        RotateFixEffect() = delete;
                        /**
                         * Construct the effect from the fix color
                         * @param c                  the effect color
                         * @param s                  the effect speed
                         * @param clockwiseEffect    tell if the effect is rotating clockwise or not
                         * @param negateOrFillEffect tell if the effect turn all leds off when a cycle is complete or if each led is turn off in the next cycle
                         */
                        RotateFixEffect(ObservedData<Color>& c, ObservedData<unsigned int>& s, bool clockwiseEffect = true, bool negateOrFillEffect = false) : color(c), speed(s), current(0), lastTime(millis()), clockwise(clockwiseEffect), negateOrFill(negateOrFillEffect), cycleComplete(false) {
                            if (clockwise) {
                                cycleComplete = true;
                            }
                        }

                    //## Methods ##//
                        /**
                         * Called when the effect is set to a controller
                         */
                        void start(LedController& controller) override {
                            controller.setColor(BLACK);
                        }
                        /**
                         * Called at each loop iteration
                         */
                        void run(LedController& controller) override {
                            unsigned long time = millis();
                            if (time - lastTime <= speed.get()) {
                                delay(speed.get() - (time - lastTime));
                            }

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

                            lastTime = millis();
                        }
                        /**
                         * Called when the effect is replaced by another one in a controller
                         */
                        void stop(LedController& controller) override {
                            controller.setColor(BLACK);
                        }
            };

        }
    }
