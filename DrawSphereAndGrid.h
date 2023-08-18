#pragma once
#include "Matrix4x4.h"
#include "AffineMatrixFunctions.h"
#include "MatrixFunctions.h"
#include "RenderingPipelineFunctions.h"
#include "VectorFanctions.h"
#include "Sphere.h"


class DrawSphereAndGrid{
public:
	void DrwaSphere(const Sphere& sphere, const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewportMatrix, int color);
	void DrawGrid(const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewportMatrix);

private:
	AffineMatrixFunctions amf_;
	MatrixFunctions mf_;
	RenderingPipelineFunctions rpf_;
	VectorFanctions vf_;


};

