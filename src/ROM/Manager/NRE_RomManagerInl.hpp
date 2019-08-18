
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
            }

            inline void RomManager::resetROM() {
                EEPROM[0] = RESET_SYMBOl;
                EEPROM.commit();
            }

            template <>
            inline void RomManager::write(String* data, int addr) {
                memcpy(reinterpret_cast <uint8_t*> (data), &EEPROM[addr], data->length());
                EEPROM.commit();
            }

            template <class T>
            inline void RomManager::write(T* data, int addr) {
                EEPROM.put<T>(addr, *data);
                EEPROM.commit();
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
