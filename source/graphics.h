#ifndef __ALOBE__GRAPHICS__
#define __ALOBE__GRAPHICS__

#include <string>
#include <memory>
#include <vector>

#include "graphicsWindow.h"

using namespace std;

/**
 * <<Abstract>> Graphics
 *
 * List of graphic commands that should be implemented for a given library
 */
class Graphics
{
    public:
        Graphics(shared_ptr<GraphicsWindow> graphicsWindow);
        virtual ~Graphics() = default;
        virtual unique_ptr<Graphics> clone() = 0;
        shared_ptr<GraphicsWindow> getGraphicsWindow();     // Getter for the graphics window
        unsigned long getXOffset();                         // Getter for the x offset
        unsigned long getYOffset();                         // Getter for the y offset
        void setXOffset(unsigned long xOffset);             // Setter for the x offset
        void setYOffset(unsigned long yOffset);             // Setter for the y offset
        long long getXSpeed();                              // Getter for the x speed
        long long getYSpeed();                              // Getter for the y speed
        unsigned long getWidth();                           // Getter for the width
        unsigned long getHeight();                          // Getter for the height
        void setWidth(unsigned long width);                 // Setter for the width
        void setHeight(unsigned long height);               // Setter for the height
        void setColor(unsigned long color);                 // Setter for the color
        vector<unsigned long> getRGB();                     // Getter for the color in RGB format
        unsigned long intervalToCoordinate(
            unsigned long minimum,
            unsigned long length,
            unsigned long total,
            unsigned long position
        ) const;                                                     // Calculate the position of an element in a divided interval
        virtual void drawStripes(
            unsigned long xLeft,
            unsigned long width,
            unsigned long yTop,
            unsigned long height,
            string direction,                                        // "horizontal" or "vertical"
            unsigned long spaces,
            unsigned long thickness
        ) = 0;                                                       // Draw stripes
        virtual void drawRectangle(
            unsigned long xLeft,
            unsigned long width,
            unsigned long yTop,
            unsigned long height
        ) = 0;                                                       // Draw a rectangle
        virtual void drawCircle(
            unsigned long x,
            unsigned long y,
            unsigned long radius
        ) = 0;                                                       // Draw a circle
        virtual void drawText(
            unsigned long x,
            unsigned long y,
            string text,
            unsigned long size
        ) = 0;                                                       // Draw a text

    private:
        shared_ptr<GraphicsWindow> my_graphicsWindow;
        unsigned long my_xOffset;
        unsigned long my_yOffset;
        long long my_xSpeed;
        long long my_ySpeed;
        unsigned long my_width;
        unsigned long my_height;
        unsigned long my_color;
};

#endif // __ALOBE__GRAPHICS__
