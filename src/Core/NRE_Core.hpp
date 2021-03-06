
    /**
     * @file Core/NRE_Core.hpp
     * @brief Declaration of Micro's API's Core
     * @author Louis ABEL
     * @date 17/08/2019
     * @copyright CC-BY-NC-SA
     */

    #pragma once

    #include <Arduino.h>

    #include "Module/NRE_AbstractModule.hpp"

    #include <vector>
    #include <cassert>

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

            typedef uint16_t Pin;

            /**
             * @class MicroManager
             * @brief Manage all modules in the framework, allowing the user simple utilisation of ESP8266 library and functionnality
             */
            class MicroManager {
                private :   // Fields
                    std::vector<AbstractModule*> modules;    /**< The framework active modules */
                    unsigned long lastTime;                  /**< The last frame time */

                public :    // Methods
                    //## Constructor ##//
                        /**
                         * Construct the micro manager
                         */
                        MicroManager() = default;

                    //## Copy Constructor ##//
                        /**
                         * Copy forbidden
                         * @param mng the manager to copy
                         */
                        MicroManager(MicroManager const& mng) = delete;

                    //## Move Constructor ##//
                        /**
                         * Move forbidden
                         * @param mng the manager to move
                         */
                        MicroManager(MicroManager && mng) = delete;

                    //## Deconstructor ##//
                        /**
                         * MicroManager Deconstructor
                         */
                        ~MicroManager() = default;
    
                    //## Getter ##//
                        /**
                         * @return the current delta time
                         */
                        long getCurrentDelta() const;

                    //## Methods ##//
                        /**
                         * Add a sub module to the core
                         * @param module the module to add
                         */
                        template <class SubModule>
                        void addModule(SubModule* module);
                        /**
                         * @return a manager module
                         */
                        template <class SubModule>
                        SubModule& getModule();
                        /**
                         * Setup all modules
                         */
                        void setupModules();
                        /**
                         * Handle the loop for all modules
                         */
                        void loopModules();
                        
                    //## Assignment Operator ##//
                        /**
                         * Copy assign forbidden
                         * @param mng the manager to copy
                         * @return the reference of himself
                         */
                        MicroManager& operator=(MicroManager const& mng) = delete;
                        /**
                         * Move assign forbidden
                         * @param mng the manager to move
                         * @return the reference of himself
                         */
                        MicroManager& operator=(MicroManager && mng) = delete;


                public :   // Static

                    /**
                     * @return the micro manager instance
                     */
                    static MicroManager& get();
                    /**
                     * Add a sub module to the core
                     * @param module the module to add
                     */
                    template <class SubModule>
                    static void add(SubModule* module);
                    /**
                     * @return a manager module
                     */
                    template <class SubModule>
                    static SubModule& get();
                    /**
                     * Setup all modules
                     */
                    static void setup();
                    /**
                     * Handle the loop for all modules
                     */
                    static void loop();
                    /**
                     * @return the current delta time
                     */
                    static long getDelta();
            };

        }
    }

    #include "NRE_CoreInl.hpp"
