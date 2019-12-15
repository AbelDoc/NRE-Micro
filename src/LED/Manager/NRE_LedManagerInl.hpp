
    /**
     * @file NRE_LedManagerInl.hpp
     * @brief Implementation of Micro's API's Object : LedManager
     * @author Louis ABEL
     * @date 17/08/2019
     * @copyright CC-BY-NC-SA
     */

    namespace NRE {
        namespace Micro {
            
            inline LedManager::LedManager() : nbControllers(1), nbLeds{10, 10, 10, 10, 10, 10, 10, 10, 10, 10}, pins{15, 14, 13, 12, 11, 10, 9, 8, 7, 6}, modifier(nullptr), active(true) {
            }

            inline LedManager::~LedManager() {
                for (LedController* controller : controllers) {
                    delete controller;
                    controller = nullptr;
                }
                delete modifier;
                modifier = nullptr;
            }

            inline LedController& LedManager::getController(unsigned char id) {
                return *(controllers[id]);
            }
            
            inline int LedManager::getNbControllers() const {
                return nbControllers.get();
            }
            
            inline String LedManager::getInfo() const {
                String res(nbControllers.get());
                res += "\n";
                res += (active) ? ("1\n") : ("0\n");
                for (std::size_t i = 0; i < controllers.size() - 1; i++) {
                    res += controllers[i]->getInfo() + "\n";
                }
                res += controllers[controllers.size() - 1]->getInfo();
                return res;
            }
            
            inline void LedManager::setColor(unsigned char index, unsigned char cIndex, Color color) {
                controllers[index]->getColor(cIndex) = color;
            }
            
            inline void LedManager::setSpeed(unsigned char index, long speed) {
                controllers[index]->getSpeed() = speed;
            }
    
            inline void LedManager::setEffect(unsigned char index, unsigned char effect) {
                controllers[index]->getEffect() = effect;
            }
            
            inline void LedManager::setNbControllers(int nb) {
                nbControllers = nb;
            }
            
            inline void LedManager::setLeds(unsigned char index, LedId leds) {
                nbLeds[index] = leds;
            }
            
            inline void LedManager::setPin(unsigned char index, Pin pin) {
                pins[index] = pin;
            }
            
            inline void LedManager::setActive(bool state) {
                active = state;
                if (!active) {
                    for (LedController* controller : controllers) {
                        controller->turnOff();
                    }
                }
            }
            
            inline void LedManager::setModifier(Modifier* m) {
                if (modifier != nullptr) {
                    modifier->onStop();
                    delete modifier;
                    modifier = nullptr;
                }
                modifier = m;
                if (modifier != nullptr) {
                    modifier->onStart();
                }
            }

            inline unsigned char LedManager::addController(LedId nb, Pin pin, neoPixelType type, bool addInRom) {
                std::shared_ptr<std::size_t> id(new std::size_t(controllers.size()));
                controllers.push_back(new LedController(nb, pin, type, addInRom));
                controllers[*(id.get())]->getEffect().setHandle([id, this](unsigned char& data) {
                    int c = *(id.get());
                    switch (data) {
                        case (0) : {
                            controllers[c]->setEffect(new FixEffect());
                            break;
                        }
                        case (1) : {
                            controllers[c]->setEffect(new RotateEffect());
                            break;
                        }
                        case (2) : {
                            controllers[c]->setEffect(new RotateFixEffect());
                            break;
                        }
                        case (3) : {
                            controllers[c]->setEffect(new RotateFixEffect(true, true));
                            break;
                        }
                        case (4) : {
                            controllers[c]->setEffect(new WaveEffect());
                            break;
                        }
                        case (5) : {
                            controllers[c]->setEffect(new RotateLinearEffect());
                            break;
                        }
                        case (6) : {
                            controllers[c]->setEffect(new RotateLinearGradiantEffect());
                            break;
                        }
                        case (7) : {
                            controllers[c]->setEffect(new RotateLinearRainbowEffect());
                            break;
                        }
                        default : {
                            controllers[c]->setEffect(new RotateLinearGradiantEffect());
                            break;
                        }
                    }
                });

                return *(id.get());
            }

            inline void LedManager::setup() {
                for (LedController* controller : controllers) {
                    controller->setup();
                }
            }

            inline void LedManager::loop(long delta) {
                if (modifier != nullptr) {
                    modifier->onRun();
                    if (modifier->isFinished()) {
                        modifier->onStop();
                        delete modifier;
                        modifier = nullptr;
                    }
                }
                if (active) {
                    for (LedController* controller : controllers) {
                        controller->loop(delta);
                    }
                }
            }

            #ifdef NRE_USE_ROM
                inline void LedManager::addData() {
                    MicroManager::get<RomManager>().addData(nbControllers);
                    for (auto i = 0; i < MAX_CONTROLLER; i++) {
                        MicroManager::get<RomManager>().addData(nbLeds[i]);
                        MicroManager::get<RomManager>().addData(pins[i]);
                    }
                }
                
                inline void LedManager::loadFromROM() {
                    for (int i = 0; i < nbControllers.get(); i++) {
                        addController(nbLeds[i].get(), pins[i].get());
                    }
                    MicroManager::get<RomManager>().loadROM();
                    setup();
                }
            #endif

        }
    }
