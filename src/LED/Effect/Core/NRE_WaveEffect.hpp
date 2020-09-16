
    /**
     * @file NRE_WaveEffect.hpp
     * @brief Declaration of Micro's API's Object : WaveEffect
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
             * @class WaveEffect
             * @brief Represent a wave light effect, setting all leds to the same color, starting from black to the given color and then back to black
             */
            class WaveEffect : public Effect {
                private :   // Fields
                    float current;                      /**< The current step */
                    bool down;                          /**< Tell if the effect is going down or up in intensity */

                public :    // Methods
                    //## Constructor ##//
                        /**
                         * Construct the effect
                         */
                        constexpr WaveEffect() : current(0), down(false) {
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
