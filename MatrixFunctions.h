#pragma once
#include "Matrix4x4.h"
#include "Vector3.h"
#include "Vector4.h"
class MatrixFunctions{
public:
	MatrixFunctions();
	~MatrixFunctions();
	Matrix4x4 Add(const Matrix4x4& m1, const Matrix4x4& m2);
	Matrix4x4 Substruct(const Matrix4x4& m1, const Matrix4x4& m2);
	Matrix4x4 Multiply(const Matrix4x4& m1, const Matrix4x4& m2);
	Matrix4x4 Inverse(const Matrix4x4& m);
	Matrix4x4 Transpose(const Matrix4x4& m);

	Matrix4x4 MakeIdentity();
	
private:
};

