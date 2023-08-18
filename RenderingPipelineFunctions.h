#pragma once
#include "Matrix4x4.h"
class RenderingPipelineFunctions{
public:
	RenderingPipelineFunctions();
	~RenderingPipelineFunctions();
	Matrix4x4 MakeOrthographicMatrix(float left, float top, float right, float bottom, float nearClip, float farClip);
	Matrix4x4 MakePerspectiveFovMatrix(float fovY, float aspectRatio, float nearClip, float farClip);
	Matrix4x4 MakeViewportMatrix(float left, float top, float width, float height, float minDeth, float maxDepth);
	void show(float f1[6],float f2[4], float f3[6]);
private:
};

