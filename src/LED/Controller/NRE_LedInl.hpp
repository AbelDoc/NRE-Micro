
    /**
     * @file NRE_LedInl.hpp
     * @brief Implementation of Micro's API's Object : Led
     * @author Louis ABEL
     * @date 17/08/2019
     * @copyright CC-BY-NC-SA
     */

    namespace NRE {
        namespace Micro {

            inline Led::Led(LedId i, LedController* ctr) : id(i), controller(ctr) {
            }

            inline void Led::update(Color const& color) {
                setColor(color);
                controller->turnOn(id);
            }

            inline void Led::turnOff() const {
                controller->turnOff(id);
            }

            inline void Led::turnOn() const {
                controller->turnOn(id);
            }

            inline CompressedColor Led::getColor() const {
                return current.get().getColor();
            }

            inline void Led::setColor(Color const& color) {
                current = color;
            }

            inline void Led::setColorHandle(std::function<void(Color&)> handle) {
                current.setHandle(handle);
            }

        }
    }
