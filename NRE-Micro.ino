
    #include <Arduino.h>

    #define NRE_USE_LED      // Use LED SubModule
    #define NRE_USE_WEB      // Use Web SubModule
    #define NRE_USE_WIFI     // Use WiFi SubModule
    #define NRE_USE_ROM      // Use Rom SubModule

    #include "src/Header/NRE_Micro.hpp"     // Include all used sub modules

    using namespace NRE::Micro;

    //## Program Variables ##//
        ObservedData<Color> color0(RED);
        ObservedData<Color> color1(YELLOW);
        ObservedData<Color> color2(GREEN);
        ObservedData<Color> color3(CYAN);
        ObservedData<Color> color4(BLUE);
        ObservedData<Color> color5(MAGENTA);

        ObservedData<unsigned int> speed(100);

        ObservedData<String> ssid("");
        ObservedData<String> ssidPwd("");

        ObservedData<unsigned char> effect(6);

    //## Setup ##//
        void setup() {
            //## Observed String need to be resized to an upper limit ##//
                ObservedData<String>::resizeString(ssid,    50);
                ObservedData<String>::resizeString(ssidPwd, 50);

            //## Configuring sub modules ##//
                //auto id = MicroManager::get<LedManager>().addController(24, 15);
                auto id = MicroManager::get<LedManager>().addController(10, 15);
                MicroManager::get<RomManager>().addData(color0);
                MicroManager::get<RomManager>().addData(color1);
                MicroManager::get<RomManager>().addData(ssid);
                MicroManager::get<RomManager>().addData(ssidPwd);
                MicroManager::get<RomManager>().addData(effect);
                MicroManager::get<RomManager>().addData(color2);
                MicroManager::get<RomManager>().addData(color3);
                MicroManager::get<RomManager>().addData(color4);
                MicroManager::get<RomManager>().addData(color5);
                MicroManager::get<RomManager>().addData(speed);

                MicroManager::get<RomManager>().setOnLoad([&]() {
                    if (strlen(ssid->c_str()) != 0) {
                        MicroManager::get<WiFiManager>().addKnownNetwork(ssid, ssidPwd);
                    }
                    MicroManager::get<WiFiManager>().setAPOnSetup("MyLight", "NRESoftware", false);
                });

                effect.setHandle([&](unsigned char& data) {
                    switch (data) {
                        case (0) : {
                            MicroManager::get<LedManager>().getController(id).setEffect(new FixEffect(color0));
                            break;
                        }
                        case (1) : {
                            MicroManager::get<LedManager>().getController(id).setEffect(new RotateEffect(color0, speed));
                            break;
                        }
                        case (2) : {
                            MicroManager::get<LedManager>().getController(id).setEffect(new RotateFixEffect(color0, speed));
                            break;
                        }
                        case (3) : {
                            MicroManager::get<LedManager>().getController(id).setEffect(new RotateFixEffect(color0, speed, true, true));
                            break;
                        }
                        case (4) : {
                            MicroManager::get<LedManager>().getController(id).setEffect(new WaveEffect(color0, speed));
                            break;
                        }
                        case (5) : {
                            MicroManager::get<LedManager>().getController(id).setEffect(new RotateLinearEffect(color0, speed));
                            break;
                        }
                        case (6) : {
                            MicroManager::get<LedManager>().getController(id).setEffect(new RotateLinearGradiantEffect(color0, color1, speed));
                            break;
                        }
                        case (7) : {
                            MicroManager::get<LedManager>().getController(id).setEffect(new RotateLinearRainbowEffect(color0, color1, color2, color3, color4, color5, speed));
                            break;
                        }
                        default : {
                            MicroManager::get<LedManager>().getController(id).setEffect(new RotateLinearGradiantEffect(color0, color1, speed));
                            break;
                        }
                    }
                });

                MicroManager::get<WebManager>().addHandle([&](ESP8266WebServer& server) {
                    if (server.args() > 0) {
                        if (server.args() >= 4 && server.argName(0) == "color") {
                            switch (server.arg(0).toInt()) {
                                case (0) : {
                                    color0 = Color(server.arg(1).toInt(), server.arg(2).toInt(), server.arg(3).toInt());
                                    break;
                                }
                                case (1) : {
                                    color1 = Color(server.arg(1).toInt(), server.arg(2).toInt(), server.arg(3).toInt());
                                    break;
                                }
                                case (2) : {
                                    color2 = Color(server.arg(1).toInt(), server.arg(2).toInt(), server.arg(3).toInt());
                                    break;
                                }
                                case (3) : {
                                    color3 = Color(server.arg(1).toInt(), server.arg(2).toInt(), server.arg(3).toInt());
                                    break;
                                }
                                case (4) : {
                                    color4 = Color(server.arg(1).toInt(), server.arg(2).toInt(), server.arg(3).toInt());
                                    break;
                                }
                                case (5) : {
                                    color5 = Color(server.arg(1).toInt(), server.arg(2).toInt(), server.arg(3).toInt());
                                    break;
                                }
                            }
                            server.send(200, "text/html", server.arg(1) + "-" + server.arg(2) + "-" + server.arg(3));
                        } else {
                            if (server.args() == 1 && server.argName(0) == "speed") {
                                speed = static_cast <unsigned int> (server.arg(0).toInt());
                                server.send(200, "text/html", "OK");
                            }
                            if (server.args() == 1 && server.argName(0) == "effect") {
                                effect = static_cast <unsigned char> (server.arg(0).toInt());
                                server.send(200, "text/html", "OK");
                            }
                            if (server.args() == 1 && server.argName(0) == "info") {
                                server.send(200, "text/html", ssid.get() + "\n" +
                                                              ssidPwd.get() + "\n" +
                                                              String(color0->getR()) + "-" + String(color0->getG()) + "-" + String(color0->getB()) + "\n" +
                                                              String(color1->getR()) + "-" + String(color1->getG()) + "-" + String(color1->getB()) + "\n" +
                                                              String(color2->getR()) + "-" + String(color2->getG()) + "-" + String(color2->getB()) + "\n" +
                                                              String(color3->getR()) + "-" + String(color3->getG()) + "-" + String(color3->getB()) + "\n" +
                                                              String(color4->getR()) + "-" + String(color4->getG()) + "-" + String(color4->getB()) + "\n" +
                                                              String(color5->getR()) + "-" + String(color5->getG()) + "-" + String(color5->getB()) + "\n" +
                                                              String(effect.get()) + "\n" +
                                                              String(speed.get())
                                                              );
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
        }

    //## Main loop ##//
        void loop() {
            MicroManager::loop();
        }
