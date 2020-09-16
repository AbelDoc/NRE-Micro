
    /**
     * @file NRE_RotateLinearRainbowEffect.hpp
     * @brief Declaration of Micro's API's Object : RotateLinearRainbowEffect
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
             * @class RotateLinearRainbowEffect
             * @brief Represent a linear gradiant, with a rotating wave effect with multiple colors
             */
            class RotateLinearRainbowEffect : public Effect {
                private :   // Fields
                    float* currents;                    /**< The current step */
                    int* currentColors;                 /**< The currents color */
                    ObservedData<Color>** startColors;  /**< The starts colors */
                    ObservedData<Color>** endColors;    /**< The ends colors */

                public :    // Methods
                    //## Constructor ##//
                        /**
                         * Construct the effect
                         */
                        constexpr RotateLinearRainbowEffect() : startColors(nullptr), endColors(nullptr), currents(nullptr), currentColors(nullptr) {
                        }

                    //## Methods ##//
                        /**
                         * Called when the effect is set to a controller
                         * @param controller the master controller
                         */
                        void start(LedController& controller) override {
                            controller.turnOff();
                            currents = new float[controller.getCount()];
                            startColors = new ObservedData<Color>*[controller.getCount()];
                            endColors = new ObservedData<Color>*[controller.getCount()];
                            currentColors = new int[controller.getCount()];

                            currents[0] = 0;
                            ObservedData<Color>& c1 = controller.getColor(0);
                            ObservedData<Color>& c2 = controller.getColor(1);

                            for (int i = 0; i < controller.getCount(); i++) {
                                startColors[i] = &c1;
                                endColors[i] = &c2;
                                currentColors[0] = 0;
                            }

                            for (int i = 1; i < controller.getCount(); i++) {
                                currents[i] = currents[i - 1] + 0.2;
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
                            ObservedData<Color>& c1 = controller.getColor(0);
                            ObservedData<Color>& c2 = controller.getColor(1);
                            ObservedData<Color>& c3 = controller.getColor(2);
                            ObservedData<Color>& c4 = controller.getColor(3);
                            ObservedData<Color>& c5 = controller.getColor(4);
                            ObservedData<Color>& c6 = controller.getColor(5);

                            for (int i = 0; i < controller.getCount(); i++) {
                                currents[i] += 0.05;
                                while (currents[i] > 1) {
                                    currents[i] = currents[i] - 1.0;
                                    ObservedData<Color>* next;
                                    switch (currentColors[i]) {
                                        case (0) : {
                                            next = &c3;
                                            break;
                                        }
                                        case (1) : {
                                            next = &c4;
                                            break;
                                        }
                                        case (2) : {
                                            next = &c5;
                                            break;
                                        }
                                        case (3) : {
                                            next = &c6;
                                            break;
                                        }
                                        case (4) : {
                                            next = &c1;
                                            break;
                                        }
                                        case (5) : {
                                            next = &c2;
                                            break;
                                        }
                                    }
                                    currentColors[i] = (currentColors[i] + 1) % 6;
                                    startColors[i] = endColors[i];
                                    endColors[i] = next;
                                }

                                float r = (endColors[i]->get().getR() * currents[i]) + (startColors[i]->get().getR() * (1.0f - currents[i]));
                                float g = (endColors[i]->get().getG() * currents[i]) + (startColors[i]->get().getG() * (1.0f - currents[i]));
                                float b = (endColors[i]->get().getB() * currents[i]) + (startColors[i]->get().getB() * (1.0f - currents[i]));

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
                            delete[] currentColors;
                            delete[] startColors;
                            delete[] endColors;
                        }
            };

        }
    }
