#ifndef RAY_H
#define RAY_H

#include "Vector3.h"

class Ray
{
public:

	Ray(){}
	Ray(const Point3& origin, const Vector3& direction) : Origin(origin), Direction(direction) {}

	Point3 GetOrigin() const { return Origin; }
	Vector3 GetDirection() const { return Direction; }

	Point3 CastRay(double scalar) const { return Origin + (scalar * Direction); }

private:

	Point3 Origin;
	Vector3 Direction;
};
#endif // !RAY_H

