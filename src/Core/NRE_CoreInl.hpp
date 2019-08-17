
    /**
     * @file NRE_Core.hpp
     * @brief Implmenetation of Micro's API's Core
     * @author Louis ABEL
     * @date 17/08/2019
     * @copyright CC-BY-NC-SA
     */

    namespace NRE {
        namespace Micro {

            inline MicroManager::MicroManager() : modules(new AbstractModule*[MAX_MODULES]) {
                for (unsigned char i = 0; i < MAX_MODULES; ++i) {
                    modules[i] = nullptr;
                }
            }

            template <class SubModule>
            inline void MicroManager::addModule(SubModule* module) {
                modules[SubModule::getId()] = module;
            }

            template <class SubModule>
            inline SubModule& MicroManager::getModule() {
                return *(static_cast <SubModule*> (modules[SubModule::getId()]));
            }

            inline void MicroManager::setupModules() {
                for (unsigned char i = 0; i < MAX_MODULES; ++i ) {
                    if (modules[i] != nullptr) {
                        modules[i]->setup();
                    }
                }
            }

            inline MicroManager::~MicroManager() {
                for (unsigned char i = 0; i < MAX_MODULES; ++i) {
                    delete modules[i];
                    modules[i] = nullptr;
                }
                delete[] modules;
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
                MicroManager::get().setup();
            }

        }
    }
