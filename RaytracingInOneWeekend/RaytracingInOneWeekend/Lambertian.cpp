#include "Lambertian.h"
#include "HittableEntity.h"

bool Lambertian::Scatter(const Ray& InRay, const HitData& data, Colour& attenuation, Ray& scattered) const 
{
    Vector3 scatterDirection = data.hitNormal + RandomUnitVectorInUnitSphere();

    //Check if scatter direction is a degenerate
    if (scatterDirection.NearZero())
    {
        scatterDirection = data.hitNormal;
    }

    scattered = Ray(data.hitPoint, scatterDirection);
    attenuation = Albedo;


    return true;
}
