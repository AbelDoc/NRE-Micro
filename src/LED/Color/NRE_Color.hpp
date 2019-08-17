
    /**
     * @file NRE_Color.hpp
     * @brief Declaration of Micro's API's Object : Color
     * @author Louis ABEL
     * @date 17/08/2019
     * @copyright CC-BY-NC-SA
     */

     #pragma once
 #ifdef USE_LED

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
                        CompressedColor getColor() const;

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

                    //## Assigment Operator ##//
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
                    static ColorChannel extractR(CompressedColor color);
                    /**
                     * Extract the green channel from a color
                     * @param  color the color to process
                     * @return       the color green channel
                     */
                    static ColorChannel extractG(CompressedColor color);
                    /**
                     * Extract the blue channel from a color
                     * @param  color the color to process
                     * @return       the color blue channel
                     */
                    static ColorChannel extractB(CompressedColor color);
            };

        }
    }
#endif
