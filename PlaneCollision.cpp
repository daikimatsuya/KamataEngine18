#include "PlaneCollision.h"
#include "math.h"

bool PlaneCollision::IsCollision(const Sphere& sphere, const Plane& plane)
{
    float distance = sqrtf((vf_.Dot(sphere.center, plane.normal) - plane.distance) * (vf_.Dot(sphere.center, plane.normal) - plane.distance));

    if (distance <= sphere.radius) {
        return true;
    }
    return false;
}
