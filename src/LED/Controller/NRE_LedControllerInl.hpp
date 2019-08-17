
    /**
     * @file NRE_LedControllerInl.hpp
     * @brief Implementation of Micro's API's Object : LedController
     * @author Louis ABEL
     * @date 17/08/2019
     * @copyright CC-BY-NC-SA
     */

     namespace NRE {
         namespace Micro {

            inline LedController::LedController(LedId nb, Pin pin, neoPixelType type) : controller(nb, pin, type), nbLeds(nb) {
                leds = static_cast <Led*> (::operator new(sizeof(Led) * nb));
                for (LedId i = 0; i < nbLeds; ++i) {
                    leds[i] = *(new(&leds[i]) Led(i, this));
                }
            }

            inline LedController::~LedController() {
                for (LedId i = 0; i < nbLeds; ++i) {
                    leds[i].~Led();
                }
                ::operator delete(leds);
            }

            inline LedController::Iterator LedController::begin() {
                return leds;
            }

            inline LedController::ConstIterator LedController::begin() const {
                return ConstIterator(leds);
            }

            inline LedController::ConstIterator LedController::cbegin() const {
                return begin();
            }

            inline LedController::Iterator LedController::end() {
                return leds + nbLeds;
            }

            inline LedController::ConstIterator LedController::end() const {
                return ConstIterator(leds + nbLeds);
            }

            inline LedController::ConstIterator LedController::cend() const {
                return end();
            }

            inline void LedController::turnOff() {
                controller.clear();
                controller.show();
            }

            inline void LedController::turnOn() {
                for (LedId i = 0; i < nbLeds; ++i) {
                    controller.setPixelColor(i, leds[i].getColor());
                }
                controller.show();
            }

            inline void LedController::turnOff(LedId id) {
                controller.setPixelColor(id, BLACK.getColor());
                controller.show();
            }

            inline void LedController::turnOn(LedId id) {
                controller.setPixelColor(id, leds[id].getColor());
                controller.show();
            }

            inline void LedController::setColor(Color const& color) {
                for (Led l : *this) {
                    l.setColor(color);
                }
                controller.fill(color.getColor(), 0, nbLeds);
                controller.show();
            }

            inline void LedController::setColor(LedId id, Color const& color) {
                leds[id].setColor(color);
                turnOn(id);
            }

            inline void LedController::setup(Color const& startUpColor) {
                controller.begin();
                setColor(startUpColor);
            }

            inline Led& LedController::operator[](LedId index) {
                return leds[index];
            }

            inline Led const& LedController::operator[](LedId index) const {
                return leds[index];
            }

         }
     }
