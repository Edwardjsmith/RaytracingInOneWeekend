#ifndef HITTABLESLIST_H
#define HITTABLESLIST_H
#include "HittableEntity.h"

#include <memory>
#include <vector>

using std::shared_ptr;
using std::make_shared;

class HittablesList : public HittableEntity
{
public:

	HittablesList() {}
	HittablesList(shared_ptr<HittableEntity> hittableEntity) { Add(hittableEntity); }

	void Clear() { hittableEntities.clear(); }
	void Add(shared_ptr<HittableEntity> hittableEntity) { hittableEntities.push_back(hittableEntity); }

	virtual bool IsHit(const Ray& ray, double tMin, double tMax, HitData& hitData) const;

private:

	std::vector<shared_ptr<HittableEntity>> hittableEntities;
};
#endif