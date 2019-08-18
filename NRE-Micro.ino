
    #include <Arduino.h>

    #define NRE_USE_LED      // Use LED SubModule
    #define NRE_USE_WEB      // Use Web SubModule
    #define NRE_USE_WIFI     // Use WiFi SubModule

    #include "src/Header/NRE_Micro.hpp"     // Include all used sub modules

    using namespace NRE::Micro;

    //## Program Variables ##//

    //## Setup ##//
        void setup() {
            MicroManager::get<LedManager>().addController(29, 15);

            MicroManager::get<WiFiManager>().addKnownNetwork("freebox_AB", "mireilleetdidier");
            MicroManager::get<WiFiManager>().setAPOnSetup("pomme", "mireilleabel");

            MicroManager::get<WebManager>().addHandle([&](ESP8266WebServer& server) {
                if (server.args() > 0) {
                    if (server.args() >= 4 && server.argName(0) == "color") {
                        MicroManager::get<LedManager>().getController(0).setColor({
                            server.arg(1).toInt(),  // r
                            server.arg(2).toInt(),  // g
                            server.arg(3).toInt()   // b
                        });
                    }
                    server.send(200, "text/html", server.arg(0));
                }
            });

            MicroManager::setup();
        }

    //## Main loop ##//
        void loop() {
            MicroManager::loop();
        }
