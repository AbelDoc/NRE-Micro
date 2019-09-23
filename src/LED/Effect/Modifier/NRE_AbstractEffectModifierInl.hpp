
    /**
     * @file NRE_AbstractEffectModifier.tpp
     * @brief Implementation of Micro's API's Object : AbstractEffectModifier
     * @author Louis ABEL
     * @date 18/08/2019
     * @copyright CC-BY-NC-SA
     */

    namespace NRE {
        namespace Micro {

            inline AbstractEffectModifier::AbstractEffectModifier(AbstractEffectModifier && m) : modified(m.modified) {
                m.modified = nullptr;
            }

            inline AbstractEffectModifier::~AbstractEffectModifier() {
                delete modified;
            }

            inline void AbstractEffectModifier::start(LedController& controller) {
                modified->start(controller);
            }

            inline void AbstractEffectModifier::stop(LedController& controller) {
                modified->stop(controller);
            }

            inline void AbstractEffectModifier::kill(LedController& controller) {
                stop(controller);
                delete modified;
                modified = nullptr;
            }

            inline AbstractEffectModifier& AbstractEffectModifier::operator=(AbstractEffectModifier && m) {
                if (this != &m) {
                    modified = m.modified;
                    m.modified = nullptr;
                }
                return *this;
            }


        }
    }
