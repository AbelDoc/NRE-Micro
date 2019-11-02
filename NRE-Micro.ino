
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

        ObservedData<Color> color6(RED);
        ObservedData<Color> color7(YELLOW);
        ObservedData<Color> color8(GREEN);
        ObservedData<Color> color9(CYAN);
        ObservedData<Color> color10(BLUE);
        ObservedData<Color> color11(MAGENTA);

        ObservedData<unsigned int> speed1(100);
        ObservedData<unsigned int> speed2(100);

        ObservedData<String> ssid("");
        ObservedData<String> ssidPwd("");

        ObservedData<unsigned char> effect1(6);
        ObservedData<unsigned char> effect2(6);

    //## Setup ##//
        void setup() {
            //## Observed String need to be resized to an upper limit ##//
                ObservedData<String>::resizeString(ssid,    50);
                ObservedData<String>::resizeString(ssidPwd, 50);

            //## Configuring sub modules ##//
                //auto id1 = MicroManager::get<LedManager>().addController(24, 15);
                auto id1 = MicroManager::get<LedManager>().addController(40, 15);
                auto id2 = MicroManager::get<LedManager>().addController(25, 4);

                MicroManager::get<RomManager>().addData(ssid);
                MicroManager::get<RomManager>().addData(ssidPwd);
                MicroManager::get<RomManager>().addData(speed1);
                MicroManager::get<RomManager>().addData(color0);
                MicroManager::get<RomManager>().addData(color1);
                MicroManager::get<RomManager>().addData(color2);
                MicroManager::get<RomManager>().addData(color3);
                MicroManager::get<RomManager>().addData(color4);
                MicroManager::get<RomManager>().addData(color5);
                MicroManager::get<RomManager>().addData(effect1);
                MicroManager::get<RomManager>().addData(speed2);
                MicroManager::get<RomManager>().addData(color6);
                MicroManager::get<RomManager>().addData(color7);
                MicroManager::get<RomManager>().addData(color8);
                MicroManager::get<RomManager>().addData(color9);
                MicroManager::get<RomManager>().addData(color10);
                MicroManager::get<RomManager>().addData(color11);
                MicroManager::get<RomManager>().addData(effect2);

                MicroManager::get<RomManager>().setOnLoad([&]() {
                    if (strlen(ssid->c_str()) != 0) {
                        MicroManager::get<WiFiManager>().addKnownNetwork(ssid, ssidPwd);
                    }
                    MicroManager::get<WiFiManager>().setAPOnSetup("MyLight", "NRESoftware", false);
                });

                effect1.setHandle([&](unsigned char& data) {
                    switch (data) {
                        case (0) : {
                            MicroManager::get<LedManager>().getController(0).setEffect(new FixEffect(color0));
                            break;
                        }
                        case (1) : {
                            MicroManager::get<LedManager>().getController(0).setEffect(new RotateEffect(color0, speed1));
                            break;
                        }
                        case (2) : {
                            MicroManager::get<LedManager>().getController(0).setEffect(new RotateFixEffect(color0, speed1));
                            break;
                        }
                        case (3) : {
                            MicroManager::get<LedManager>().getController(0).setEffect(new RotateFixEffect(color0, speed1, true, true));
                            break;
                        }
                        case (4) : {
                            MicroManager::get<LedManager>().getController(0).setEffect(new WaveEffect(color0, speed1));
                            break;
                        }
                        case (5) : {
                            MicroManager::get<LedManager>().getController(0).setEffect(new RotateLinearEffect(color0, speed1));
                            break;
                        }
                        case (6) : {
                            MicroManager::get<LedManager>().getController(0).setEffect(new RotateLinearGradiantEffect(color0, color1, speed1));
                            break;
                        }
                        case (7) : {
                            MicroManager::get<LedManager>().getController(0).setEffect(new RotateLinearRainbowEffect(color0, color1, color2, color3, color4, color5, speed1));
                            break;
                        }
                        default : {
                            MicroManager::get<LedManager>().getController(0).setEffect(new RotateLinearGradiantEffect(color0, color1, speed1));
                            break;
                        }
                    }
                });

                effect2.setHandle([&](unsigned char& data) {
                    switch (data) {
                        case (0) : {
                            MicroManager::get<LedManager>().getController(1).setEffect(new FixEffect(color6));
                            break;
                        }
                        case (1) : {
                            MicroManager::get<LedManager>().getController(1).setEffect(new RotateEffect(color6, speed2));
                            break;
                        }
                        case (2) : {
                            MicroManager::get<LedManager>().getController(1).setEffect(new RotateFixEffect(color6, speed2));
                            break;
                        }
                        case (3) : {
                            MicroManager::get<LedManager>().getController(1).setEffect(new RotateFixEffect(color6, speed2, true, true));
                            break;
                        }
                        case (4) : {
                            MicroManager::get<LedManager>().getController(1).setEffect(new WaveEffect(color6, speed2));
                            break;
                        }
                        case (5) : {
                            MicroManager::get<LedManager>().getController(1).setEffect(new RotateLinearEffect(color6, speed2));
                            break;
                        }
                        case (6) : {
                            MicroManager::get<LedManager>().getController(1).setEffect(new RotateLinearGradiantEffect(color6, color7, speed2));
                            break;
                        }
                        case (7) : {
                            MicroManager::get<LedManager>().getController(1).setEffect(new RotateLinearRainbowEffect(color6, color7, color8, color9, color10, color11, speed2));
                            break;
                        }
                        default : {
                            MicroManager::get<LedManager>().getController(1).setEffect(new RotateLinearGradiantEffect(color6, color7, speed2));
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
                                case (6) : {
                                    color6 = Color(server.arg(1).toInt(), server.arg(2).toInt(), server.arg(3).toInt());
                                    break;
                                }
                                case (7) : {
                                    color7 = Color(server.arg(1).toInt(), server.arg(2).toInt(), server.arg(3).toInt());
                                    break;
                                }
                                case (8) : {
                                    color8 = Color(server.arg(1).toInt(), server.arg(2).toInt(), server.arg(3).toInt());
                                    break;
                                }
                                case (9) : {
                                    color9 = Color(server.arg(1).toInt(), server.arg(2).toInt(), server.arg(3).toInt());
                                    break;
                                }
                                case (10) : {
                                    color10 = Color(server.arg(1).toInt(), server.arg(2).toInt(), server.arg(3).toInt());
                                    break;
                                }
                                case (11) : {
                                    color11 = Color(server.arg(1).toInt(), server.arg(2).toInt(), server.arg(3).toInt());
                                    break;
                                }
                            }
                            server.send(200, "text/html", server.arg(1) + "-" + server.arg(2) + "-" + server.arg(3));
                        } else {
                            if (server.args() == 1 && server.argName(0) == "speed1") {
                                speed1 = static_cast <unsigned int> (server.arg(0).toInt());
                                server.send(200, "text/html", "OK");
                            }
                            if (server.args() == 1 && server.argName(0) == "speed2") {
                                speed2 = static_cast <unsigned int> (server.arg(0).toInt());
                                server.send(200, "text/html", "OK");
                            }
                            if (server.args() == 1 && server.argName(0) == "effect1") {
                                effect1 = static_cast <unsigned char> (server.arg(0).toInt());
                                server.send(200, "text/html", "OK");
                            }
                            if (server.args() == 1 && server.argName(0) == "effect2") {
                                effect2 = static_cast <unsigned char> (server.arg(0).toInt());
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
                                                              String(color6->getR()) + "-" + String(color6->getG()) + "-" + String(color6->getB()) + "\n" +
                                                              String(color7->getR()) + "-" + String(color7->getG()) + "-" + String(color7->getB()) + "\n" +
                                                              String(color8->getR()) + "-" + String(color8->getG()) + "-" + String(color8->getB()) + "\n" +
                                                              String(color9->getR()) + "-" + String(color9->getG()) + "-" + String(color9->getB()) + "\n" +
                                                              String(color10->getR()) + "-" + String(color10->getG()) + "-" + String(color10->getB()) + "\n" +
                                                              String(color11->getR()) + "-" + String(color11->getG()) + "-" + String(color11->getB()) + "\n" +
                                                              String(effect1.get()) + "\n" +
                                                              String(effect2.get()) + "\n" +
                                                              String(speed1.get()) + "\n" +
                                                              String(speed2.get())
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
