
    /**
     * @file NRE_LedManager.hpp
     * @brief Declaration of Micro's API's Object : LedManager
     * @author Louis ABEL
     * @date 17/08/2019
     * @copyright CC-BY-NC-SA
     */

     #pragma once

        #ifndef NRE_USE_ROM
            #pragma message("Enable the ROM module to get automatic LEDs management")
        #endif

     #include "../../Core/Module/NRE_Module.hpp"
     #include "../Controller/NRE_LedController.hpp"

     #include "../Effect/Core/NRE_FixEffect.hpp"
     #include "../Effect/Core/NRE_WaveEffect.hpp"
     #include "../Effect/Core/NRE_RotateEffect.hpp"
     #include "../Effect/Core/NRE_RotateFixEffect.hpp"
     #include "../Effect/Core/NRE_RotateLinearEffect.hpp"
     #include "../Effect/Core/NRE_RotateLinearGradiantEffect.hpp"
     #include "../Effect/Core/NRE_RotateLinearRainbowEffect.hpp"

     #include <vector>
     #include <memory>

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
             * @class LedManager
             * @brief Manage all leds controller
             */
            class LedManager : public Module<LedManager> {
                private :   // Static
                    static constexpr int MAX_CONTROLLER = 10;
                
                private :   // Fields
                    ObservedData<int> nbControllers;            /**< The number of controllers */
                    ObservedData<LedId> nbLeds[MAX_CONTROLLER]; /**< The number of leds for each controllers */
                    ObservedData<Pin> pins[MAX_CONTROLLER];     /**< The pin number for each controllers */
                    std::vector<LedController*> controllers;    /**< The leds controllers */

                public :    // Methods
                    //## Constructor ##//
                        /**
                         * Construct the led module
                         */
                        LedManager();

                    //## Deconstructor ##//
                        /**
                         * LedManager Deconstructor
                         */
                        ~LedManager();

                    //## Getter ##//
                        /**
                         * Query a led controller
                         * @param  id the controller id
                         * @return    the corresponding controller
                         */
                        LedController& getController(unsigned char id);
                        /**
                         * @return the number of controller in rom
                         */
                        int getNbControllers() const;
                        /**
                         * @return the manager info
                         */
                        String getInfo() const;
    
                    //## Setter ##//
                        /**
                         * Set a controller color
                         * @param index  the controller id
                         * @param cIndex the color index
                         * @param color  the new color
                         */
                        void setColor(unsigned char index, unsigned char cIndex, Color color);
                        /**
                         * Set a controller speed
                         * @param index the controller id
                         * @param speed the new speed
                         */
                        void setSpeed(unsigned char index, long speed);
                        /**
                         * Set a controller effect
                         * @param index the controller id
                         * @param speed the new effect
                         */
                        void setEffect(unsigned char index, unsigned char effect);
                        /**
                         * Set the number of controllers in rom
                         * @param nb  the number of controllers
                         */
                        void setNbControllers(int nb);
                        /**
                         * Set a controller number of leds
                         * @param index the controller id
                         * @param leds  the number of leds
                         */
                        void setLeds(unsigned char index, LedId leds);
                        /**
                         * Set a controller pin
                         * @param index the controller id
                         * @param pin   the controller pin
                         */
                        void setPin(unsigned char index, Pin pin);

                    //## Methods ##//
                        /**
                         * Add a led controller
                         * @param nb   the number of led
                         * @param pin  the leds strip pin
                         * @param type the leds type
                         * @return the controller id
                         */
                        unsigned char addController(LedId nb, Pin pin, neoPixelType type = NEO_GRB + NEO_KHZ800, bool addInRom = true);
                        /**
                         * Setup the module
                         */
                        void setup() override;
                        /**
                         * Loop through all controller
                         * @param delta the delta time from the last frame
                         */
                        void loop(long delta) override;
                        #ifdef NRE_USE_ROM
                            /**
                             * Load controllers from rom
                             */
                            void loadFromROM();
                            /**
                             * Add manager data into rom
                             */
                            void addData();
                        #endif
            };

            static LedManager _ledManager;
        }
    }

    #include "NRE_LedManagerInl.hpp"
