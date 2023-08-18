#pragma once
#include "Sphere.h"
#include "VectorFanctions.h"
class SphereCollision
{
public:
	bool isCollision(Sphere s1, Sphere s2);
private:
	VectorFanctions vf_;
};

