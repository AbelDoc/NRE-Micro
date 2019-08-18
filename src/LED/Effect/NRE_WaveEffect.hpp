
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
                    int current;                /**< The current step */

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
                        WaveEffect(ObservedData<Color>& c, unsigned char s = 5) : color(c), speed(s), current(0), down(false) {
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
                            if (down) {
                                current -= speed;
                                if (current < 0) {
                                    current = 0;
                                    down = false;
                                }
                            } else {
                                current += speed;
                                if (current > 255) {
                                    current = 255;
                                    down = true;
                                }
                            }

                            ColorChannel r = Color::extractR(color.get());
                            ColorChannel g = Color::extractG(color.get());
                            ColorChannel b = Color::extractB(color.get());

                            r = r - (255 - current);
                            g = g - (255 - current);
                            b = b - (255 - current);

                            controller.setColor(Color(r, g, b));
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
