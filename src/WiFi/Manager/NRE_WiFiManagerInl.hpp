
    /**
     * @file NRE_WiFiManagerInl.hpp
     * @brief Implementation of Micro's API's Object : WiFiManager
     * @author Louis ABEL
     * @date 17/08/2019
     * @copyright CC-BY-NC-SA
     */

    namespace NRE {
        namespace Micro {

            inline WiFiManager::WiFiManager() : launchAPOnSetup(false), launchIfNetwork(false) {
            }

            inline std::vector<Network> const& WiFiManager::getKnownNetworks() const {
                return networks;
            }

            inline void WiFiManager::setAPOnSetup(String const& name, String const& pwd, bool launch) {
                hotspot = {name, pwd};
                launchAPOnSetup = true;
                launchIfNetwork = launch;
            }

            inline void WiFiManager::addKnownNetwork(String const& name, String const& pwd) {
                String nameValid, pwdValid;
                std::size_t nameLength, pwdLength;
                nameLength = strlen(name.c_str());
                pwdLength  = strlen(pwd.c_str());

                nameValid.reserve(nameLength);
                pwdValid.reserve(pwdLength);

                for (std::size_t i = 0; i < nameLength; i++) {
                    nameValid += name[i];
                }
                for (std::size_t i = 0; i < pwdLength; i++) {
                    pwdValid += pwd[i];
                }
                networks.push_back({nameValid, pwdValid});
            }

            inline void WiFiManager::addKnownNetwork(char* name, char* pwd) {
                networks.push_back({String(name), String(pwd)});
            }

            inline void WiFiManager::addKnownNetwork(ObservedData<String> const& name, ObservedData<String> const& pwd) {
                addKnownNetwork(name.get(), pwd.get());
            }

            inline void WiFiManager::setup() {
                connected = false;

                Network good;

                WiFi.scanNetworks(false, false);
                scannedNetworks = WiFi.scanComplete();
                WiFi.mode(WIFI_STA_AP);

                int current = 0;
                while (!connected && current < networks.size()) {
                    int scanned = 0;
                    while (!connected && scanned < scannedNetworks) {
                        if (WiFi.SSID(scanned) == networks[current].name) {
                            good = networks[current];
                            connected = true;
                        }
                        ++scanned;
                    }
                    ++current;
                }

                if (connected) {
                    if (!launchIfNetwork) {
                        WiFi.mode(WIFI_STA);
                        WiFi.softAPdisconnect();
                    }
                    WiFi.begin(good.name, good.pwd);
                    if (launchIfNetwork) {
                        WiFi.softAP(hotspot.name, hotspot.pwd);
                    }
                } else {
                    if (launchAPOnSetup) {
                        WiFi.mode(WIFI_AP);
                        WiFi.softAP(hotspot.name, hotspot.pwd);
                    }
                }
            }

        }
    }
