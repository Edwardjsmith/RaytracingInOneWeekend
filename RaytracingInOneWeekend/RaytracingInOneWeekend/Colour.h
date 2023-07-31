#ifndef COLOR_H
#define COLOUR_H

#include "Vector3.h"

#include <iostream>

static const double rgbMultiplier = 255.999;

void WriteColour(std::ostream& out, Colour pixelColour)
{
    // Write the translated [0,255] value of each color component.
    out << static_cast<int>(rgbMultiplier * pixelColour.X()) << ' '
        << static_cast<int>(rgbMultiplier * pixelColour.Y()) << ' '
        << static_cast<int>(rgbMultiplier * pixelColour.Z()) << '\n';
}

#endif