
    /**
     * @file NRE_RomManagerInl.hpp
     * @brief Implementation of Micro's API's Object : RomManager
     * @author Louis ABEL
     * @date 18/08/2019
     * @copyright CC-BY-NC-SA
     */

    namespace NRE {
        namespace Micro {

            inline RomManager::RomManager() : currentPtr(1) {
            }

            inline bool RomManager::setupPrior() const {
                return true;
            }

            inline void RomManager::setOnLoad(std::function<void()> func) {
                onLoad = func;
            }

            template <class T>
            inline void RomManager::addData(ObservedData<T>& data) {
                objects.push_back(&data);
                data.ptr = currentPtr;
                currentPtr += data.getSize();
            }

            inline void RomManager::clearROM() {
                memset(&EEPROM[1], FILL_SYMBOL, MAX_ADDR - 1);
                EEPROM[0] = START_SYMBOL;
                EEPROM.commit();
            }

            inline void RomManager::loadROM() {
                for (AbstractData* obj : objects) {
                    obj->read(&EEPROM[obj->ptr]);
                }
                if (onLoad) {
                    onLoad();
                }
            }

            inline void RomManager::resetROM() {
                EEPROM[0] = RESET_SYMBOl;
                EEPROM.commit();
            }

            template <>
            inline void RomManager::write(String& data, int addr) {
                for (std::size_t i = 0; i < data.length(); i++) {
                    EEPROM[addr + i] = data[i];
                }
                EEPROM.commit();
            }

            template <class T>
            inline void RomManager::write(T& data, int addr) {
                EEPROM.put<T>(addr, data);
                EEPROM.commit();
            }

            inline unsigned char RomManager::read(int addr) {
                return EEPROM[addr];
            }

            inline void RomManager::setup() {
                EEPROM.begin(MAX_ADDR);
                if (EEPROM[0] == START_SYMBOL) {
                    loadROM();
                } else {
                    clearROM();
                }
            }

        }
    }
