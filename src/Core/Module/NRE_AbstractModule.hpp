
    /**
     * @file NRE_AbstractModule.hpp
     * @brief Declaration of Micro's API's Core Object : AbstractModule
     * @author Louis ABEL
     * @date 17/08/2019
     * @copyright CC-BY-NC-SA
     */

    #pragma once

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

            typedef unsigned char ModuleId;

            /**
             * @class AbstractModule
             * @brief Represent an abstract module used to active a certain part of the framework
             */
            class AbstractModule {
                public :   // Methods
                    //## Constructor ##//
                        /**
                         * Default constructor
                         */
                        AbstractModule() = default;

                    //## Deconstructor ##//
                        /**
                         * AbstractModule Deconstructor
                         */
                        virtual ~AbstractModule() = default;

                    //## Copy Constructor ##//
                        /**
                         * Copy forbidden
                         * @param m the module to copy
                         */
                        AbstractModule(AbstractModule const& m) = delete;

                    //## Move Constructor ##//
                        /**
                         * Move forbidden
                         * @param m the module to move
                         */
                        AbstractModule(AbstractModule && m) = delete;

                    //## Getter ##//
                        /**
                         * @return tell if the module has to be setup first, used for rom manager
                         */
                        virtual bool setupPrior() const {
                            return false;
                        }

                    //## Methods ##//
                        /**
                         * Setup the module
                         */
                        virtual void setup() {
                        }
                        /**
                         * The module loop
                         * @param delta the delta time from last frame
                         */
                        virtual void loop(long delta) {
                        }

                    //## Assignment Operator ##//
                        /**
                         * Copy assign forbidden
                         * @param m the module to copy
                         * @return the reference of himself
                         */
                        AbstractModule& operator=(AbstractModule const& m) = delete;
                        /**
                         * Move assign forbidden
                         * @param m the module to move
                         * @return the reference of himself
                         */
                        AbstractModule& operator=(AbstractModule && m) = delete;

                public :    // Static
                    static ModuleId counter;    /**< The modules id counter */
            };

        }
    }
