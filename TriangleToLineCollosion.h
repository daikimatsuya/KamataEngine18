#pragma once
#include "Triangle.h"
#include "LineRaySegment.h"
#include "VectorFanctions.h"
#include "Plane.h"
#include "Matrix4x4.h"
#include "stdint.h"
#include "AffineMatrixFunctions.h"
class TriangleToLineCollosion
{
public:
	bool IsCollision(const Triangle& triangle, const Segment& line);
	void Draw(const Triangle& triangle, const Matrix4x4& viewPrijectionMatrix, const Matrix4x4& viewportMatrix, uint32_t color);
private:
	VectorFanctions vf_;
	AffineMatrixFunctions amf_;
};

