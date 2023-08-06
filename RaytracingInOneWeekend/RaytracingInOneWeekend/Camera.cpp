#include "Camera.h"

Camera::Camera(const Point3& lookFrom, const Point3& lookAt, const Vector3 up, const double virticalFOV, const double aspectRatio)
{
    const double theta = DegreesToRadians(virticalFOV);
    const double h = tan(theta * 0.5);


    const double cameraViewportHeight = 2.0 * h;
    const double cameraViewportWidth = imageAspectRatio * cameraViewportHeight;
    const double cameraFocalLength = 1.0;

    const Point3 cameraOrigin = Point3(0.0);
    const Vector3 cameraRight = Vector3(cameraViewportWidth, 0.0, 0.0);
    const Vector3 cameraUp = Vector3(0, cameraViewportHeight, 0.0);
    const Vector3 cameraLowerLeftCorner = cameraOrigin - (cameraRight * 0.5) - (cameraUp * 0.5) - Vector3(0, 0, cameraFocalLength);

    const Vector3 w = GetUnitVector(lookFrom - lookAt);
    const Vector3 u = GetUnitVector(Cross(up, w));
    const Vector3 v = Cross(w, u);

    Origin = lookFrom;
    Right = cameraViewportWidth * u;
    Up = cameraViewportHeight * v;
    LowerLeft = Origin - (Right * 0.5) - (Up * 0.5) - w;
}

Ray Camera::GetRay(const double u, const double v) const
{
	return Ray(Origin, LowerLeft + (u *Right) + (v*Up) - Origin);
}
