
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
                    Adafruit_NeoPixel controller;        /**< Internal controller */
                    LedId nbLeds;                        /**< The number of controlled leds */
                    Pin pin;                             /**< The controller pin */
                    Effect* lightEffect;                 /**< The controller light effect */
                    long sleepTimer;                     /**< Allow the controller to sleep without impacting other module */
                    
                    ObservedData<Color> colors[6];
                    ObservedData<long> speed;
                    ObservedData<unsigned char> effect;

                public :    // Methods
                    //## Constructor ##//
                        /**
                         * No default constructor
                         */
                        LedController() = delete;
                        /**
                         * Construct the led controller
                         * @param nb       the number of controlled led
                         * @param p        the leds strip pin
                         * @param type     the leds type
                         * @param addInRom tell if we add the observed data from the controller in the rom
                         */
                        LedController(LedId nb, Pin p, neoPixelType type = NEO_GRB + NEO_KHZ800, bool addInRom = true);

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
                        /**
                         * @return the sleep timer value
                         */
                        unsigned long getTimer() const;
                        /**
                         * Query an observed color
                         * @param index the color index
                         * @return the corresponding color
                         */
                        ObservedData<Color>& getColor(int index);
                        /**
                         * @return the observed speed
                         */
                        ObservedData<long>& getSpeed();
                        /**
                         * @return the observed effect
                         */
                        ObservedData<unsigned char>& getEffect();
                        /**
                         * @return controller infos
                         */
                        String getInfo() const;
    
                    //## Setter ##//
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

                    //## Methods ##//
                        /**
                         * Turn all leds off
                         */
                        void turnOff();
                        /**
                         * Setup the controller
                         * @param startUpColor the startup color for all leds
                         */
                        void setup(Color const& startUpColor = RED);
                        /**
                         * The controller's loop
                         * @param delta the delta time from last frame
                         */
                        void loop(long delta);
                        /**
                         * Set the sleep timer
                         * @param time the new timer
                         */
                        void sleep(long time);
                        
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
