
    #include <Arduino.h>

    #define NRE_USE_LED      // Use LED SubModule
    #define NRE_USE_WEB      // Use Web SubModule
    #define NRE_USE_WIFI     // Use WiFi SubModule
    #define NRE_USE_ROM      // Use Rom SubModule

    #include "src/Header/NRE_Micro.hpp"     // Include all used sub modules

    using namespace NRE::Micro;

    //#include <EEPROM.h>

    //## Program Variables ##//
        ObservedData<Color> color0(BLUE);
        ObservedData<Color> color1(RED);

        ObservedData<String> ssid("");
        ObservedData<String> ssidPwd("");

    //## Setup ##//
        void setup() {
            //## Observed String need to be resized to an upper limit ##//
                ObservedData<String>::resizeString(ssid,    50);
                ObservedData<String>::resizeString(ssidPwd, 50);

            //## Configuring sub modules ##//
                auto id = MicroManager::get<LedManager>().addController(10, 15);
                MicroManager::get<RomManager>().addData(color0);
                MicroManager::get<RomManager>().addData(color1);
                MicroManager::get<RomManager>().addData(ssid);
                MicroManager::get<RomManager>().addData(ssidPwd);

                MicroManager::get<RomManager>().setOnLoad([&]() {
                    if (strlen(ssid->c_str()) != 0) {
                        MicroManager::get<WiFiManager>().addKnownNetwork(ssid, ssidPwd);
                    }
                    MicroManager::get<WiFiManager>().setAPOnSetup("MyLight", "NRESoftware", false);
                });

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
                            if (server.args() == 1 && server.argName(0) == "info") {
                                server.send(200, "text/html", ssid.get() + "\n" + ssidPwd.get());
                            }
                            if (server.args() == 2 && server.argName(0) == "ssid" && server.argName(1) == "pwd") {
                                ssid    = server.arg(0);
                                ssidPwd = server.arg(1);
                                server.send(200, "text/html", ssid.get() + "\n" + ssidPwd.get());
                                delay(2000);
                                ESP.restart();
                            }
                            if (server.args() == 1 && server.argName(0) == "debug" && server.arg(0) == "reset") {
                                MicroManager::get<RomManager>().resetROM();
                                server.send(200, "text/html", "OK");
                            }
                            if (server.args() == 1 && server.argName(0) == "debug" && server.arg(0) == "clear") {
                                MicroManager::get<RomManager>().clearROM();
                                server.send(200, "text/html", "OK");
                            }
                            if (server.args() == 1 && server.argName(0) == "auth") {
                                server.send(200, "text/html", "OK");
                            }
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
