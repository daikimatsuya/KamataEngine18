#pragma once
#include "Sphere.h"
#include "Plane.h"
#include "VectorFanctions.h"
class PlaneCollision
{
public:
	bool IsCollision(const Sphere& sphere, const Plane& plane);
private:
	VectorFanctions vf_;
};

