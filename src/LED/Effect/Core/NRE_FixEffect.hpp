
    /**
     * @file NRE_FixEffect.hpp
     * @brief Declaration of Micro's API's Object : FixEffect
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
             * @class FixEffect
             * @brief Represent a fix light effect, setting all leds to the same color with no movement
             */
            class FixEffect : public Effect {
                private :   // Fields
                    ObservedData<Color>& color; /**< The effect color */

                public :    // Methods
                    //## Constructor ##//
                        /**
                         * No default constructor
                         */
                        FixEffect() = delete;
                        /**
                         * Construct the effect from the fix color
                         * @param c the effect color
                         */
                        FixEffect(ObservedData<Color>& c) : color(c) {
                        }

                    //## Methods ##//
                        /**
                         * Called when the effect is set to a controller
                         */
                        void start(LedController& controller) override {
                        }
                        /**
                         * Called at each loop iteration
                         */
                        void run(LedController& controller) override {
                            controller.setColor(color);
                        }
                        /**
                         * Called when the effect is replaced by another one in a controller
                         */
                        void stop(LedController& controller) override {
                        }
            };

        }
    }
