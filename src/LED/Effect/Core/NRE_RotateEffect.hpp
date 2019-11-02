
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
                    ObservedData<Color>& color;         /**< The effect color */
                    ObservedData<unsigned int>& speed;  /**< The effect speed */
                    LedId current;                      /**< The current step */
                    unsigned long lastTime;             /**< The last step time */
                    bool clockwise;                     /**< Tell if the effect is going clockwise or not */

                public :    // Methods
                    //## Constructor ##//
                        /**
                         * No default constructor
                         */
                        RotateEffect() = delete;
                        /**
                         * Construct the effect from the fix color
                         * @param c               the effect color
                         * @param s               the effect speed
                         * @param clockwiseEffect tell if the effect is rotating clockwise or not
                         */
                        RotateEffect(ObservedData<Color>& c, ObservedData<unsigned int>& s, bool clockwiseEffect = true) : color(c), speed(s), current(0), lastTime(millis()), clockwise(clockwiseEffect) {
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
