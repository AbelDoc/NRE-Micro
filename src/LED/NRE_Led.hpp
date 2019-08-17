
    /**
     * @file LED/NRE_Led.hpp
     * @brief Declaration of Micro's API's Object : Led
     * @author Louis ABEL
     * @date 17/08/2019
     * @copyright CC-BY-NC-SA
     */

     #pragma once

    #include "Color/NRE_Color.hpp"

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

            class LedController;

            typedef uint16_t LedId;

            /**
             * @class Led
             * @brief Represent a single Led
             */
            class Led {
                private :   // Fields
                    LedId id;                       /**< The led id used for controller actions */
                    Color current;                  /**< The current led color */
                    LedController* controller;      /**< The parent controller */

                public :    // Methods
                    //## Constructor ##//
                        /**
                         * No default constructor
                         */
                        Led() = delete;
                        /**
                         * Construct the led from the controller
                         * @param i   the led's id
                         * @param ctr the leds controller
                         */
                        Led(LedId i, LedController* ctr);

                    //## Copy Constructor ##//
                        /**
                         * Copy led into this
                         * @param led the led to copy
                         */
                        Led(Led const& led) = default;

                    //## Move Constructor ##//
                        /**
                         * Move led into this
                         * @param led the led to move
                         */
                        Led(Led && led) = default;

                    //## Getter ##//
                        /**
                         * @return the internal compressed color
                         */
                        CompressedColor getColor() const;

                    //## Setter ##//
                        /**
                         * Set the led color
                         * @param color the new color
                         */
                        void setColor(Color const& color);

                    //## Methods ##//
                        /**
                         * Update the led color
                         * @param color the new color
                         */
                        void update(Color const& color);
                        /**
                         * Turn off the led
                         */
                        void turnOff() const;
                        /**
                         * Turn on the led
                         */
                        void turnOn() const;

                    //## Assignment Operator ##//
                        /**
                         * Copy assign led into this
                         * @param led the led to copy
                         * @return the reference of himself
                         */
                        Led& operator=(Led const& led) = default;
                        /**
                         * Move assign led into this
                         * @param led the led to move
                         * @return the reference of himself
                         */
                        Led& operator=(Led && c) = default;
            };

        }
    }

    #include "NRE_LedInl.hpp"
