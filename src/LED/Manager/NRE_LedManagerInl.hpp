
    /**
     * @file NRE_LedManagerInl.hpp
     * @brief Implementation of Micro's API's Object : LedManager
     * @author Louis ABEL
     * @date 17/08/2019
     * @copyright CC-BY-NC-SA
     */

    namespace NRE {
        namespace Micro {

            inline LedManager::~LedManager() {
                for (LedController* controller : controllers) {
                    delete controller;
                    controller = nullptr;
                }
            }

            inline LedController& LedManager::getController(unsigned char id) {
                return *(controllers[id]);
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
                for (LedController* controller : controllers) {
                    controller->loop(delta);
                }
            }

        }
    }
