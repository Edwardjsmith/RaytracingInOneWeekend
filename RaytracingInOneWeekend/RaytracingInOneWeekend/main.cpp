#pragma once

#include "Constants.h"

#include "Camera.h"
#include "HittablesList.h"
#include "Sphere.h"
#include "Colour.h"

Colour RayColour(const Ray& ray, const HittableEntity& entity, const int depth)
{
	//Exceeded depth limit, return
	if (depth <= 0)
	{
		return Colour(0);
	}

	HitData data;

	if (entity.IsHit(ray, 0.001, infinity, data))
	{
		const Point3 target = data.hitPoint + RandomInHemisphere(data.hitNormal);

		return 0.5 * RayColour(Ray(data.hitPoint, target - data.hitPoint), entity, depth - 1);
	}

	Vector3 unitDir = GetUnitVector(ray.GetDirection());

	const double t = 0.5 * (unitDir.Y() + 1.0);

	return (1.0 - t) * Colour(1.0) + (t * Colour(0.5, 0.7, 1.0));
}

//Image constants
const int imageWidth = 400;
const int imageHeight = static_cast<int>(imageWidth / imageAspectRatio);
const int samplesPerPixel = 100;

//Camera
Camera cam;

//Hittable entities
HittablesList entities;

//Max depth
const int maxDepth = 50;

int main()
{
	entities.Add(make_shared<Sphere>(Point3(0, -100.5, -1), 100));
	entities.Add(make_shared<Sphere>(Point3(0, 0, -1), 0.5));

	//Render image
	std::cout << "P3\n" << imageWidth << ' ' << imageHeight << "\n255\n";

	for (int j = imageHeight - 1; j >= 0; --j)
	{
		std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;

		for (int i = 0; i < imageWidth; ++i)
		{
			Colour pixelColour(0);
			for (int s = 0; s < samplesPerPixel; ++s)
			{
				const double u = (i + RandomDouble()) / (imageWidth - 1);
				const double v = (j + RandomDouble()) / (imageHeight - 1);
				const Ray ray = cam.GetRay(u, v);
				pixelColour += RayColour(ray, entities, maxDepth);
			}

			WriteColour(std::cout, pixelColour, samplesPerPixel);
		}
	}

	std::cerr << "\nDone.\n";

	return 0;
}