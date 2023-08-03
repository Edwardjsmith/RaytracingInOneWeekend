#pragma once

#ifndef COLOR_H
#define COLOUR_H

#include "Vector3.h"

#include <iostream>

static const double rgbMultiplier = 255.999;

void WriteColour(std::ostream& out, Colour pixelColour, const int samplesPerPixel)
{
    const double scale = 1.0 / samplesPerPixel;

    const double r = pixelColour.X() * scale;
    const double g = pixelColour.Y() * scale;
    const double b = pixelColour.Z() * scale;



    

    // Write the translated [0,255] value of each color component.
    out << static_cast<int>(rgbMultiplier * Clamp(r, 0.0, 0.999)) << ' '
        << static_cast<int>(rgbMultiplier * Clamp(g, 0.0, 0.999)) << ' '
        << static_cast<int>(rgbMultiplier * Clamp(b, 0.0, 0.999)) << '\n';
}

#endif