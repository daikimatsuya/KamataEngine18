#include "VectorFanctions.h"
#include "math.h"


Vector3 VectorFanctions::Add(const Vector3& v1, const Vector3& v2) {
	Vector3 tmp={};
	tmp.x = v1.x + v2.x;
	tmp.y = v1.y + v2.y;
	tmp.z = v1.z + v2.z;
	return tmp;
}

Vector3 VectorFanctions::Subtract(const Vector3& v1, const Vector3& v2){
	Vector3 tmp={};
	tmp.x = v1.x - v2.x;
	tmp.y = v1.y - v2.y;
	tmp.z = v1.z - v2.z;
	return tmp;
}

Vector3 VectorFanctions::Multiply(const Vector3& v1, float scalar){
	Vector3 tmp={};
	tmp.x = v1.x * scalar;
	tmp.y = v1.y * scalar;
	tmp.z = v1.z * scalar;
	return tmp;
}

float VectorFanctions::Dot(const Vector3& v1, const Vector3& v2){
	float tmp={};
	tmp = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	return tmp;
}

float VectorFanctions::Length(const Vector3& v1){
	float tmp={};
	tmp = sqrtf(v1.x * v1.x + v1.y * v1.y + v1.z * v1.z);
	return tmp;
}

Vector3 VectorFanctions::Normalize(const Vector3& v1){
	float tmp1 = Length(v1);
	Vector3 tmp2 = v1;
	if (tmp1 != 0) {
		tmp2.x = v1.x / tmp1;
		tmp2.y = v1.y / tmp1;
		tmp2.z = v1.z / tmp1;
	}
	return tmp2;
}
Vector3 VectorFanctions::Cross(const Vector3& v1, const Vector3& v2)
{
	Vector3 tmp;
	tmp.x = v1.y * v2.z - v2.y * v1.z;
	tmp.y = v1.z * v2.x - v2.z * v1.x;
	tmp.z = v1.x * v2.y - v2.x * v1.y;
	return tmp;
}


