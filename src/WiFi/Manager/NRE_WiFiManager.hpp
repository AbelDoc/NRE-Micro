 
    /**
     * @file NRE_WiFiManager.hpp
     * @brief Declaration of Micro's API's Object : WiFiManager
     * @author Louis ABEL
     * @date 17/08/2019
     * @copyright CC-BY-NC-SA
     */

     #pragma once

     #include "../../Core/Module/NRE_Module.hpp"

     #include <ESP8266WiFi.h>

     /**
     * @namespace NRE
     * @brief The NearlyRealEngine's global namespace
     */
    namespace NRE {

        /**
         * @namespace Micro
         * @brief Micro's API
         */
        namespace Micro {

            /**
             * @struct Network
             * @brief Represent a wifi network
             */
            struct Network {
                String name;    /**< The network name */
                String pwd;     /**< The network password */
            };

            /**
             * @class WiFiManager
             * @brief Manage the wifi module with client/server and connection
             */
            class WiFiManager : public Module<WiFiManager> {
                private :   // Fields
                    int scannedNetworks;            /**< The number of scanned networks */
                    std::vector<Network> networks;  /**< All known networks */
                    Network hotspot;                /**< The hotspot network */
                    bool connected;                 /**< Tell if the manager is connected */
                    bool launchAPOnSetup;           /**< Tell if we launch the soft AP on setup */
                    bool launchIfNetwork;           /**< Tell if we launch the AP mode with the STA mode */

                public :    // Methods
                    //## Constructor ##//
                        /**
                         * Construct the wifi module
                         */
                        WiFiManager();

                    //## Getter ##//
                        /**
                         * @return all known networks
                         */
                        std::vector<Network> const& getKnownNetworks() const;

                    //## Methods ##//
                        /**
                         * Set the hotspot network
                         * @param name   the hotspot name
                         * @param pwd    the hotspot password
                         * @param launch tell if we launch the AP mode even if the STA is activated
                         */
                        void setAPOnSetup(String const& name, String const& pwd, bool launch = true);
                        /**
                         * Add a known network, add them in priority order
                         * @param name the network name
                         * @param pwd  the network password
                         */
                        void addKnownNetwork(String const& name, String const& pwd);
                        /**
                         * Add a known network, add them in priority order
                         * @param name the network name
                         * @param pwd  the network password
                         */
                        void addKnownNetwork(char* name, char* pwd);
                        /**
                         * Add a known network, add them in priority order
                         * @param name the network name
                         * @param pwd  the network password
                         */
                        void addKnownNetwork(ObservedData<String> const& name, ObservedData<String> const& pwd);
                        /**
                         * Setup the module
                         */
                        void setup() override;
            };

            static WiFiManager _wiFiManager;
        }
    }

    #include "NRE_WiFiManagerInl.hpp"
