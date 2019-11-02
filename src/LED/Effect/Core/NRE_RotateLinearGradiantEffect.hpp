
    /**
     * @file NRE_RotateLinearGradiantEffect.hpp
     * @brief Declaration of Micro's API's Object : RotateLinearGradiantEffect
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
             * @class RotateLinearGradiantEffect
             * @brief Represent a linear gradiant, with a rotating wave effect
             */
            class RotateLinearGradiantEffect : public Effect {
                private :   // Fields
                    ObservedData<Color>& startColor;    /**< The start color */
                    ObservedData<Color>& endColor;      /**< The end color */
                    ObservedData<unsigned int>& speed;  /**< The effect speed */
                    float* currents;                    /**< The current step */
                    bool* downs;                        /**< Tell if the effect is going down or up in intensity */
                    unsigned long lastTime;             /**< The last step time */

                public :    // Methods
                    //## Constructor ##//
                        /**
                         * No default constructor
                         */
                        RotateLinearGradiantEffect() = delete;
                        /**
                         * Construct the effect from the fix color
                         * @param c the effect color
                         * @param s the effect speed
                         */
                        RotateLinearGradiantEffect(ObservedData<Color>& startC, ObservedData<Color>& endC, ObservedData<unsigned int>& s) : startColor(startC), endColor(endC), speed(s), currents(nullptr),  downs(nullptr), lastTime(millis()) {
                        }

                    //## Methods ##//
                        /**
                         * Called when the effect is set to a controller
                         */
                        void start(LedController& controller) override {
                            controller.setColor(BLACK);
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
                         */
                        void run(LedController& controller) override {
                            unsigned long time = millis();
                            if (time - lastTime <= speed.get()) {
                                delay(speed.get() - (time - lastTime));
                            }

                            for (int i = 0; i < controller.getCount(); i++) {
                                if (downs[i]) {
                                    currents[i] -= 0.01;
                                    if (currents[i] < 0) {
                                        currents[i] = 0;
                                        downs[i] = false;
                                    }
                                } else {
                                    currents[i] += 0.01;
                                    if (currents[i] > 1) {
                                        currents[i] = 1.0;
                                        downs[i] = true;
                                    }
                                }

                                float r = (endColor.get().getR() * currents[i]) + (startColor.get().getR() * (1.0f - currents[i]));
                                float g = (endColor.get().getG() * currents[i]) + (startColor.get().getG() * (1.0f - currents[i]));
                                float b = (endColor.get().getB() * currents[i]) + (startColor.get().getB() * (1.0f - currents[i]));

                                controller.setColor(i, Color(static_cast <ColorChannel> (r), static_cast <ColorChannel> (g), static_cast <ColorChannel> (b)));
                            }

                            lastTime = millis();
                        }
                        /**
                         * Called when the effect is replaced by another one in a controller
                         */
                        void stop(LedController& controller) override {
                            controller.setColor(BLACK);
                            delete[] currents;
                            delete[] downs;
                        }
            };

        }
    }
