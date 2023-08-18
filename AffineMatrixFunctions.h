#pragma once
#include "Vector3.h"
#include "Matrix4x4.h"
class AffineMatrixFunctions{
public:
	
	AffineMatrixFunctions();
	~AffineMatrixFunctions();
	Matrix4x4 Multiply(Matrix4x4 m1, Matrix4x4 m2);
	Matrix4x4 MakeScaleMatrix(Vector3 scale);
	Matrix4x4 MakeRotateMatrix(Matrix4x4 rotate1,Matrix4x4 rotate2,Matrix4x4 rotate3);
	Matrix4x4 MakeRotateXMatrix(float theta);
	Matrix4x4 MakeRotateYMatrix(	float theta);
	Matrix4x4 MakeRotateZMatrix(float theta);
	Matrix4x4 MakeTranslateMatrix(Vector3 translate);
	Matrix4x4 MakeAffinMatrix(Matrix4x4 Scale, Matrix4x4 Rotate, Matrix4x4 Translate);
	void show(Vector3 scale, float theta1,float theta2,float theta3, Vector3 translate);
	Vector3 Transform(Vector3 v1, Matrix4x4 m1);
	Matrix4x4 MakeRotateMatrix(Vector3 rotate);
private:

};

