
    /**
     * @file NRE_WaveEffect.hpp
     * @brief Declaration of Micro's API's Object : WaveEffect
     * @author Louis ABEL
     * @date 18/08/2019
     * @copyright CC-BY-NC-SA
     */

     #pragma once

     #include "../Controller/NRE_LedController.hpp"

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
             * @class WaveEffect
             * @brief Represent a wave light effect, setting all leds to the same color, starting from black to the given color and then back to black
             */
            class WaveEffect : public Effect {
                private :   // Fields
                    ObservedData<Color>& color; /**< The effect color */
                    unsigned char speed;        /**< The effect speed */
                    float current;              /**< The current step */
                    unsigned long lastTime;     /**< The last step time */
                    bool down;                  /**< Tell if the effect is going down or up in intensity */

                public :    // Methods
                    //## Constructor ##//
                        /**
                         * No default constructor
                         */
                        WaveEffect() = delete;
                        /**
                         * Construct the effect from the fix color
                         * @param c the effect color
                         * @param s the effect speed
                         */
                        WaveEffect(ObservedData<Color>& c, unsigned char s = 2) : color(c), speed(s), current(0), lastTime(0), down(false) {
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
                            unsigned long time = micros();
                            if (time - lastTime <= 100 * speed) {
                                delay(100 * speed - (time - lastTime));
                            }

                            float r = color.get().getR();
                            float g = color.get().getG();
                            float b = color.get().getB();

                            if (down) {
                                current -= 0.01;
                                if (current < 0) {
                                    current = 0;
                                    down = false;
                                }
                            } else {
                                current += 0.01;
                                if (current > 1) {
                                    current = 1;
                                    down = true;
                                }
                            }

                            r *= current;
                            g *= current;
                            b *= current;

                            controller.setColor(Color(static_cast <ColorChannel> (r), static_cast <ColorChannel> (g), static_cast <ColorChannel> (b)));
                            lastTime = micros();
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
