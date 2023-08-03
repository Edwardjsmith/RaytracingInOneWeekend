#include "Camera.h"

Camera::Camera()
{
    const double cameraViewportHeight = 2.0;
    const double cameraViewportWidth = imageAspectRatio * cameraViewportHeight;
    const double cameraFocalLength = 1.0;

    const Point3 cameraOrigin = Point3(0.0);
    const Vector3 cameraRight = Vector3(cameraViewportWidth, 0.0, 0.0);
    const Vector3 cameraUp = Vector3(0, cameraViewportHeight, 0.0);
    const Vector3 cameraLowerLeftCorner = cameraOrigin - (cameraRight * 0.5) - (cameraUp * 0.5) - Vector3(0, 0, cameraFocalLength);

    Origin = Point3(0);
    Right = Vector3(cameraViewportWidth, 0.0, 0.0);
    Up = Vector3(0.0, cameraViewportHeight, 0.0);
    LowerLeft = Origin - Right / 2 - Up / 2 - Vector3(0, 0, cameraFocalLength);
}

Ray Camera::GetRay(const double u, const double v)
{
	return Ray(Origin, LowerLeft + (u *Right) + (v*Up) - Origin);
}
