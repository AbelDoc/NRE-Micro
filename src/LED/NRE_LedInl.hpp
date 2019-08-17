
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

            inline CompressedColor Led::getColor() const {
                return current.getColor();
            }

            inline void Led::setColor(Color const& color) {
                current = color;
            }

        }
    }
