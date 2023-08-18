#include "DrawPlane.h"
#include "Novice.h"

void DrawPlane::Draw(const Plane& plane, const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewportMatrix, uint32_t color)
{
	Vector3 center = vf_.Multiply(plane.normal, plane.distance);
	Vector3 perpendiculars[4];
	perpendiculars[0] = vf_.Normalize(Perpendicular(plane.normal));
	perpendiculars[1] = { -perpendiculars[0].x,perpendiculars[0].y,-perpendiculars[0].z };
	perpendiculars[2] = vf_.Cross(plane.normal, perpendiculars[0]);
	perpendiculars[3] = { -perpendiculars[2].x,-perpendiculars[2].y,-perpendiculars[2].z };

	Vector3 points[4];
	for (int32_t index = 0; index < 4; ++index) {
		Vector3 extend = vf_.Multiply(perpendiculars[index], 2.0f);
		Vector3 point = vf_.Add(center, extend);
		points[index] = amf_.Transform(amf_.Transform(point, viewProjectionMatrix), viewportMatrix);
	}

	Novice::DrawLine((int)points[0].x, (int)points[0].y, (int)points[2].x, (int)points[2].y, color);
	Novice::DrawLine((int)points[0].x, (int)points[0].y, (int)points[3].x, (int)points[3].y, color);
	Novice::DrawLine((int)points[1].x, (int)points[1].y, (int)points[2].x, (int)points[2].y, color);
	Novice::DrawLine((int)points[1].x, (int)points[1].y, (int)points[3].x, (int)points[3].y, color);
}

Vector3 DrawPlane::Perpendicular(const Vector3& vector)
{
	if (vector.x != 0.0f || vector.y != 0.0f) {
		return{ -vector.y,vector.x,0.0f };
	}
	return { 0.0f,-vector.z,vector.y };
}
