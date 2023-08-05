#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <cmath>
#include <limits>
#include <memory>
#include <cstdlib>

#include "Vector3.h"

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

inline static Vector3 RandomVector()
{
    return Vector3(RandomDouble(), RandomDouble(), RandomDouble());
}

inline static Vector3 RandomVectorInRange(double min, double max)
{
    return Vector3(RandomDoubleInRange(min, max), RandomDoubleInRange(min, max), RandomDoubleInRange(min, max));
}

inline static Vector3 RandomVectorInUnitSphere()
{
    while (true)
    {
        const Vector3 randomVec = RandomVectorInRange(-1, 1);

        if (randomVec.LengthSquared() >= 1)
        {
            continue;
        }

        return randomVec;
    }
}

inline static Vector3 RandomUnitVectorInUnitSphere()
{
    return GetUnitVector(RandomVectorInUnitSphere());
}

inline static Vector3 RandomInHemisphere(const Vector3& normal)
{
    const Vector3 randomInSphere = RandomVectorInUnitSphere();

    if (Dot(randomInSphere, normal) > 0.0)
    {
        return randomInSphere;
    }
    else
    {
        return -randomInSphere;
    }
}

inline static Vector3 ReflectedVector(const Vector3& firstVector, const Vector3& secondVector)
{
    return firstVector - (2 * Dot(firstVector, secondVector) * secondVector);
}

// Common Headers

#include "Ray.h"
#include "Vector3.h"

#endif