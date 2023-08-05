#ifndef LAMBERTIAN_H
#define LAMBERTIAN_H

#include "Material.h"

class Lambertian : public Material
{
public:

	Lambertian(const Colour& albedo) : Albedo(albedo) {}

	// Inherited via Material
	virtual bool Scatter(const Ray& InRay, const HitData& data, Colour& attenuation, Ray& scattered) const override;

private:

	Colour Albedo;
};

#endif
