
    #include <Arduino.h>

    #define NRE_USE_LED      // Use LED SubModule
    #define NRE_USE_WEB      // Use Web SubModule
    #define NRE_USE_WIFI     // Use WiFi SubModule
    #define NRE_USE_ROM      // Use Rom SubModule
    #define NRE_USE_TIME     // Use Time SubModule

    #include "Header/NRE_Micro.hpp"     // Include all used sub modules

    using namespace NRE::Micro;

    //## Program Variables ##//
        static float CHIP_VERSION = 1.0000;
    
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
                
                MicroManager::get<LedManager>().addData();  // Add nothing beyond LedManager ROM data
                
                MicroManager::get<RomManager>().setOnLoad([&]() {
                    MicroManager::get<LedManager>().loadFromROM();
                    if (strlen(ssid->c_str()) != 0) {
                        MicroManager::get<WiFiManager>().addKnownNetwork(ssid, ssidPwd);
                    }
                    MicroManager::get<WiFiManager>().setAPOnSetup("MyLight_" + String(ESP.getChipId(), 16), "NRESoftware", false);
                });

                MicroManager::get<WebManager>().addHandle([&](ESP8266WebServer& server) {
                    switch (server.args()) {
                        case (1) : {
                            String const& arg = server.argName(0);
                            if (arg == "controllers") {
                                MicroManager::get<LedManager>().setNbControllers(server.arg(0).toInt());
                                server.send(200, "text/html", "OK");
                                return;
                            }
                            if (arg == "restart") {
                                server.send(200, "text/html", "OK");
                                delay(1000);
                                ESP.restart();
                                return;
                            }
                            if (arg == "info") {
                                server.send(200, "text/html", String(CHIP_VERSION, 4) + "\n" +
                                                              ssid.get() + "\n" +
                                                              ssidPwd.get() + "\n" +
                                                              MicroManager::get<LedManager>().getInfo());
                                return;
                            }
                            if (arg == "auth") {
                                server.send(200, "text/html", "OK");
                                return;
                            }
                            String const& value = server.arg(0);
                            if (arg == "switch") {
                                MicroManager::get<LedManager>().setActive(static_cast <bool> (value.toInt()));
                                server.send(200, "text/html", "OK");
                                return;
                            }
                            if (arg == "debug" && value == "reset") {
                                MicroManager::get<RomManager>().resetROM();
                                server.send(200, "text/html", "OK");
                                return;
                            }
                            if (arg == "debug" && value == "clear") {
                                MicroManager::get<RomManager>().clearROM();
                                server.send(200, "text/html", "OK");
                                return;
                            }
                            if (arg == "debug" && value == "delta") {
                                server.send(200, "text/html", String(MicroManager::getDelta()));
                                return;
                            }
                            if (arg == "debug" && value == "time") {
                                server.send(200, "text/html", MicroManager::get<TimeManager>().getInfo());
                                return;
                            }
                            if (arg == "debug" && value == "controller") {
                                server.send(200, "text/html", String(MicroManager::get<LedManager>().getNbControllers()));
                                return;
                            }
                            break;
                        }
                        case (2) : {
                            String const& arg0 = server.argName(0);
                            String const& value0 = server.arg(0);
                            String const& value1 = server.arg(1);
                            if (arg0 == "speed") {
                                MicroManager::get<LedManager>().setSpeed(value0.toInt(), static_cast <long> (value1.toInt()));
                                server.send(200, "text/html", "OK");
                                return;
                            }
                            if (arg0 == "effect") {
                                MicroManager::get<LedManager>().setEffect(value0.toInt(), static_cast <unsigned char> (value1.toInt()));
                                server.send(200, "text/html", "OK");
                                return;
                            }
                            if (arg0 == "leds") {
                                MicroManager::get<LedManager>().setLeds(value0.toInt(), static_cast <LedId> (value1.toInt()));
                                server.send(200, "text/html", "OK");
                                return;
                            }
                            if (arg0 == "pin") {
                                MicroManager::get<LedManager>().setPin(value0.toInt(), static_cast <Pin> (value1.toInt()));
                                server.send(200, "text/html", "OK");
                                return;
                            }
                            String const& arg1 = server.argName(1);
                            if (arg0 == "ssid" && server.argName(1) == "pwd") {
                                ssid    = value0;
                                ssidPwd = value1;
                                server.send(200, "text/html", ssid.get() + "\n" + ssidPwd.get());
                                return;
                            }
                            break;
                        }
                        case (5) : {
                            String const& arg0 = server.argName(0);
                            String const& value0 = server.arg(0);
                            String const& value1 = server.arg(1);
                            String const& value2 = server.arg(2);
                            String const& value3 = server.arg(3);
                            String const& value4 = server.arg(4);
                            if (server.argName(0) == "color") {
                                MicroManager::get<LedManager>().setColor(value0.toInt(), value1.toInt(), Color(value2.toInt(), value3.toInt(), value4.toInt()));
                                server.send(200, "text/html", server.arg(2) + "-" + server.arg(3) + "-" + server.arg(4));
                                return;
                            }
                            break;
                        }
                        case (8) : {
                            String const& arg0 = server.argName(0);
                            String const& value1 = server.arg(1);
                            String const& value2 = server.arg(2);
                            String const& value3 = server.arg(3);
                            String const& value4 = server.arg(4);
                            String const& value5 = server.arg(5);
                            String const& value6 = server.arg(6);
                            String const& value7 = server.arg(7);
                            if (server.argName(0) == "time") {
                                MicroManager::get<TimeManager>().setDate(Date(value1.toInt(), value2.toInt() - 1, value3.toInt() - 1, value4.toInt(), value5.toInt(), value6.toInt(), value7.toInt()));
                                server.send(200, "text/html", "OK");
                                return;
                            }
                            break;
                        }
                        case (10) : {
                            String const& arg0 = server.argName(0);
                            String const& value0 = server.arg(0);
                            String const& value1 = server.arg(1);
                            String const& value2 = server.arg(2);
                            String const& value3 = server.arg(3);
                            String const& value4 = server.arg(4);
                            String const& value5 = server.arg(5);
                            String const& value6 = server.arg(6);
                            String const& value7 = server.arg(7);
                            String const& value8 = server.arg(8);
                            String const& value9 = server.arg(9);
                            if (server.argName(0) == "timer") {
                                Date stop = Date(value1.toInt(), value2.toInt() - 1, value3.toInt() - 1, value4.toInt(), value5.toInt(), value6.toInt(), value7.toInt());
                                Date start(stop);
                                start.add(value8.toInt(), HOURS);
                                MicroManager::get<LedManager>().getController(value0.toInt()).setModifier(new TimeModifier(stop, start, Date(0, 0, value9.toInt(), 0, 0, 0, 0)));
                                server.send(200, "text/html", "OK");
                                return;
                            }
                            break;
                        }
                    }
                    server.send(404, "text/plain", "404: Not found");
                });
                
            //## Launching sub modules ##//
                MicroManager::setup();
        }

    //## Main loop ##//
        void loop() {
            MicroManager::loop();
        }
