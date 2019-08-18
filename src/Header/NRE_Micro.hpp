
    /**
     * @file NRE_Micro.hpp
     * @brief Declaration of Micro's API's Header
     * @author Louis ABEL
     * @date 17/08/2019
     * @copyright CC-BY-NC-SA
     */

    #pragma once

    #include "NRE_Core.hpp"

    #ifdef NRE_USE_LED
        #include "NRE_Led.hpp"
    #endif

    #ifdef NRE_USE_WIFI
        #include "NRE_WiFi.hpp"
    #endif

    #ifdef NRE_USE_WEB
        #include "NRE_Web.hpp"
    #endif
