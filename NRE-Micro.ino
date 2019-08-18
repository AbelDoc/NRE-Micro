
    #include <Arduino.h>

    #define NRE_USE_LED      // Use LED SubModule
    #define NRE_USE_WEB      // Use Web SubModule
    #define NRE_USE_WIFI     // Use WiFi SubModule
    #define NRE_USE_ROM      // Use Rom SubModule

    #include "src/Header/NRE_Micro.hpp"     // Include all used sub modules

    using namespace NRE::Micro;

    //## Program Variables ##//
        ObservedData<Color> color(RED);

    //## Setup ##//
        void setup() {
            //## Configuring sub modules ##//
                auto id = MicroManager::get<LedManager>().addController(29, 15);
                MicroManager::get<RomManager>().addData(color);

                color.setHandle([&](Color& data) {
                    MicroManager::get<LedManager>().getController(id).setColor(color);
                });

                MicroManager::get<WiFiManager>().addKnownNetwork("freebox_AB", "mireilleetdidier");
                MicroManager::get<WiFiManager>().setAPOnSetup("pomme", "mireilleabel");

                MicroManager::get<WebManager>().addHandle([&](ESP8266WebServer& server) {
                    if (server.args() > 0) {
                        if (server.args() >= 4 && server.argName(0) == "color") {
                            color = Color(server.arg(1).toInt(), server.arg(2).toInt(), server.arg(3).toInt());
                        }
                        server.send(200, "text/html", server.arg(0));
                    }
                });
            //## Launching sub modules ##//
                MicroManager::setup();

            //## Sub modules operationnals, can be used ##//
                MicroManager::get<LedManager>().getController(id).setEffect(new FixEffect(color));
        }

    //## Main loop ##//
        void loop() {
            MicroManager::loop();
        }
