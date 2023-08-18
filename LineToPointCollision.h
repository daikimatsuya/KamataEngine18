#pragma once
#include "Vector3.h"
#include "LineRaySegment.h"
#include "VectorFanctions.h"
class LineToPointCollision
{
public:
	Vector3 Project(const Vector3& v1, const Vector3& v2);
	Vector3 ClosestPoint(const Vector3& point, const Segment& segment);
private:
	VectorFanctions vf_;
};

