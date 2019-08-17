
    /**
     * @file NRE_LedControllerInl.hpp
     * @brief Implementation of Micro's API's Object : LedMan
     * @author Louis ABEL
     * @date 17/08/2019
     * @copyright CC-BY-NC-SA
     */

     #pragma once

    namespace NRE {
        namespace Micro {

            inline LedManager::LedManager() : controllers(new LedController*[MAX_CONTROLLERS]), size(0) {
                for (unsigned char i = 0; i < MAX_CONTROLLERS; ++i) {
                    controllers[i] = nullptr;
                }
            }

            inline LedManager::~LedManager() {
                for (unsigned char i = 0; i < size; ++i) {
                    delete controllers[i];
                    controllers[i] = nullptr;
                }
                delete[] controllers;
                size = 0;
            }

            inline LedController& LedManager::getController(unsigned char id) {
                return *(controllers[id]);
            }

            inline unsigned char LedManager::addController(LedId nb, Pin pin, neoPixelType type) {
                int id = size;
                controllers[id] = new LedController(nb, pin, type);
                size++;
                return id;
            }

            inline void LedManager::setup() {
                for (unsigned char i = 0; i < size; ++i) {
                    controllers[i]->setup();
                }
            }

        }
    }
