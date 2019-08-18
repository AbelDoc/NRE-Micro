
    /**
     * @file NRE_WebManagerInl.hpp
     * @brief Implementation of Micro's API's Object : WebManager
     * @author Louis ABEL
     * @date 17/08/2019
     * @copyright CC-BY-NC-SA
     */

    namespace NRE {
        namespace Micro {

            inline WebManager::WebManager() : server(NRE_WEB_SERVER_PORT) {
            }

            inline void WebManager::addHandle(ServerHandle handle) {
                handles.push_back(handle);
            }

            inline void WebManager::setup() {
                server.begin();
                updater.setup(&server);

                server.on("/", [&]() {
                    for (ServerHandle handle : handles) {
                        handle(server);
                    }
                });
            }

            inline void WebManager::loop() {
                server.handleClient();
            }

        }
    }
