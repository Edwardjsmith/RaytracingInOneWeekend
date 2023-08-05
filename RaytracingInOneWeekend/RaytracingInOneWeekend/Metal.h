#ifndef METAL_H
#define METAL_H

#include "Material.h"

class Metal : public Material
{

public:

	Metal(const Colour& albedo, const double fuzziness) : Albedo(albedo), Fuzziness(fuzziness) {}

	// Inherited via Material
	virtual bool Scatter(const Ray& InRay, const HitData& data, Colour& attenuation, Ray& scattered) const override;
private:

	Colour Albedo;
	double Fuzziness;

};

#endif