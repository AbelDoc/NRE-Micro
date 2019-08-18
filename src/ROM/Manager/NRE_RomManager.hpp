
    /**
     * @file NRE_RomManager.hpp
     * @brief Declaration of Micro's API's Object : RomManager
     * @author Louis ABEL
     * @date 18/08/2019
     * @copyright CC-BY-NC-SA
     */

     #pragma once

     #include "../../Core/Module/NRE_Module.hpp"

     #ifdef NRE_USE_ROM
        #include <EEPROM.h>
     #endif

     #include <vector>

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
             * @class AbstractData
             * @brief Represent an abstract data
             */
            class AbstractData {
                public :   // Fields
                    #ifdef NRE_USE_ROM
                        int ptr;  /**< The data address in rom */
                    #endif

                public :    // Methods
                    //## Constructor ##//
                        /**
                         * No default contructor
                         */
                        AbstractData() = default;

                    //## Methods ##//
                        #ifdef NRE_USE_ROM
                            /**
                             * Read the data from the EEPROM
                             * @param ptr the data pointer
                             */
                            virtual void read(void* ptr) = 0;
                        #endif
            };

            /**
             * @class ObservedData
             * @brief Represent an observed data by the internal ROM if used, allowing an automatic update between RAM and ROM
             */
            template <class T>
            class ObservedData : public AbstractData {
                private :   // Fields
                    T data;                         /**< The observed data */
                    std::function<void(T&)> handle; /**< The handle when the data is modified */

                public :    // Methods
                    //## Constructor ##//
                        /**
                         * No default contructor
                         */
                        ObservedData();
                        /**
                         * Create the data from the object address
                         * @param args the object construction arguments
                         */
                        template <class ... Args>
                        ObservedData(Args && ... args);

                    //## Copy Constructor ##//
                        /**
                         * Copy d into this
                         * @param d the data to copy
                         */
                        ObservedData(ObservedData const& d) = default;

                    //## Move Constructor ##//
                        /**
                         * Move d into this
                         * @param d the data to move
                         */
                        ObservedData(ObservedData && d) = default;

                    //## Deconstructor ##//
                        /**
                         * ObservedData Deconstructor
                         */
                        ~ObservedData() = default;

                    //## Getter ##//
                        /**
                         * @return the object size
                         */
                        uint32_t getSize() const;
                        /**
                         * @return the internal object
                         */
                        T& get();
                        /**
                         * @return the internal object
                         */
                        T const& get() const;

                    //## Setter ##//
                        /**
                         * Set the data handler
                         * @param h the new handler
                         */
                        void setHandle(std::function<void(T&)> h);

                    //## Methods ##//
                        /**
                         * Update internally the data
                         */
                        void update();
                        #ifdef NRE_USE_ROM
                            /**
                             * Read the data from the EEPROM
                             * @param ptr the data pointer
                             */
                            void read(void* ptr) override;
                        #endif

                    //## Assignment Operator ##//
                        /**
                         * Copy assign d into this
                         * @param d the data to copy
                         * @return the reference of himself
                         */
                        ObservedData& operator=(ObservedData const& d) = default;
                        /**
                         * Move assign d into this
                         * @param d the data to move
                         * @return the reference of himself
                         */
                        ObservedData& operator=(ObservedData && d) = default;
                        /**
                         * Assign the given data internally
                         * @param d the data to assign
                         * @return the reference of himself
                         */
                        ObservedData& operator=(T const& d);
                        /**
                         * Assign the given data internally
                         * @param d the data to assign
                         * @return the reference of himself
                         */
                        ObservedData& operator=(T && d);
            };

            #ifdef NRE_USE_ROM

                /**
                 * @class RomManager
                 * @brief Manage the internal rom with read/write access
                 */
                class RomManager : public Module<RomManager> {
                    private :   // Fields
                        std::vector<AbstractData*> objects;  /**< The managed objects */
                        int currentPtr;

                    public :    // Methods
                        //## Constructor ##//
                            /**
                             * Construct the wifi module
                             */
                            RomManager();

                        //## Methods ##//
                            /**
                             * Add a data to managed
                             * @param obj  the data to manage
                             */
                            template <class T>
                            void addData(ObservedData<T>& data);
                            /**
                             * Clear the rom
                             */
                            void clearROM();
                            /**
                             * Load all data from rom
                             */
                            void loadROM();
                            /**
                             * Reset the rom to an undetermined state, use it when you add or remove data managed in the rom in order to prevent wrong write/read, this will erase the ROM.
                             */
                            void resetROM();
                            /**
                             * Write data in the ROM
                             * @param data the data to write
                             */
                            template <class T>
                            void write(T* data, int addr);
                            /**
                             * Setup the module
                             */
                            void setup() override;

                    public :    // Static
                        static constexpr int MAX_ADDR = 4096;
                        static constexpr unsigned char FILL_SYMBOL  = 0x00;
                        static constexpr unsigned char START_SYMBOL = 0x4E; // N
                        static constexpr unsigned char RESET_SYMBOl = 0x52; // R
                };

                static RomManager _RomManager;

            #endif
        }
    }

    #ifdef NRE_USE_ROM
        #include "NRE_RomManagerInl.hpp"
    #endif

    #include "NRE_ObservedDataInl.hpp"
