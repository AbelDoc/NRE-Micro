
    /**
     * @file NRE_CoreInl.hpp
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
            
            inline long MicroManager::getCurrentDelta() const {
                return static_cast <long> (millis() - lastTime);
            }
            
            template <class SubModule>
            inline SubModule& MicroManager::getModule() {
                return *(static_cast <SubModule*> (modules[SubModule::getId()]));
            }

            inline void MicroManager::setupModules() {
                for (AbstractModule* module : modules) {
                    if (module->setupPrior()) {
                        module->setup();
                    }
                }
                for (AbstractModule* module : modules) {
                    if (!module->setupPrior()) {
                        module->setup();
                    }
                }
                lastTime = millis();
            }

            inline void MicroManager::loopModules() {
                long unsigned current = millis();
                long delta = current - lastTime;
                for (AbstractModule* module : modules) {
                    module->loop(delta);
                }
                lastTime = current;
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
            
            inline long MicroManager::getDelta() {
                MicroManager::get().getCurrentDelta();
            }

        }
    }
