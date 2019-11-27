
    /**
     * @file NRE_LedControllerInl.hpp
     * @brief Implementation of Micro's API's Object : LedController
     * @author Louis ABEL
     * @date 17/08/2019
     * @copyright CC-BY-NC-SA
     */

     namespace NRE {
         namespace Micro {

            inline LedController::LedController(LedId nb, Pin p, neoPixelType type, bool addInRom) : controller(nb, p, type), nbLeds(nb), pin(p), lightEffect(nullptr), modifier(nullptr), sleepTimer(0), colors{RED, YELLOW, GREEN, CYAN, BLUE, MAGENTA}, speed(100), effect(6) {
                #ifdef NRE_USE_ROM
                    if (addInRom) {
                        MicroManager::get<RomManager>().addData(speed);
                        MicroManager::get<RomManager>().addData(colors[0]);
                        MicroManager::get<RomManager>().addData(colors[1]);
                        MicroManager::get<RomManager>().addData(colors[2]);
                        MicroManager::get<RomManager>().addData(colors[3]);
                        MicroManager::get<RomManager>().addData(colors[4]);
                        MicroManager::get<RomManager>().addData(colors[5]);
                        MicroManager::get<RomManager>().addData(effect);
                        MicroManager::get<RomManager>().addData(modifierNum);
                    }
                #endif
            }

            inline LedController::~LedController() {
                delete lightEffect;
                delete modifier;
                modifier = nullptr;
                lightEffect = nullptr;
            }

            inline LedId LedController::getCount() const {
                return nbLeds;
            }
            
            inline unsigned long LedController::getTimer() const {
                return sleepTimer;
            }
            
            inline ObservedData<Color>& LedController::getColor(int index) {
                return colors[index];
            }
            
            inline ObservedData<long>& LedController::getSpeed() {
                return speed;
            }
            
            inline ObservedData<unsigned char>& LedController::getEffect() {
                return effect;
            }
            
            inline ObservedData<unsigned char>& LedController::getModifier() {
                return modifierNum;
            }
            
            inline String LedController::getInfo() const {
                return String(effect.get()) + "\n" +
                       String(speed.get()) + "\n" +
                       String(nbLeds) + "\n" +
                       String(pin) + "\n" +
                       String(colors[0]->getInfo()) + "\n" +
                       String(colors[1]->getInfo()) + "\n" +
                       String(colors[2]->getInfo()) + "\n" +
                       String(colors[3]->getInfo()) + "\n" +
                       String(colors[4]->getInfo()) + "\n" +
                       String(colors[5]->getInfo());
            }
            
            inline void LedController::setModifier(Modifier* m) {
                delete modifier;
                modifier = m;
            }

            inline void LedController::setColor(Color const& color) {
                if (modifier != nullptr) {
                    controller.fill(modifier->modify(color).getColor(), 0, nbLeds);
                } else {
                    controller.fill(color.getColor(), 0, nbLeds);
                }
            }

            inline void LedController::setColor(ObservedData<Color> const& color) {
                setColor(color.get());
            }

            inline void LedController::setColor(LedId id, Color const& color) {
                if (modifier != nullptr) {
                    controller.setPixelColor(id, modifier->modify(color).getColor());
                } else {
                    controller.setPixelColor(id, color.getColor());
                }
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
                if (effect) {
                    lightEffect->start(*this);
                    controller.show();
                }
            }
    
            inline void LedController::turnOff() {
                controller.clear();
            }

            inline void LedController::setup(Color const& startUpColor) {
                controller.begin();
                setColor(startUpColor);
                controller.show();
            }

            inline void LedController::loop(long delta) {
                if (sleepTimer <= 0) {
                    if (lightEffect) {
                        lightEffect->run(*this, delta);
                        controller.show();
                    }
                } else {
                    if (delta <= 0) {
                        delta = 1;
                    }
                    sleepTimer -= delta;
                }
            }
            
            inline void LedController::sleep(long time) {
                sleepTimer = time;
            }

         }
     }
