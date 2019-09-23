
    /**
     * @file NRE_AbstractEffectModifier.hpp
     * @brief Declaration of Micro's API's Object : AbstractEffectModifier
     * @author Louis ABEL
     * @date 18/08/2019
     * @copyright CC-BY-NC-SA
     */

     #pragma once

     #include "../NRE_Effect.hpp"

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
             * @class AbstractEffectModifier
             * @brief Modify the behavior from a given effect
             */
            class AbstractEffectModifier {
                private :   // Fields
                    Effect* modified;

                public :    // Methods
                    //## Constructor ##//
                        /**
                         * Construct the modifier from the effect
                         * @param m the effect to modify
                         */
                        AbstractEffectModifier(Effect* m);

                    //## Copy Constructor ##//
                        /**
                         * Copy forbidden
                         * @param m the modifier to copy
                         */
                        AbstractEffectModifier(AbstractEffectModifier const& m) = delete;

                    //## Move Constructor ##//
                        /**
                         * Move m into this
                         * @param m the modifier to move
                         */
                        AbstractEffectModifier(AbstractEffectModifier && m);

                    //## Deconstructor ##//
                        /**
                         * AbstractEffectModifier Deconstructor
                         */
                        ~AbstractEffectModifier();

                    //## Methods ##//
                        /**
                         * Start the modified effect and apply the modifier start effect
                         * @param controller the master controller
                         */
                        virtual void start(LedController& controller);
                        /**
                         * Run the modified effect and apply the modifier
                         * @param controller the master controller
                         */
                        virtual void run(LedController& controller) = 0;
                        /**
                         * Stop the modified effect and apply the modifier stop effect
                         * @param controller the master controller
                         */
                        virtual void stop(LedController& controller);
                        /**
                         * Kill the current effect
                         * @param controller the master controller
                         */
                        virtual void kill(LedController& controller);

                    //## Assignment Operator ##//
                        /**
                         * Copy assign forbidden
                         * @param m the modifier to copy
                         * @return the reference of himself
                         */
                        AbstractEffectModifier& operator=(AbstractEffectModifier const& m) = delete;
                        /**
                         * Move assign of m into this
                         * @param m the modifier to move
                         * @return the reference of himself
                         */
                        AbstractEffectModifier& operator=(AbstractEffectModifier && m);

            };

        }
    }

    #include "NRE_AbstractEffectModifierInl.hpp"
