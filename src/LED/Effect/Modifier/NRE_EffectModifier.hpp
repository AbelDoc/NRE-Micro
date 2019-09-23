
    /**
     * @file NRE_EffectModifier.hpp
     * @brief Declaration of Micro's API's Object : EffectModifier
     * @author Louis ABEL
     * @date 18/08/2019
     * @copyright CC-BY-NC-SA
     */

     #pragma once

     #include "NRE_AbstractEffectModifier.hpp"

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

            template <class T>
            class EffectModifier : public AbstractEffectModifier {
                public :    // Methods
                    //## Constructor ##//
                        /**
                         * Construct the effect modifier
                         */
                        template <class ... Args>
                        EffectModifier(Args && ... args) : AbstractEffectModifier(new T(std::forward<Args>(args)...)) {
                        }
            };

        }
    }
