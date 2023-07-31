#include "Sphere.h"

bool Sphere::IsHit(const Ray& ray, double tMin, double tMax, HitData& hitData) const
{
	const Vector3 diff = ray.GetOrigin() - sphereCentre;
	const double a = ray.GetDirection().LengthSquared();
	const double b = Dot(diff, ray.GetDirection());
	const double c = diff.LengthSquared() - (sphereRadius * sphereRadius);

	const double discriminant = (b * b) - (a * c);

	if (discriminant < 0)
	{
		return false;
	}

	const double discriminantSqrt = sqrt(discriminant);

	//Find suitable root
	double root = (-b - discriminantSqrt) / a;

	if (root < tMin || root > tMax)
	{
		root = (-b + discriminantSqrt) / a;

		if (root < tMin || root > tMax)
		{
			return false;
		}
	}

	hitData.hitScalar = root;
	hitData.hitPoint = ray.CastRay(root);
	hitData.SetFaceNormal(ray, (hitData.hitPoint - sphereCentre) / sphereRadius);
	
}
