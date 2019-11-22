
    #include <Arduino.h>

    #define NRE_USE_LED      // Use LED SubModule
    #define NRE_USE_WEB      // Use Web SubModule
    #define NRE_USE_WIFI     // Use WiFi SubModule
    #define NRE_USE_ROM      // Use Rom SubModule

    #include "src/Header/NRE_Micro.hpp"     // Include all used sub modules

    using namespace NRE::Micro;

    //## Program Variables ##//
        ObservedData<String> ssid("");
        ObservedData<String> ssidPwd("");

    //## Setup ##//
        void setup() {
            //## Observed String need to be resized to an upper limit ##//
                ObservedData<String>::resizeString(ssid,    50);
                ObservedData<String>::resizeString(ssidPwd, 50);

            //## Configuring sub modules ##//
                MicroManager::get<RomManager>().addData(ssid);
                MicroManager::get<RomManager>().addData(ssidPwd);
                
                //auto id1 = MicroManager::get<LedManager>().addController(24, 15);
                
                static auto id1 = MicroManager::get<LedManager>().addController(40, 15);
                static auto id2 = MicroManager::get<LedManager>().addController(25, 4);

                MicroManager::get<RomManager>().setOnLoad([&]() {
                    if (strlen(ssid->c_str()) != 0) {
                        MicroManager::get<WiFiManager>().addKnownNetwork(ssid, ssidPwd);
                    }
                    MicroManager::get<WiFiManager>().setAPOnSetup("MyLight", "NRESoftware", false);
                });

                MicroManager::get<WebManager>().addHandle([&](ESP8266WebServer& server) {
                    if (server.args() > 0) {
                        if (server.args() >= 4 && server.argName(0) == "color") {
                            int color = server.arg(0).toInt();
                            if (color < 6) {
                                MicroManager::get<LedManager>().getController(id1).getColor(color)     = Color(server.arg(1).toInt(), server.arg(2).toInt(), server.arg(3).toInt());
                            } else {
                                MicroManager::get<LedManager>().getController(id2).getColor(color - 6) = Color(server.arg(1).toInt(), server.arg(2).toInt(), server.arg(3).toInt());
                            }
                            server.send(200, "text/html", server.arg(1) + "-" + server.arg(2) + "-" + server.arg(3));
                        } else {
                            if (server.args() == 1 && server.argName(0) == "speed1") {
                                MicroManager::get<LedManager>().getController(id1).getSpeed() = static_cast <unsigned int> (server.arg(0).toInt());
                                server.send(200, "text/html", "OK");
                            }
                            if (server.args() == 1 && server.argName(0) == "speed2") {
                                MicroManager::get<LedManager>().getController(id2).getSpeed() = static_cast <unsigned int> (server.arg(0).toInt());
                                server.send(200, "text/html", "OK");
                            }
                            if (server.args() == 1 && server.argName(0) == "effect1") {
                                MicroManager::get<LedManager>().getController(id1).getEffect() = static_cast <unsigned char> (server.arg(0).toInt());
                                server.send(200, "text/html", "OK");
                            }
                            if (server.args() == 1 && server.argName(0) == "effect2") {
                                MicroManager::get<LedManager>().getController(id2).getEffect() = static_cast <unsigned char> (server.arg(0).toInt());
                                server.send(200, "text/html", "OK");
                            }
                            if (server.args() == 1 && server.argName(0) == "info") {
                                server.send(200, "text/html", ssid.get() + "\n" +
                                                              ssidPwd.get() + "\n" +
                                                              String(2) + "\n" +
                                                              MicroManager::get<LedManager>().getController(id1).getInfo() + "\n" +
                                                              MicroManager::get<LedManager>().getController(id1).getInfo());
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
                            if (server.args() == 1 && server.argName(0) == "debug" && server.arg(0) == "delta") {
                                server.send(200, "text/html", String(MicroManager::getDelta()));
                            }
                            if (server.args() == 1 && server.argName(0) == "debug" && server.arg(0) == "time") {
                                server.send(200, "text/html", String(millis()));
                            }
                            if (server.args() == 1 && server.argName(0) == "debug" && server.arg(0) == "sleep") {
                                server.send(200, "text/html", String(MicroManager::get<LedManager>().getController(id1).getTimer()) + "\n" +
                                                              String(MicroManager::get<LedManager>().getController(id2).getTimer()));
                            }
                            if (server.args() == 1 && server.argName(0) == "auth") {
                                server.send(200, "text/html", "OK");
                            }
                        }
                    }
                });
            //## Launching sub modules ##//
                MicroManager::setup();
        }

    //## Main loop ##//
        void loop() {
            MicroManager::loop();
        }
