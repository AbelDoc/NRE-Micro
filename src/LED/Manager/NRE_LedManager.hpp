
    /**
     * @file NRE_LedManager.hpp
     * @brief Declaration of Micro's API's Object : LedManager
     * @author Louis ABEL
     * @date 17/08/2019
     * @copyright CC-BY-NC-SA
     */

     #pragma once

     #include "../../Core/Module/NRE_Module.hpp"
     #include "../Controller/NRE_LedController.hpp"

     #include <vector>

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
                private :   // Fields
                    std::vector<LedController*> controllers;    /**< The leds controllers */

                public :    // Methods
                    //## Constructor ##//
                        /**
                         * Construct the led module
                         */
                        LedManager() = default;

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

                    //## Methods ##//
                        /**
                         * Add a led controller
                         * @param nb   the number of led
                         * @param pin  the leds strip pin
                         * @param type the leds type
                         * @return the controller id
                         */
                        unsigned char addController(LedId nb, Pin pin, neoPixelType type = NEO_GRB + NEO_KHZ800);
                        /**
                         * Setup the module
                         */
                        void setup() override;
            };

            static LedManager _ledManager;
        }
    }

    #include "NRE_LedManagerInl.hpp"
