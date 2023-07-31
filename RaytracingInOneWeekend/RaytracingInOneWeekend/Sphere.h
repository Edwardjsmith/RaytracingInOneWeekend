#ifndef SPHERE_H
#define SPHERE_H

#include "HittableEntity.h"

class Sphere : public HittableEntity
{
public:

	Sphere() {}
	Sphere(Point3 centre, double radius) : sphereCentre(centre), sphereRadius(radius) {};

	virtual bool IsHit(const Ray& ray, double tMin, double tMax, HitData& hitData) const;

private:

	Point3 sphereCentre;
	double sphereRadius;
};

#endif
