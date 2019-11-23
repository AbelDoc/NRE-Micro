
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
                
                MicroManager::get<LedManager>().addData();
                
                MicroManager::get<RomManager>().setOnLoad([&]() {
                    MicroManager::get<LedManager>().loadFromROM();
                    if (strlen(ssid->c_str()) != 0) {
                        MicroManager::get<WiFiManager>().addKnownNetwork(ssid, ssidPwd);
                    }
                    MicroManager::get<WiFiManager>().setAPOnSetup("MyLight", "NRESoftware", false);
                });

                MicroManager::get<WebManager>().addHandle([&](ESP8266WebServer& server) {
                    if (server.args() > 0) {
                        if (server.args() == 5 && server.argName(0) == "color") {
                            MicroManager::get<LedManager>().setColor(server.arg(0).toInt(), server.arg(1).toInt(), Color(server.arg(2).toInt(), server.arg(3).toInt(), server.arg(4).toInt()));
                            server.send(200, "text/html", server.arg(2) + "-" + server.arg(3) + "-" + server.arg(4));
                        } else {
                            if (server.args() == 2 && server.argName(0) == "speed") {
                                MicroManager::get<LedManager>().setSpeed(server.arg(0).toInt(), static_cast <long> (server.arg(1).toInt()));
                                server.send(200, "text/html", "OK");
                            }
                            if (server.args() == 2 && server.argName(0) == "effect") {
                                MicroManager::get<LedManager>().setEffect(server.arg(0).toInt(), static_cast <unsigned char> (server.arg(1).toInt()));
                                server.send(200, "text/html", "OK");
                            }
                            if (server.args() == 1 && server.argName(0) == "controllers") {
                                MicroManager::get<LedManager>().setNbControllers(server.arg(0).toInt());
                                server.send(200, "text/html", "OK");
                            }
                            if (server.args() == 2 && server.argName(0) == "leds") {
                                MicroManager::get<LedManager>().setLeds(server.arg(0).toInt(), static_cast <LedId> (server.arg(1).toInt()));
                                server.send(200, "text/html", "OK");
                            }
                            if (server.args() == 2 && server.argName(0) == "pin") {
                                MicroManager::get<LedManager>().setPin(server.arg(0).toInt(), static_cast <Pin> (server.arg(1).toInt()));
                                server.send(200, "text/html", "OK");
                            }
                            if (server.args() == 1 && server.argName(0) == "restart") {
                                server.send(200, "text/html", "OK");
                                delay(1000);
                                ESP.restart();
                            }
                            if (server.args() == 1 && server.argName(0) == "info") {
                                server.send(200, "text/html", ssid.get() + "\n" +
                                                              ssidPwd.get() + "\n" +
                                                              MicroManager::get<LedManager>().getInfo());
                            }
                            if (server.args() == 2 && server.argName(0) == "ssid" && server.argName(1) == "pwd") {
                                ssid    = server.arg(0);
                                ssidPwd = server.arg(1);
                                server.send(200, "text/html", ssid.get() + "\n" + ssidPwd.get());
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
                            if (server.args() == 1 && server.argName(0) == "debug" && server.arg(0) == "controller") {
                                server.send(200, "text/html", String(MicroManager::get<LedManager>().getNbControllers()));
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
