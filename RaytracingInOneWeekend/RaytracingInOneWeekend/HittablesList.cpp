#include "HittablesList.h"

bool HittablesList::IsHit(const Ray& ray, double tMin, double tMax, HitData& hitData) const
{
	HitData tempData;
	bool hit = false;
	double closest = tMax;

	for (const shared_ptr<HittableEntity> entity : hittableEntities)
	{
		if (entity->IsHit(ray, tMin, tMax, tempData))
		{
			hit = true;
			closest = tempData.hitScalar;
			hitData = tempData;
		}
	}

	return hit;
}
