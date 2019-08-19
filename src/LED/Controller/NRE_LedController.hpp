
    /**
     * @file NRE_LedController.hpp
     * @brief Declaration of Micro's API's Object : LedController
     * @author Louis ABEL
     * @date 17/08/2019
     * @copyright CC-BY-NC-SA
     */

     #pragma once

     #include <Adafruit_NeoPixel.h>
     #include "../Color/NRE_Color.hpp"
     #include "../../Core/NRE_Core.hpp"

     #include "../Effect/NRE_Effect.hpp"

     #include "../../ROM/Manager/NRE_RomManager.hpp"

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
                    ObservedData<Color> current;    /**< The current led color */
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
                        /**
                         * Set the color changes handles
                         * @param handle the new handler
                         */
                        void setColorHandle(std::function<void(Color&)> handle);

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
                        Led& operator=(Led && led) = default;
            };

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
                    Effect* lightEffect;            /**< The controller light effect */

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

                    //## Getter ##//
                        /**
                         * @return the leds count
                         */
                        LedId getCount() const;

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
                         * @param color the new color
                         */
                        void setColor(Color const& color);
                        /**
                         * Set all leds color (and turn them on)
                         * @param color the new color
                         */
                        void setColor(ObservedData<Color> const& color);
                        /**
                         * Set a led color (and turn it on)
                         * @param id    the led id
                         * @param color the new color
                         */
                        void setColor(LedId id, Color const& color);
                        /**
                         * Set a led color (and turn it on)
                         * @param id    the led id
                         * @param color the new color
                         */
                        void setColor(LedId id, ObservedData<Color> const& color);
                        /**
                         * Set a color handle for all leds
                         * @param handle the new handler
                         */
                        void setColorHandle(std::function<void(Color&)> handle);
                        /**
                         * Set a color handle for a given led
                         * @param id     the led id
                         * @param handle the new handler
                         */
                        void setColorHandle(LedId id, std::function<void(Color&)> handle);
                        /**
                         * Set the light effect
                         * @param effect the new effect
                         */
                        void setEffect(Effect* effect);
                        /**
                         * Setup the controller
                         * @param startUpColor the startup color for all leds
                         */
                        void setup(Color const& startUpColor = BLACK);
                        /**
                         * The controller's loop
                         */
                        void loop();

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

    #include "NRE_LedInl.hpp"
