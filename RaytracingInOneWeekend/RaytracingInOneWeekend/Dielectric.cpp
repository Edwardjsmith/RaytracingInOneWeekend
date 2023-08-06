#include "Dielectric.h"
#include "HittableEntity.h"

double Dialectric::Reflectance(const double cosine, const double refractionIndex)
{
    double r0 = (1 - refractionIndex) / (1 + refractionIndex);
    r0 *= r0;

    return r0 + ((1 - r0) * pow((1 - cosine), 5));
}

bool Dialectric::Scatter(const Ray& InRay, const HitData& data, Colour& attenuation, Ray& scattered) const
{
    attenuation = Colour(1.0);
    const double refractionRatio = data.frontFacingNormal ? (1.0 / RefractionIndex) : RefractionIndex;

    const Vector3 unitDirection = GetUnitVector(InRay.GetDirection());

    const double cosTheta = fmin(Dot(-unitDirection, data.hitNormal), 1.0);
    const double sinTheta = sqrt(1.0 - (cosTheta * cosTheta));

    const bool cannotRefract = (refractionRatio * sinTheta) > 1.0;
    Vector3 direction;

    if (cannotRefract || Reflectance(cosTheta, refractionRatio) > RandomDouble())
    {
        direction = ReflectedVector(unitDirection, data.hitNormal);
    }
    else
    {
        direction = RefractedVector(unitDirection, data.hitNormal, refractionRatio);
    }

    scattered = Ray(data.hitPoint, direction);

    return true;
}
