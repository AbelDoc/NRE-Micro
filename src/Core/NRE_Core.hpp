
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

            class MicroManager {
                private :   // Static
                    static constexpr unsigned char MAX_MODULES = 8;
                private :   // Fields
                    AbstractModule** modules;    /**< The framework active modules */

                public :    // Methods
                    //## Constructor ##//
                        /**
                         * Construct the micro manager
                         */
                        MicroManager();

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
                        ~MicroManager();

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
            };

        }
    }

    #include "NRE_CoreInl.hpp"
