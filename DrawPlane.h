#pragma once
#include "Plane.h"
#include "Matrix4x4.h"
#include "stdint.h"
#include "VectorFanctions.h"
#include "AffineMatrixFunctions.h"
class DrawPlane
{
public:
	void Draw(const Plane& plane, const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewportMatrix,uint32_t color);
	Vector3 Perpendicular(const Vector3& vector);
private:
	VectorFanctions vf_;
	AffineMatrixFunctions amf_;
};

