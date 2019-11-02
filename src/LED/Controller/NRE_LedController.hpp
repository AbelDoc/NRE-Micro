
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
             * @class LedController
             * @brief Manage access to a led component
             */
            class LedController {
                private :   // Fields
                    Adafruit_NeoPixel controller;   /**< Internal controller */
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
                         * Set the light effect
                         * @param effect the new effect
                         */
                        void setEffect(Effect* effect);
                        /**
                         * Setup the controller
                         * @param startUpColor the startup color for all leds
                         */
                        void setup(Color const& startUpColor = RED);
                        /**
                         * The controller's loop
                         */
                        void loop();

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
