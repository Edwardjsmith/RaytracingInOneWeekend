#pragma once

#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>

using std::sqrt;

class Vector3 {
public:
    Vector3() : element{ 0,0,0 } {}
    Vector3(double x, double y, double z) : element{ x, y, z } {}
    Vector3(double value) : element{value, value, value } {}

    double X() const { return element[0]; }
    double Y() const { return element[1]; }
    double Z() const { return element[2]; }

    Vector3 operator-() const { return Vector3(-element[0], -element[1], -element[2]); }
    double operator[](int i) const { return element[i]; }
    double& operator[](int i) { return element[i]; }

    Vector3& operator+=(const Vector3& vector)
    {
        element[0] += vector.element[0];
        element[1] += vector.element[1];
        element[2] += vector.element[2];
        return *this;
    }

    Vector3& operator*=(const double scalar)
    {
        element[0] *= scalar;
        element[1] *= scalar;
        element[2] *= scalar;
        return *this;
    }

    Vector3& operator/=(const double scalar) 
    {
        return *this *= 1 / scalar;
    }

    double Length() const 
    {
        return sqrt(LengthSquared());
    }

    double LengthSquared() const
    {
        return element[0] * element[0] + element[1] * element[1] + element[2] * element[2];
    }

private:

    double element[3];
};

// Type aliases for Vector3
using Point3 = Vector3;   // 3D point
using Colour = Vector3;    // RGB color

// Vector3 Utility Functions

inline std::ostream& operator<<(std::ostream& out, const Vector3& vector)
{
    return out << vector.X() << ' ' << vector.Y() << ' ' << vector.Z();
}

inline Vector3 operator+(const Vector3& firstVector, const Vector3& secondVector)
{
    return Vector3(firstVector.X() + secondVector.X(), firstVector.Y() + secondVector.Y(), firstVector.Z() + secondVector.Z());
}

inline Vector3 operator-(const Vector3& firstVector, const Vector3& secondVector)
{
    return Vector3(firstVector.X() - secondVector.X(), firstVector.Y() - secondVector.Y(), firstVector.Z() - secondVector.Z());
}

inline Vector3 operator*(const Vector3& firstVector, const Vector3& secondVector)
{
    return Vector3(firstVector.X() * secondVector.X(), firstVector.Y() * secondVector.Y(), firstVector.Z() * secondVector.Z());
}

inline Vector3 operator*(double scalar, const Vector3& vector)
{
    return Vector3(scalar * vector.X(), scalar * vector.Y(), scalar * vector.Z());
}

inline Vector3 operator*(const Vector3& vector, double scalar)
{
    return scalar * vector;
}

inline Vector3 operator/(Vector3 vector, double scalar)
{
    return (1 / scalar) * vector;
}

inline double Dot(const Vector3& firstVector, const Vector3& secondVector)
{
    return firstVector.X() * secondVector.X()
        + firstVector.Y() * secondVector.Y()
        + firstVector.Z() * secondVector.Z();
}

inline Vector3 Cross(const Vector3& firstVector, const Vector3& secondVector)
{
    return Vector3(firstVector.Y() * secondVector.Z() - firstVector.Z() * secondVector.Y(),
        firstVector.Z() * secondVector.X() - firstVector.X() * secondVector.Z(),
        firstVector.X() * secondVector.Y() - firstVector.Y() * secondVector.X());
}

inline Vector3 GetUnitVector(const Vector3& vector)
{
    return vector / vector.Length();
}

#endif