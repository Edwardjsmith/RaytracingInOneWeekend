#include "Camera.h"

Camera::Camera(const Point3& lookFrom, const Point3& lookAt, const Vector3 up, const double virticalFOV, const double aspectRatio, const double aperture, const double focusDistance)
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

    w = GetUnitVector(lookFrom - lookAt);
    u = GetUnitVector(Cross(up, w));
    v = Cross(w, u);

    Origin = lookFrom;
    Right = focusDistance * cameraViewportWidth * u; 
    Up = focusDistance * cameraViewportHeight * v;
    LowerLeft = Origin - (Right * 0.5) - (Up * 0.5) - (focusDistance * w);

    lensRadius = aperture * 0.5;
}

Ray Camera::GetRay(const double u, const double v) const
{
    const Vector3 radius = lensRadius * RandomVectorInUnitDisc();
    const Vector3 offset = (u * radius.X()) + (v * radius.Y());

	return Ray(Origin + offset, LowerLeft + (u * Right) + (v * Up) - (Origin - offset));
}
