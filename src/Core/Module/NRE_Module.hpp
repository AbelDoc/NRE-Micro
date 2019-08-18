
    /**
     * @file NRE_Module.hpp
     * @brief Declaration of Micro's API's Core Object : Module
     * @author Louis ABEL
     * @date 17/08/2019
     * @copyright CC-BY-NC-SA
     */

    #pragma once

    #include "NRE_AbstractModule.hpp"
    #include "../NRE_Core.hpp"

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
             * @class Module
             * @brief Represent a module interface to create framework sub module
             */
            template <class SubModule>
            class Module : public AbstractModule {
                public :   // Methods
                    //## Constructor ##//
                        /**
                         * Construct the module and add it to the manager
                         */
                        Module() {
                            MicroManager::add(static_cast <SubModule*> (this));
                        }

                    //## Deconstructor ##//
                        /**
                         * Module Deconstructor
                         */
                        virtual ~Module() = default;

                public :    // Static
                    /**
                     * @return the module id
                     */
                    static ModuleId getId() {
                        static ModuleId id = counter++;
                        return id;
                    }
            };

        }
    }
