
    /**
     * @file NRE_LedControllerInl.hpp
     * @brief Implementation of Micro's API's Object : LedController
     * @author Louis ABEL
     * @date 17/08/2019
     * @copyright CC-BY-NC-SA
     */

     namespace NRE {
         namespace Micro {

            inline LedController::LedController(LedId nb, Pin pin, neoPixelType type) : controller(nb, pin, type), nbLeds(nb), lightEffect(nullptr) {
            }

            inline LedController::~LedController() {
                delete lightEffect;
                lightEffect = nullptr;
            }

            inline LedId LedController::getCount() const {
                return nbLeds;
            }

            inline void LedController::turnOff() {
                controller.clear();
            }

            inline void LedController::setColor(Color const& color) {
                controller.fill(color.getColor(), 0, nbLeds);
            }

            inline void LedController::setColor(ObservedData<Color> const& color) {
                setColor(color.get());
            }

            inline void LedController::setColor(LedId id, Color const& color) {
                controller.setPixelColor(id, color.getColor());
            }

            inline void LedController::setColor(LedId id, ObservedData<Color> const& color) {
                setColor(id, color.get());
            }

            inline void LedController::setEffect(Effect* effect) {
                if (lightEffect) {
                    lightEffect->stop(*this);
                    controller.show();
                    delete lightEffect;
                    lightEffect = nullptr;
                }
                lightEffect = effect;
                lightEffect->start(*this);
                controller.show();
            }

            inline void LedController::setup(Color const& startUpColor) {
                controller.begin();
                setColor(startUpColor);
            }

            inline void LedController::loop() {
                lightEffect->run(*this);
                controller.show();
            }

         }
     }
