
    /**
     * @file NRE_WebManager.hpp
     * @brief Declaration of Micro's API's Object : WebManager
     * @author Louis ABEL
     * @date 17/08/2019
     * @copyright CC-BY-NC-SA
     */

     #pragma once

     #include "../../Core/Module/NRE_Module.hpp"
     #include <ESP8266WebServer.h>
     #include <ESP8266HTTPUpdateServer.h>

     #include <vector>
     #include <functional>

     #ifndef NRE_USE_WIFI
        #error Web Server can't work without WiFi module, please use it.
     #endif

     #ifndef NRE_WEB_SERVER_PORT
        #define NRE_WEB_SERVER_PORT 80
     #endif

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

            typedef std::function<void(ESP8266WebServer& server)> ServerHandle;

            /**
             * @class WebManager
             * @brief Manage a web serveur and http updater
             */
            class WebManager : public Module<WebManager> {
                private :   // Fields
                    ESP8266HTTPUpdateServer updater;    /**< The HTTP Update server instance */
                    ESP8266WebServer server;            /**< The web server */
                    std::vector<ServerHandle> handles;  /**< All server handles */

                public :    // Methods
                    //## Constructor ##//
                        /**
                         * Construct the web module
                         */
                        WebManager();

                    //## Methods ##//
                        void addHandle(ServerHandle handler);
                        /**
                         * Setup the module
                         */
                        void setup() override;
                        /**
                         * The module loop
                         */
                        void loop() override;
            };

            static WebManager _webManager;
        }
    }

    #include "NRE_WebManagerInl.hpp"
