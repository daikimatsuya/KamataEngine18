#pragma once
#include "Vector3.h"
class VectorFanctions{
private:

public:
	
	Vector3 Add(const Vector3& v1, const Vector3& v2);
	Vector3 Subtract(const Vector3& v1, const Vector3& v2);
	Vector3 Multiply(const Vector3& v1, float scalar);
	float Dot(const Vector3& v1, const Vector3& v2);
	float Length(const Vector3& v1);
	Vector3 Normalize(const Vector3& v1);
	Vector3 Cross(const Vector3& v1, const Vector3& v2);

};

