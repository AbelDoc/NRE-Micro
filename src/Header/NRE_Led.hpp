
    /**
     * @file Header/NRE_Led.hpp
     * @brief Declaration of Micro's API's LED Header
     * @author Louis ABEL
     * @date 17/08/2019
     * @copyright CC-BY-NC-SA
     */

    #pragma once

    #ifndef NRE_HEADER_GUARD
        #error Only include module by using NRE_USE_LED macro and import NRE_Micro header
    #endif

    #include "../LED/Manager/NRE_LedManager.hpp"

    #include "../LED/Color/NRE_Color.hpp"
    #include "../LED/Controller/NRE_LedController.hpp"

    #include "../LED/Effect/Core/NRE_FixEffect.hpp"
    #include "../LED/Effect/Core/NRE_WaveEffect.hpp"
    #include "../LED/Effect/Core/NRE_RotateEffect.hpp"
    #include "../LED/Effect/Core/NRE_RotateFixEffect.hpp"
    #include "../LED/Effect/Core/NRE_RotateLinearEffect.hpp"
    #include "../LED/Effect/Core/NRE_RotateLinearGradiantEffect.hpp"
    #include "../LED/Effect/Core/NRE_RotateLinearRainbowEffect.hpp"

    #include "../LED/Modifier/NRE_Modifier.hpp"

    #ifdef NRE_USE_TIME
        #include "../LED/Modifier/Core/NRE_TimeModifier.hpp"
    #endif
    
