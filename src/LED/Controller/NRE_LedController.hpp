
    /**
     * @file NRE_LedController.hpp
     * @brief Declaration of Micro's API's Object : LedController
     * @author Louis ABEL
     * @date 17/08/2019
     * @copyright CC-BY-NC-SA
     */

     #pragma once
    #include <Adafruit_NeoPixel.h>
    #include "../NRE_Led.hpp"
    #include "../../Core/NRE_Core.hpp"

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
             * @class LedController
             * @brief Manage access to a led component
             */
            class LedController {
                public :    // Iterator
                    typedef Led*          Iterator;
                    typedef const Led*    ConstIterator;

                private :   // Fields
                    Adafruit_NeoPixel controller;   /**< Internal controller */
                    Led* leds;                      /**< All controlled leds */
                    LedId nbLeds;                   /**< The number of controlled leds */

                public :    // Methods
                    //## Constructor ##//
                        /**
                         * No default constructor
                         */
                        LedController() = delete;
                        /**
                         * Construct the led controller
                         * @param nb   the number of controlled led
                         * @param pin  the leds strip pin
                         * @param type the leds type
                         */
                        LedController(LedId nb, Pin pin, neoPixelType type = NEO_GRB + NEO_KHZ800);

                    //## Copy Constructor ##//
                        /**
                         * Copy forbidden
                         * @param ctr the controller to copy
                         */
                        LedController(LedController const& ctr) = delete;

                    //## Move Constructor ##//
                        /**
                         * Move forbidden
                         * @param ctr the controller to move
                         */
                        LedController(LedController && ctr) = delete;

                    //## Deconstructor ##//
                        /**
                         * LedController Deconstructor
                         */
                        ~LedController();

                    //## Iterator Access ##//
                        /**
                         * @return an iterator on the first element
                         */
                        Iterator begin();
                        /**
                         * @return a const iterator on the first element
                         */
                        ConstIterator begin() const;
                        /**
                         * @return a const iterator on the first element
                         */
                        ConstIterator cbegin() const;
                        /**
                         * @return an iterator on the end of the container
                         */
                        Iterator end();
                        /**
                         * @return a const iterator on the end of the container
                         */
                        ConstIterator end() const;
                        /**
                         * @return a const iterator on the end of the container
                         */
                        ConstIterator cend() const;

                    //## Methods ##//
                        /**
                         * Turn all leds off
                         */
                        void turnOff();
                        /**
                         * Turn a led off
                         * @param id the led id
                         */
                        void turnOff(LedId id);
                        /**
                         * Turn all leds on
                         */
                        void turnOn();
                        /**
                         * Turn a led on with it's saved color
                         * @param id the led id
                         */
                        void turnOn(LedId id);
                        /**
                         * Set all leds color (and turn them on)
                         * @param id    the led id
                         * @param color the new color
                         */
                        void setColor(Color const& color);
                        /**
                         * Set a led color (and turn it on)
                         * @param id    the led id
                         * @param color the new color
                         */
                        void setColor(LedId id, Color const& color);
                        /**
                         * Setup the controller
                         * @param startUpColor the startup color for all leds
                         */
                        void setup(Color const& startUpColor = BLACK);

                    //## Access Operator ##//
                        /**
                         * Access a particular element without bound checking
                         * @param  index the element index
                         * @return       the corresponding element
                         */
                        Led& operator[](LedId index);
                        /**
                         * Access a particular element without bound checking
                         * @param  index the element index
                         * @return       the corresponding element
                         */
                        Led const& operator[](LedId index) const;

                    //## Assignment Operator ##//
                        /**
                         * Copy assign forbidden
                         * @param ctr the controller to copy
                         * @return the reference of himself
                         */
                        LedController& operator=(LedController const& ctr) = delete;
                        /**
                         * Move assign forbidden
                         * @param ctr the controller to move
                         * @return the reference of himself
                         */
                        LedController& operator=(LedController && ctr) = delete;
            };

        }
    }

    #include "NRE_LedControllerInl.hpp"
