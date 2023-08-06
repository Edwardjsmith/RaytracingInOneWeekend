#ifndef DIALECTRIC_H
#define DIALECTRIC_H

#include "Material.h"

class Dialectric : public Material
{
public:

	Dialectric(const double refractionIndex) : RefractionIndex(refractionIndex) {}

private:

	static double Reflectance(const double cosine, const double refractionIndex);

	double RefractionIndex;

	// Inherited via Material
	virtual bool Scatter(const Ray& InRay, const HitData& data, Colour& attenuation, Ray& scattered) const override;
};

#endif
