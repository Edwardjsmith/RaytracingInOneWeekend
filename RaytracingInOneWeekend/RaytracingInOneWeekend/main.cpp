#pragma once

#include "Constants.h"

#include "Colour.h"
#include "HittablesList.h"
#include "Sphere.h"

Colour RayColour(const Ray& ray, const HittableEntity& entity)
{
	HitData data;

	if (entity.IsHit(ray, 0.0, infinity, data))
	{
		return 0.5 * (data.hitNormal + Colour(1.0));
	}

	Vector3 unitDir = GetUnitVector(ray.GetDirection());

	const double t = 0.5 * (unitDir.Y() + 1.0);

	return (1.0 - t) * Colour(1.0) + (t * Colour(0.5, 0.7, 1.0));
}

//Image constants
const double imageAspectRatio = 16.0 / 9.0;
const int imageWidth = 400;
const int imageHeight = static_cast<int>(imageWidth / imageAspectRatio);

//Camera constants
const double cameraViewportHeight = 2.0;
const double cameraViewportWidth = imageAspectRatio * cameraViewportHeight;
const double cameraFocalLength = 1.0;

const Point3 cameraOrigin = Point3(0.0);
const Vector3 cameraRight = Vector3(cameraViewportWidth, 0.0, 0.0);
const Vector3 cameraUp = Vector3(0, cameraViewportHeight, 0.0);
const Vector3 cameraLowerLeftCorner = cameraOrigin - (cameraRight * 0.5) - (cameraUp * 0.5) - Vector3(0, 0, cameraFocalLength);

//Hittable entities
HittablesList entities;

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
			const double x = static_cast<double>(i) / (imageWidth - 1);
			const double y = static_cast<double>(j) / (imageHeight - 1);

			const Vector3 rayDir = cameraLowerLeftCorner + (x * cameraRight) + (y * cameraUp) - cameraOrigin;
			const Ray ray(cameraOrigin, rayDir);

			Colour pixelColour = RayColour(ray, entities);
			WriteColour(std::cout, pixelColour);
		}
	}

	std::cerr << "\nDone.\n";

	return 0;
}