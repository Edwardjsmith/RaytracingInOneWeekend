#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <cmath>
#include <limits>
#include <memory>
#include <cstdlib>

using std::shared_ptr;
using std::make_shared;
using std::sqrt;

const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

const double imageAspectRatio = 16.0 / 9.0;

// Utility Functions

inline double DegreesToRadians(double degrees)
{
    return degrees * pi / 180.0;
}

inline double RandomDouble()
{
    // Returns a random real in [0,1).
    return rand() / (RAND_MAX + 1.0);
}

inline double RandomDoubleInRange(double min, double max)
{
    // Returns a random real in [min,max).
    return min + (max - min) * RandomDouble();
}

inline double Clamp(double x, double min, double max)
{
    if (x < min)
    {
        return min;
    }
    else if (x > max)
    {
        return max;
    }

    return x;
}

// Common Headers

#include "Ray.h"
#include "Vector3.h"

#endif