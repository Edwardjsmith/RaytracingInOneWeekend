#ifndef HITTABLEENTITY_H
#define HITTABLEENTITY_H

#include "Constants.h"

class Material;

struct HitData
{
	Point3 hitPoint;
	Vector3 hitNormal;
	shared_ptr<Material> hitMaterialPtr;
	double hitScalar;
	bool frontFacingNormal = false;

	inline void SetFaceNormal(const Ray& ray, const Vector3& outwardNormal)
	{
		frontFacingNormal = Dot(ray.GetDirection(), outwardNormal) < 0.0;
		hitNormal = frontFacingNormal ? outwardNormal : -outwardNormal;
	}
};

class HittableEntity
{
public:

	virtual bool IsHit(const Ray& ray, double tMin, double tMax, HitData& hitData) const = 0;
};

#endif // !HITTABLEENTITY_H

