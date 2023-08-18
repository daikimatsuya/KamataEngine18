#pragma once
#include "LineRaySegment.h"
#include "Plane.h"
#include "VectorFanctions.h"
class LineToPlaneCollision
{
public:
	bool IsCollosion(const Segment& line, const Plane& plane);
private:
	VectorFanctions vf_;
};


