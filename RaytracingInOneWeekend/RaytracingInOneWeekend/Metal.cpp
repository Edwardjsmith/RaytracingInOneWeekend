#include "Metal.h"
#include "HittableEntity.h"

bool Metal::Scatter(const Ray& InRay, const HitData& data, Colour& attenuation, Ray& scattered) const
{
    const Vector3 reflection = ReflectedVector(GetUnitVector(InRay.GetDirection()), data.hitNormal);
    scattered = Ray(data.hitPoint, reflection + (RandomVectorInUnitSphere() * Fuzziness));
    attenuation = Albedo;

    return (Dot(scattered.GetDirection(), data.hitNormal) > 0);
}
