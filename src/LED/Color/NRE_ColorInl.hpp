
    /**
     * @file NRE_ColorInl.hpp
     * @brief Implementation of Micro's API's Object : Color
     * @author Louis ABEL
     * @date 17/08/2019
     * @copyright CC-BY-NC-SA
     */

    namespace NRE {
        namespace Micro {

            inline ColorChannel Color::getR() const {
                return r;
            }

            inline ColorChannel Color::getG() const {
                return g;
            }

            inline ColorChannel Color::getB() const {
                return b;
            }
            
            inline String Color::getInfo() const {
                return String(getR()) + "-" + String(getG()) + "-" + String(getB());
            }

            inline void Color::setR(ColorChannel red) {
                r = red;
            }

            inline void Color::setG(ColorChannel green) {
                g = green;
            }

            inline void Color::setB(ColorChannel blue) {
                b = blue;
            }

        }
    }
