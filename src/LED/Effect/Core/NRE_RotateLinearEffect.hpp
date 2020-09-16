
    /**
     * @file NRE_RotateLinearEffect.hpp
     * @brief Declaration of Micro's API's Object : RotateLinearEffect
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
             * @class RotateLinearEffect
             * @brief Represent a wave light effect, setting all leds to the same color with a linear gradient, starting from black to the given color and then back to black
             */
            class RotateLinearEffect : public Effect {
                private :   // Fields
                    float* currents;                    /**< The current step */
                    bool* downs;                        /**< Tell if the effect is going down or up in intensity */

                public :    // Methods
                    //## Constructor ##//
                        /**
                         * Construct the effect from the fix color
                         */
                        constexpr RotateLinearEffect() : currents(nullptr),  downs(nullptr) {
                        }

                    //## Methods ##//
                        /**
                         * Called when the effect is set to a controller
                         * @param controller the master controller
                         */
                        void start(LedController& controller) override {
                            controller.turnOff();
                            currents = new float[controller.getCount()];
                            downs = new bool[controller.getCount()];

                            currents[0] = 0;
                            downs[0] = false;

                            for (int i = 1; i < controller.getCount(); i++) {
                                currents[i] = currents[i - 1] + 1.0f / controller.getCount();
                                downs[i] = false;
                            }
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

                            for (int i = 0; i < controller.getCount(); i++) {
                                float r = color.get().getR();
                                float g = color.get().getG();
                                float b = color.get().getB();

                                if (downs[i]) {
                                    currents[i] -= 0.01;
                                    if (currents[i] < 0) {
                                        currents[i] = 0;
                                        downs[i] = false;
                                    }
                                } else {
                                    currents[i] += 0.01;
                                    if (currents[i] > 1) {
                                        currents[i] = 1;
                                        downs[i] = true;
                                    }
                                }

                                r *= currents[i];
                                g *= currents[i];
                                b *= currents[i];

                                controller.setColor(i, Color(static_cast <ColorChannel> (r), static_cast <ColorChannel> (g), static_cast <ColorChannel> (b)));
                            }
                        }
                        /**
                         * Called when the effect is replaced by another one in a controller
                         * @param controller the master controller
                         */
                        void stop(LedController& controller) override {
                            controller.turnOff();
                            delete[] currents;
                            delete[] downs;
                        }
            };

        }
    }
