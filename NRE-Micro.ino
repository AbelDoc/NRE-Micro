
    #include <Arduino.h>

    #define NRE_USE_LED     // Use LED SubModule

    #include "src/Header/NRE_Micro.hpp"     // Include all used sub modules

    using namespace NRE::Micro;

    //## Program Variables ##//

    //## Setup ##//
        void setup() {
            MicroManager::get<LedManager>().addController(29, 15);
            MicroManager::setup();
        }

    //## Main loop ##//
        void loop() {
            for (Led l : MicroManager::get<LedManager>().getController(0)) {
                l.update(RED);
            }
        }
