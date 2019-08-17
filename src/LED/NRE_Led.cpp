
    /**
     * @file NRE_Led.cpp
     * @brief Implementation of Micro's API's Object : Led
     * @author Louis ABEL
     * @date 17/08/2019
     * @copyright CC-BY-NC-SA
     */

    #include "NRE_Led.hpp"
    #include "Controller/NRE_LedController.hpp"

    namespace NRE {
        namespace Micro {

            void Led::update(Color const& color) {
                setColor(color);
                controller->turnOn(id);
            }

            void Led::turnOff() const {
                controller->turnOff(id);
            }

            void Led::turnOn() const {
                controller->turnOn(id);
            }

        }
    }
