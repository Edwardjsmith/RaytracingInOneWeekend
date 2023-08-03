#ifndef CAMERA_H
#define CAMERA_H

#include "Constants.h"

class Camera
{
public:

	Camera();

	Ray GetRay(const double u, const double v);

private:

	Point3 Origin;
	Point3 LowerLeft;
	Vector3 Right;
	Vector3 Up;
};


#endif