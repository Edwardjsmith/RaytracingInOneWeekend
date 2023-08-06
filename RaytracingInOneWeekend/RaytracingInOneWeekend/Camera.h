#ifndef CAMERA_H
#define CAMERA_H

#include "Constants.h"

class Camera
{
public:

	Camera(const Point3& lookFrom, const Point3& lookAt, const Vector3 up, const double virticalFOV, const double aspectRatio);

	Ray GetRay(const double u, const double v) const;

private:

	Point3 Origin;
	Point3 LowerLeft;
	Vector3 Right;
	Vector3 Up;
};


#endif