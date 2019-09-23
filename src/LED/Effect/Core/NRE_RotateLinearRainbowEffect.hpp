
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
                    ObservedData<Color>& c1;            /**< The first color */
                    ObservedData<Color>& c2;            /**< The second color */
                    ObservedData<Color>& c3;            /**< The third color */
                    ObservedData<Color>& c4;            /**< The fourth color */
                    ObservedData<Color>& c5;            /**< The fifth color */
                    ObservedData<Color>& c6;            /**< The sixth color */
                    unsigned char speed;                /**< The effect speed */
                    float* currents;                    /**< The current step */
                    int* currentColors;                 /**< The currents color */
                    ObservedData<Color>** startColors;  /**< The starts colors */
                    ObservedData<Color>** endColors;    /**< The ends colors */
                    unsigned long lastTime;             /**< The last step time */

                public :    // Methods
                    //## Constructor ##//
                        /**
                         * No default constructor
                         */
                        RotateLinearRainbowEffect() = delete;
                        /**
                         * Construct the effect from the fix color
                         * @param color1 the first effect color
                         * @param color2 the second effect color
                         * @param color3 the third effect color
                         * @param color4 the fourth effect color
                         * @param color5 the fifth effect color
                         * @param color6 the sixth effect color
                         * @param s      the effect speed
                         */
                        RotateLinearRainbowEffect(ObservedData<Color>& color1, ObservedData<Color>& color2, ObservedData<Color>& color3, ObservedData<Color>& color4, ObservedData<Color>& color5, ObservedData<Color>& color6, unsigned char s = 1) : c1(color1), c2(color2), c3(color3), c4(color4), c5(color5), c6(color6), startColors(nullptr), endColors(nullptr), speed(s), currents(nullptr), currentColors(nullptr), lastTime(0) {
                        }

                    //## Methods ##//
                        /**
                         * Called when the effect is set to a controller
                         */
                        void start(LedController& controller) override {
                            controller.setColor(BLACK);
                            currents = new float[controller.getCount()];
                            startColors = new ObservedData<Color>*[controller.getCount()];
                            endColors = new ObservedData<Color>*[controller.getCount()];
                            currentColors = new int[controller.getCount()];

                            currents[0] = 0;

                            for (int i = 0; i < controller.getCount(); i++) {
                                startColors[i] = &c1;
                                endColors[i] = &c2;
                                currentColors[0] = 0;
                            }

                            for (int i = 1; i < controller.getCount(); i++) {
                                currents[i] = currents[i - 1] + 1.0f / controller.getCount();
                            }
                        }
                        /**
                         * Called at each loop iteration
                         */
                        void run(LedController& controller) override {
                            unsigned long time = micros();
                            if (time - lastTime <= 100 * speed) {
                                delay(100 * speed - (time - lastTime));
                            }

                            for (int i = 0; i < controller.getCount(); i++) {
                                currents[i] += 0.01;
                                if (currents[i] > 1) {
                                    currents[i] = 0.0;
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

                            lastTime = micros();
                        }
                        /**
                         * Called when the effect is replaced by another one in a controller
                         */
                        void stop(LedController& controller) override {
                            controller.setColor(BLACK);
                            delete[] currents;
                            delete[] currentColors;
                            delete[] startColors;
                            delete[] endColors;
                        }
            };

        }
    }
