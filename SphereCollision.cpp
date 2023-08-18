#include "SphereCollision.h"

bool SphereCollision::isCollision(Sphere s1, Sphere s2)
{
    float distance = vf_.Length(vf_.Subtract(s1.center, s2.center));
    if (distance*distance <= s1.radius* s1.radius + s2.radius* s2.radius) {
        return true;
    }
    return false;
}
