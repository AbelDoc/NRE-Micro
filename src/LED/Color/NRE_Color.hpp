
    /**
     * @file NRE_Color.hpp
     * @brief Declaration of Micro's API's Object : Color
     * @author Louis ABEL
     * @date 17/08/2019
     * @copyright CC-BY-NC-SA
     */

     #pragma once
     #include <Arduino.h>

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

            typedef unsigned char ColorChannel;
            typedef uint32_t CompressedColor;

            /**
             * @class Color
             * @brief Represent a led Color
             */
            class Color {
                private :   // Fields
                    ColorChannel r;        /**< The red channel */
                    ColorChannel g;        /**< The green channel */
                    ColorChannel b;        /**< The blue channel */

                public :   // Methods
                    //## Constructor ##//
                        /**
                         * Default constructor
                         */
                        Color() = default;
                        /**
                         * Construct the color from all channel
                         * @param red   the red value
                         * @param green the green value
                         * @param blue  the blue value
                         */
                        constexpr Color(ColorChannel red, ColorChannel green, ColorChannel blue) : r(red), g(green), b(blue) {
                        }
                        /**
                         * Construct the color from a compressed one
                         * @param color the compressed color
                         */
                        constexpr Color(CompressedColor color) : r(extractR(color)), g(extractG(color)), b(extractB(color)) {
                        }

                    //## Copy Constructor ##//
                        /**
                         * Copy c into this
                         * @param c the color to copy
                         */
                        Color(Color const& c) = default;

                    //## Copy Constructor ##//
                        /**
                         * Move c into this
                         * @param c the color to move
                         */
                        Color(Color && c) = default;

                    //## Getter ##//
                        /**
                         * @return the red channel
                         */
                        ColorChannel getR() const;
                        /**
                         * @return the green channel
                         */
                        ColorChannel getG() const;
                        /**
                         * @return the blue channel
                         */
                        ColorChannel getB() const;
                        /**
                         * @return the compressed 32 bits color
                         */
                        constexpr CompressedColor getColor() const {
                            return (static_cast <CompressedColor> (r) << 16) | (static_cast <CompressedColor> (g) <<  8) | b;
                        }

                    //## Setter ##//
                        /**
                         * Set the red channel value
                         * @param red the new value
                         */
                        void setR(ColorChannel red);
                        /**
                         * Set the green channel value
                         * @param green the new value
                         */
                        void setG(ColorChannel green);
                        /**
                         * Set the blue channel value
                         * @param blue the new value
                         */
                        void setB(ColorChannel blue);

                    //## Assignment Operator ##//
                        /**
                         * Copy assign c into this
                         * @param c the color to copy
                         * @return the reference of himself
                         */
                        Color& operator=(Color const& c) = default;
                        /**
                         * Move assign c into this
                         * @param c the color to move
                         * @return the reference of himself
                         */
                        Color& operator=(Color && c) = default;

                public :    // Static
                    /**
                     * Extract the red channel from a color
                     * @param  color the color to process
                     * @return       the color red channel
                     */
                    static constexpr ColorChannel extractR(CompressedColor color) {
                        return static_cast <ColorChannel> ((color & 0xFFFF0000) >> 16);
                    }
                    /**
                     * Extract the red channel from a color
                     * @param  color the color to process
                     * @return       the color red channel
                     */
                    static constexpr ColorChannel extractR(Color const& color) {
                        return static_cast <ColorChannel> ((color.getColor() & 0xFFFF0000) >> 16);
                    }
                    /**
                     * Extract the green channel from a color
                     * @param  color the color to process
                     * @return       the color green channel
                     */
                    static constexpr ColorChannel extractG(CompressedColor color) {
                        return static_cast <ColorChannel> ((color & 0xFF00FF00) >> 8);
                    }
                    /**
                     * Extract the green channel from a color
                     * @param  color the color to process
                     * @return       the color green channel
                     */
                    static constexpr ColorChannel extractG(Color const& color) {
                        return static_cast <ColorChannel> ((color.getColor() & 0xFF00FF00) >> 8);
                    }
                    /**
                     * Extract the blue channel from a color
                     * @param  color the color to process
                     * @return       the color blue channel
                     */
                    static constexpr ColorChannel extractB(CompressedColor color) {
                        return static_cast <ColorChannel> (color & 0xFF0000FF);
                    }
                    /**
                     * Extract the blue channel from a color
                     * @param  color the color to process
                     * @return       the color blue channel
                     */
                    static constexpr ColorChannel extractB(Color const& color) {
                        return static_cast <ColorChannel> (color.getColor() & 0xFF0000FF);
                    }
            };

            static constexpr Color BLACK    = Color(  0,   0,   0);
            static constexpr Color RED      = Color(255,   0,   0);
            static constexpr Color GREEN    = Color(  0, 255,   0);
            static constexpr Color BLUE     = Color(  0,   0, 255);
            static constexpr Color MAGENTA  = Color(255,   0, 255);
            static constexpr Color YELLOW   = Color(255, 255,   0);
            static constexpr Color CYAN     = Color(  0, 255, 255);

        }
    }

    #include "NRE_ColorInl.hpp"
