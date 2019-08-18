
    /**
     * @file NRE_Core.hpp
     * @brief Implmenetation of Micro's API's Core
     * @author Louis ABEL
     * @date 17/08/2019
     * @copyright CC-BY-NC-SA
     */

    namespace NRE {
        namespace Micro {

            template <class SubModule>
            inline void MicroManager::addModule(SubModule* module) {
                assert(modules.size() == SubModule::getId());
                modules.push_back(module);
            }

            template <class SubModule>
            inline SubModule& MicroManager::getModule() {
                return *(static_cast <SubModule*> (modules[SubModule::getId()]));
            }

            inline void MicroManager::setupModules() {
                for (AbstractModule* module : modules) {
                    module->setup();
                }
            }

            inline void MicroManager::loopModules() {
                for (AbstractModule* module : modules) {
                    module->loop();
                }
            }

            inline MicroManager& MicroManager::get() {
                static MicroManager instance;
                return instance;
            }

            template <class SubModule>
            inline void MicroManager::add(SubModule* module) {
                MicroManager::get().addModule(module);
            }

            template <class SubModule>
            inline SubModule& MicroManager::get() {
                return MicroManager::get().getModule<SubModule>();
            }

            inline void MicroManager::setup() {
                MicroManager::get().setupModules();
            }

            inline void MicroManager::loop() {
                MicroManager::get().loopModules();
            }

        }
    }
