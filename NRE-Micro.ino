
    #include <Arduino.h>

    #define NRE_USE_LED      // Use LED SubModule
    #define NRE_USE_WEB      // Use Web SubModule
    #define NRE_USE_WIFI     // Use WiFi SubModule
    //#define NRE_USE_ROM      // Use Rom SubModule

    #include "src/Header/NRE_Micro.hpp"     // Include all used sub modules

    using namespace NRE::Micro;

    //## Program Variables ##//
        ObservedData<Color> color0(BLUE);
        ObservedData<Color> color1(RED);

    //## Setup ##//
        void setup() {
            //## Configuring sub modules ##//
                auto id = MicroManager::get<LedManager>().addController(10, 15);
                MicroManager::get<RomManager>().addData(color0);
                MicroManager::get<RomManager>().addData(color1);

                //MicroManager::get<WiFiManager>().addKnownNetwork("freebox_AB", "mireilleetdidier");
                MicroManager::get<WiFiManager>().addKnownNetwork("ABEL-ELITE-LAN", "AbelDocLan");
                //MicroManager::get<WiFiManager>().setAPOnSetup("pomme", "mireilleabel");

                MicroManager::get<WebManager>().addHandle([&](ESP8266WebServer& server) {
                    if (server.args() > 0) {
                        if (server.args() >= 4 && server.argName(0) == "color") {
                            if (server.arg(0).toInt() == 0) {
                                color0 = Color(server.arg(1).toInt(), server.arg(2).toInt(), server.arg(3).toInt());
                            } else {
                                color1 = Color(server.arg(1).toInt(), server.arg(2).toInt(), server.arg(3).toInt());
                            }
                            server.send(200, "text/html", server.arg(1) + "-" + server.arg(2) + "-" + server.arg(3));
                        } else {
                            if (server.args() == 1 && server.argName(0) == "effect") {
                                if (server.arg(0).toInt() == 0) {
                                    MicroManager::get<LedManager>().getController(id).setEffect(new FixEffect(color0));
                                }
                                if (server.arg(0).toInt() == 1) {
                                    MicroManager::get<LedManager>().getController(id).setEffect(new RotateEffect(color0, 10));
                                }
                                if (server.arg(0).toInt() == 2) {
                                    MicroManager::get<LedManager>().getController(id).setEffect(new RotateFixEffect(color0, 10));
                                }
                                if (server.arg(0).toInt() == 3) {
                                    MicroManager::get<LedManager>().getController(id).setEffect(new RotateFixEffect(color0, 10, true, true));
                                }
                                if (server.arg(0).toInt() == 4) {
                                    MicroManager::get<LedManager>().getController(id).setEffect(new WaveEffect(color0, 2));
                                }
                                if (server.arg(0).toInt() == 5) {
                                    MicroManager::get<LedManager>().getController(id).setEffect(new RotateLinearEffect(color0, 1));
                                }
                                if (server.arg(0).toInt() == 6) {
                                    MicroManager::get<LedManager>().getController(id).setEffect(new RotateLinearGradiantEffect(color0, color1, 1));
                                }
                                server.send(200, "text/html", "OK");
                            }
                            /*if (server.args() == 1 && server.argName(0) == "debug" && server.arg(0) == "color") {
                                server.send(200, "text/html", String(color.get().getColor()));
                            }
                            if (server.args() == 1 && server.argName(0) == "debug" && server.arg(0) == "rom") {
                                server.send(200, "text/html", String(MicroManager::get<RomManager>().read(0)));
                            }
                            if (server.args() == 1 && server.argName(0) == "debug" && server.arg(0) == "reset") {
                                MicroManager::get<RomManager>().resetROM();
                                server.send(200, "text/html", "OK");
                            }
                            if (server.args() == 1 && server.argName(0) == "debug" && server.arg(0) == "clear") {
                                MicroManager::get<RomManager>().clearROM();
                                server.send(200, "text/html", "OK");
                            }
                            if (server.args() == 1 && server.argName(0) == "debug" && server.arg(0) == "adr") {
                                server.send(200, "text/html", String(static_cast <int> (color0.ptr)) + "-" + String(static_cast <int> (color1.ptr)));
                            }*/
                        }
                    }
                });
            //## Launching sub modules ##//
                MicroManager::setup();

            //## Sub modules operationnals, can be used ##//
                MicroManager::get<LedManager>().getController(id).setEffect(new RotateLinearGradiantEffect(color0, color1, 1));
        }

    //## Main loop ##//
        void loop() {
            MicroManager::loop();
        }
