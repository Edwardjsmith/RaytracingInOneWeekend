#ifndef MATERIAL_H
#define MATERIAL_H

#include "Constants.h"

struct HitData;

class Material
{

public:

	virtual bool Scatter(const Ray& InRay, const HitData& data, Colour& attenuation, Ray& scattered) const = 0;
};

#endif // !MATERIAL_H
