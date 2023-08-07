#pragma once

#include "Constants.h"

#include "Camera.h"
#include "HittablesList.h"
#include "Sphere.h"
#include "Colour.h"
#include "Lambertian.h"
#include "Metal.h"
#include "Dielectric.h"

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
		Ray scattered;
		Colour attenuation;

		if (data.hitMaterialPtr != nullptr && data.hitMaterialPtr->Scatter(ray, data, attenuation, scattered))
		{
			return attenuation * RayColour(scattered, entity, depth - 1);
		}

		return Colour(0);
	}

	const Vector3 unitDir = GetUnitVector(ray.GetDirection());

	const double t = 0.5 * (unitDir.Y() + 1.0);

	return (1.0 - t) * Colour(1.0) + (t * Colour(0.5, 0.7, 1.0));
}

//Image constants
const int imageWidth = 400;
const int imageHeight = static_cast<int>(imageWidth / imageAspectRatio);
const int samplesPerPixel = 100;

//Camera
const Point3 lookFrom(-2, 2, 1);
const Point3 lookAt(0, 0, -1);
const Vector3 up(0, 1, 0);
const double distToFocus = (lookFrom - lookAt).Length();
const double aperture = 2.0;

Camera cam(lookFrom, lookAt, up, 90.0, imageAspectRatio, aperture, distToFocus);

//Hittable entities
HittablesList entities;

//Max depth
const int maxDepth = 50;

int main()
{
	shared_ptr<Lambertian> floorMaterial = make_shared<Lambertian>(Colour(0.8, 0.8, 0.0));
	shared_ptr<Lambertian> centreMaterial = make_shared<Lambertian>(Colour(0.7, 0.3, 0.3));
	shared_ptr<Dialectric> leftMaterial = make_shared<Dialectric>(0.1);
	shared_ptr<Metal> rightMaterial = make_shared<Metal>(Colour(0.8, 0.6, 0.2), 1.0);

	entities.Add(make_shared<Sphere>(Point3(0.0, -100.5, -1.0), 100.0, floorMaterial));
	entities.Add(make_shared<Sphere>(Point3(1.0, 0.0, -1.0), 0.5, rightMaterial));
	entities.Add(make_shared<Sphere>(Point3(0.0, 0.0, -1.0), 0.5, centreMaterial));
	entities.Add(make_shared<Sphere>(Point3(-1.0, 0.0, -1.0), -0.5, leftMaterial));

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