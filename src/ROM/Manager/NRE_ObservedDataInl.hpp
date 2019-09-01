
    /**
     * @file NRE_ObservedDataInl.hpp
     * @brief Implementation of Micro's API's Core Object : ObservedData
     * @author Louis ABEL
     * @date 18/08/2019
     * @copyright CC-BY-NC-SA
     */

    namespace NRE {
        namespace Micro {

            template <class T>
            inline ObservedData<T>::ObservedData() : data() {
            }

            template <class T>
            template <class ... Args>
            inline ObservedData<T>::ObservedData(Args && ... args) : data(std::forward<Args>(args)...) {
            }

            template <class T>
            inline uint32_t ObservedData<T>::getSize() const {
                return sizeof(T);
            }

            template <>
            inline uint32_t ObservedData<String>::getSize() const {
                return data.length();
            }

            template <class T>
            inline T& ObservedData<T>::get() {
                return data;
            }

            template <class T>
            inline T const& ObservedData<T>::get() const {
                return data;
            }

            template <class T>
            inline void ObservedData<T>::setHandle(std::function<void(T&)> h) {
                handle = h;
            }

            template <class T>
            inline void ObservedData<T>::update() {
                #ifdef  NRE_USE_ROM
                    if (ptr != 0) {
                        MicroManager::get<RomManager>().write<T>(data, ptr);
                    }
                #endif
                if (handle) {
                    handle(data);
                }
            }

            #ifdef NRE_USE_ROM
                template <class T>
                inline void ObservedData<T>::read(void* ptr) {
                    memcpy(reinterpret_cast <char*> (&data), ptr, getSize());
                }

                template <>
                inline void ObservedData<String>::read(void* ptr) {
                    char* buf = static_cast <char*> (ptr);
                    String tmp;
                    tmp.reserve(getSize());

                    for (uint32_t i = 0; i < getSize(); ++i) {
                        tmp += buf[i];
                    }
                    data = tmp;
                }

            #endif

            template <class T>
            inline ObservedData<T>& ObservedData<T>::operator=(T const& d) {
                if (&data != &d) {
                    data = d;
                    update();
                }
                return *this;
            }

            template <class T>
            inline ObservedData<T>& ObservedData<T>::operator=(T && d) {
                if (&data != &d) {
                    data = std::move(d);
                    update();
                }
                return *this;
            }

        }
    }
