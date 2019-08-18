
    /**
     * @file NRE_WiFiManagerInl.hpp
     * @brief Implementation of Micro's API's Object : WiFiManager
     * @author Louis ABEL
     * @date 17/08/2019
     * @copyright CC-BY-NC-SA
     */

    namespace NRE {
        namespace Micro {

            inline void WiFiManager::setAPOnSetup(String const& name, String const& pwd) {
                hotspot = {name, pwd};
                launchAPOnSetup = true;
            }

            inline void WiFiManager::addKnownNetwork(String const& name, String const& pwd) {
                networks.push_back({name, pwd});
            }

            inline void WiFiManager::setup() {
                connected = false;

                WiFi.scanNetworks(false, false);
                scannedNetworks = WiFi.scanComplete();

                int current = 0;
                while (!connected && current < networks.size()) {
                    int scanned = 0;
                    while (!connected && scanned < scannedNetworks) {
                        if (WiFi.SSID(scanned) == networks[current].name) {
                            WiFi.begin(networks[current].name, networks[current].pwd);
                            connected = true;
                        }
                        ++scanned;
                    }
                    ++current;
                }

                if (launchAPOnSetup) {
                    WiFi.softAP(hotspot.name, hotspot.pwd);
                }
            }

        }
    }
