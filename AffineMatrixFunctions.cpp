#include "AffineMatrixFunctions.h"
#include "cmath"
#include "Vector3.h"
#include "Material.h"
#include "Vector4.h"


AffineMatrixFunctions::AffineMatrixFunctions(){

}

AffineMatrixFunctions::~AffineMatrixFunctions(){

}

Matrix4x4 AffineMatrixFunctions::Multiply(Matrix4x4 m1, Matrix4x4 m2){
	Matrix4x4 tmp;
	tmp.m[0][0] = m1.m[0][0] * m2.m[0][0] + m1.m[0][1] * m2.m[1][0] + m1.m[0][2] * m2.m[2][0] + m1.m[0][3] * m2.m[3][0];
	tmp.m[0][1] = m1.m[0][0] * m2.m[0][1] + m1.m[0][1] * m2.m[1][1] + m1.m[0][2] * m2.m[2][1] + m1.m[0][3] * m2.m[3][1];
	tmp.m[0][2] = m1.m[0][0] * m2.m[0][2] + m1.m[0][1] * m2.m[1][2] + m1.m[0][2] * m2.m[2][2] + m1.m[0][3] * m2.m[3][2];
	tmp.m[0][3] = m1.m[0][0] * m2.m[0][3] + m1.m[0][1] * m2.m[1][3] + m1.m[0][2] * m2.m[2][3] + m1.m[0][3] * m2.m[3][3];

	tmp.m[1][0] = m1.m[1][0] * m2.m[0][0] + m1.m[1][1] * m2.m[1][0] + m1.m[1][2] * m2.m[2][0] + m1.m[1][3] * m2.m[3][0];
	tmp.m[1][1] = m1.m[1][0] * m2.m[0][1] + m1.m[1][1] * m2.m[1][1] + m1.m[1][2] * m2.m[2][1] + m1.m[1][3] * m2.m[3][1];
	tmp.m[1][2] = m1.m[1][0] * m2.m[0][2] + m1.m[1][1] * m2.m[1][2] + m1.m[1][2] * m2.m[2][2] + m1.m[1][3] * m2.m[3][2];
	tmp.m[1][3] = m1.m[1][0] * m2.m[0][3] + m1.m[1][1] * m2.m[1][3] + m1.m[1][2] * m2.m[2][3] + m1.m[1][3] * m2.m[3][3];

	tmp.m[2][0] = m1.m[2][0] * m2.m[0][0] + m1.m[2][1] * m2.m[1][0] + m1.m[2][2] * m2.m[2][0] + m1.m[2][3] * m2.m[3][0];
	tmp.m[2][1] = m1.m[2][0] * m2.m[0][1] + m1.m[2][1] * m2.m[1][1] + m1.m[2][2] * m2.m[2][1] + m1.m[2][3] * m2.m[3][1];
	tmp.m[2][2] = m1.m[2][0] * m2.m[0][2] + m1.m[2][1] * m2.m[1][2] + m1.m[2][2] * m2.m[2][2] + m1.m[2][3] * m2.m[3][2];
	tmp.m[2][3] = m1.m[2][0] * m2.m[0][3] + m1.m[2][1] * m2.m[1][3] + m1.m[2][2] * m2.m[2][3] + m1.m[2][3] * m2.m[3][3];

	tmp.m[3][0] = m1.m[3][0] * m2.m[0][0] + m1.m[3][1] * m2.m[1][0] + m1.m[3][2] * m2.m[2][0] + m1.m[3][3] * m2.m[3][0];
	tmp.m[3][1] = m1.m[3][0] * m2.m[0][1] + m1.m[3][1] * m2.m[1][1] + m1.m[3][2] * m2.m[2][1] + m1.m[3][3] * m2.m[3][1];
	tmp.m[3][2] = m1.m[3][0] * m2.m[0][2] + m1.m[3][1] * m2.m[1][2] + m1.m[3][2] * m2.m[2][2] + m1.m[3][3] * m2.m[3][2];
	tmp.m[3][3] = m1.m[3][0] * m2.m[0][3] + m1.m[3][1] * m2.m[1][3] + m1.m[3][2] * m2.m[2][3] + m1.m[3][3] * m2.m[3][3];
	return tmp;
}

Matrix4x4 AffineMatrixFunctions::MakeScaleMatrix(Vector3 scale){
	Matrix4x4 tmp{
		{scale.x,0,0,0,
			0,scale.y,0,0,
				0,0,scale.z,0,
					0,0,0,1.0f}
	};
	return tmp;
}

Matrix4x4 AffineMatrixFunctions::MakeRotateMatrix(Matrix4x4 rotate1,Matrix4x4 rotate2,Matrix4x4 rotate3){
	Matrix4x4 tmp;
	tmp = Multiply(rotate1, Multiply(rotate2, rotate3));
	return tmp;
}

Matrix4x4 AffineMatrixFunctions::MakeRotateXMatrix(float theta){
	Matrix4x4 tmp{
			{1,0,				  0,			   0,
			  0,cosf(theta),sinf(theta),  0,
			  0,-sinf(theta),cosf(theta), 0,
			  0, 0,			  0,				1.0f}
	};
	return tmp;
}

Matrix4x4 AffineMatrixFunctions::MakeRotateYMatrix(float theta){
	Matrix4x4 tmp{
		{cosf(theta),0,-sinf(theta), 0,
		  0,			  1,0,				  0,
		  sinf(theta),0,cosf(theta),0,
		  0,			  0,0,				  1.0f}
	};
	return tmp;
	
}

Matrix4x4 AffineMatrixFunctions::MakeRotateZMatrix(float theta){
	Matrix4x4 tmp{
		{cosf(theta),sinf(theta),0,0,
		 -sinf(theta),cosf(theta),0,0,
		  0,			  0,			   1.0f,0,
		  0,			  0,			   0,1.0f}
	};
	return tmp;
}

Matrix4x4 AffineMatrixFunctions::MakeTranslateMatrix(Vector3 translate){
	Matrix4x4 tmp{
		{1,						  0,						  0,						  0,
		  0,						  1,						  0,						  0,
		  0,						  0,						  1,						  0,
		  translate.x,				translate.y,			translate.z,		1.0f }
	};

	return tmp;
}

Matrix4x4 AffineMatrixFunctions::MakeAffinMatrix(Matrix4x4 Scale, Matrix4x4 Rotate, Matrix4x4 Translate){
	Matrix4x4 tmp;
	tmp = Multiply(Scale, Multiply(Rotate,Translate));
	return tmp;
}

void AffineMatrixFunctions::show(Vector3 scale, float theta1,float theta2,float theta3, Vector3 translate){
	Matrix4x4 tmp1;
	Matrix4x4 tmp2;
	Matrix4x4 tmp3;
	Matrix4x4 tmp4;
	Matrix4x4 tmp5;
	Matrix4x4 tmp6;
	Matrix4x4 tmp7;

	tmp1 = MakeScaleMatrix(scale);
	tmp2 = MakeRotateXMatrix(theta1);
	tmp3 = MakeRotateYMatrix(theta2);
	tmp4 = MakeRotateZMatrix(theta3);
	tmp5 = MakeTranslateMatrix(translate);
	tmp6 = MakeRotateMatrix(tmp2, tmp3, tmp4);
	tmp7 = MakeAffinMatrix(tmp1, tmp6, tmp5);
}
Vector3 AffineMatrixFunctions::Transform(Vector3 v1, Matrix4x4 m1) {
	Vector4 tmp;
	Vector3 tmp2;
	tmp.x = v1.x;
	tmp.y = v1.y;
	tmp.z = v1.z;
	tmp.w = 1.0f;

	float w = tmp.x * m1.m[0][3] + tmp.y * m1.m[1][3] + tmp.z * m1.m[2][3] + tmp.w * m1.m[3][3];
	tmp2.x = (tmp.x * m1.m[0][0] + tmp.y * m1.m[1][0] + tmp.z * m1.m[2][0] + tmp.w * m1.m[3][0]) / w;
	tmp2.y = (tmp.x * m1.m[0][1] + tmp.y * m1.m[1][1] + tmp.z * m1.m[2][1] + tmp.w * m1.m[3][1]) / w;
	tmp2.z = (tmp.x * m1.m[0][2] + tmp.y * m1.m[1][2] + tmp.z * m1.m[2][2] + tmp.w * m1.m[3][2]) / w;
	return tmp2;

}

Matrix4x4 AffineMatrixFunctions::MakeRotateMatrix(Vector3 rotate) {
	Matrix4x4 tmp1 = MakeRotateXMatrix(rotate.x);
	Matrix4x4 tmp2 = MakeRotateYMatrix(rotate.y);
	Matrix4x4 tmp3 = MakeRotateZMatrix(rotate.z);
	Matrix4x4 tmp4 = MakeRotateMatrix(tmp1, tmp2, tmp3);
	return tmp4;
}
