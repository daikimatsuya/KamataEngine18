#include "LineToPointCollision.h"

Vector3 LineToPointCollision::Project(const Vector3& v1, const Vector3& v2)
{
    Vector3 normalize = vf_.Normalize(v2);
    return vf_.Multiply(normalize, vf_.Dot(v1, normalize));
}

Vector3 LineToPointCollision::ClosestPoint(const Vector3& point, const Segment& segment)
{
    Vector3 closestPoint;
    closestPoint = vf_.Add(segment.origin, Project(vf_.Subtract(point, segment.origin), segment.diff));
    return closestPoint;
}
