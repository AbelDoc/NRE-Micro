
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

            inline unsigned char LedManager::addController(LedId nb, Pin pin, neoPixelType type) {
                int id = controllers.size();
                controllers.push_back(new LedController(nb, pin, type));
                return id;
            }

            inline void LedManager::setup() {
                for (LedController* controller : controllers) {
                    controller->setup();
                }
            }

            inline void LedManager::loop() {
                for (LedController* controller : controllers) {
                    controller->loop();
                }
            }

        }
    }
