#include "DrawSphereAndGrid.h"
#include "Novice.h"
#include "stdint.h"
#define _USE_MATH_DEFINES
#include "math.h"

void DrawSphereAndGrid::DrwaSphere(const Sphere& sphere, const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewPortMatrix, int color){
	const uint32_t kSubdvision = 10;
	const float kLonEvery = 2.0f*(float)M_PI / kSubdvision;//経度
	const float kLatEvery = (float)M_PI/ kSubdvision;//緯度

	for (uint32_t latIndex = 0; latIndex < kSubdvision; ++latIndex) {
		float lat = (float)-M_PI / 2.0f + kLatEvery * latIndex;
		for (uint32_t lonIndex = 0; lonIndex < kSubdvision; ++lonIndex) {
			float lon = lonIndex * kLonEvery;

			Vector3 p = { sphere.radius * (cosf((float)lat) * cosf(2.0f * (float)lon),sphere.radius * (sinf((float)lat),sphere.radius * (cosf((float)lon) * sinf(2.0f * (float)lon)))) };
			Vector3 q = { sphere.center.x + p.x,sphere.center.y + p.y,sphere.center.z + p.z };
			Vector3 t = {};

			Vector3 a, b, c;
			a = { cosf((float)M_PI + lat) * cosf(2.0f * (float)M_PI +lon),sinf((float)M_PI + lat ),cosf((float)M_PI + lat ) * sinf(2.0f * (float)M_PI + lon) };
			b = { cosf((float)M_PI + lat + kLatEvery) * cosf(2.0f * (float)M_PI + lon),sinf((float)M_PI + lat + kLatEvery),cosf((float)M_PI + lat + kLatEvery) * sinf(2.0f * (float)M_PI + lon) };
			c = { cosf((float)M_PI + lat + kLatEvery) * cosf((2.0f * (float)M_PI) + lon+kLonEvery),sinf((float)M_PI+lat + kLatEvery),cosf((float)M_PI + lat + kLatEvery) * sinf((2.0f * (float)M_PI) + lon + kLonEvery) };


			a = { a.x * sphere.radius + sphere.center.x,a.y * sphere.radius + sphere.center.y,a.z * sphere.radius + sphere.center.z };
			b = { b.x * sphere.radius + sphere.center.x,b.y * sphere.radius + sphere.center.y,b.z * sphere.radius + sphere.center.z };
			c = { c.x * sphere.radius + sphere.center.x,c.y * sphere.radius + sphere.center.y,c.z * sphere.radius + sphere.center.z };
			




			Vector3 ndcVertex1 = amf_.Transform(a , viewProjectionMatrix);
			Vector3 ndcVertex2 = amf_.Transform(b, viewProjectionMatrix);
			Vector3 ndcVertex3 = amf_.Transform(c, viewProjectionMatrix);
			Vector3 a2 = amf_.Transform(ndcVertex1, viewPortMatrix);
			Vector3 b2 = amf_.Transform(ndcVertex2, viewPortMatrix);
			Vector3 c2 = amf_.Transform(ndcVertex3, viewPortMatrix);


			Novice::DrawLine((int)a2.x, (int)a2.y, (int)b2.x, (int)b2.y, color);
			Novice::DrawLine((int)b2.x, (int)b2.y, (int)c2.x, (int)c2.y, color);
		}
	}
}

void DrawSphereAndGrid::DrawGrid(const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewPortMatrix){
	const float kGridHalfWidth = 2.0f;
	const int kSubdivision = 10;
	const float kGridEvery = (kGridHalfWidth * 2.0f) / kSubdivision;

	for (int xIndex = 0; xIndex <= kSubdivision; ++xIndex) {

		Vector3 grid1 = { 0 + kGridEvery * xIndex - (kSubdivision) / 4,0,0.0f };
		Vector3 grid2 = { 0 + kGridEvery * xIndex - (kSubdivision) / 4,0,kGridHalfWidth };
		Vector3 grid3 = { 0 + kGridEvery * xIndex - (kSubdivision) / 4,0,-kGridHalfWidth };

		Vector3 screenvirtices[3] = {};
		Vector3 ndcVertex1 = amf_.Transform(grid1, viewProjectionMatrix);
		Vector3 ndcVertex2= amf_.Transform(grid2, viewProjectionMatrix);
		Vector3 ndcVertex3 = amf_.Transform(grid3, viewProjectionMatrix);
		screenvirtices[0] = amf_.Transform(ndcVertex1, viewPortMatrix);
		screenvirtices[1] = amf_.Transform(ndcVertex2, viewPortMatrix);
		screenvirtices[2] = amf_.Transform(ndcVertex3, viewPortMatrix);

		Novice::DrawLine((int)screenvirtices[0].x, (int)screenvirtices[0].y, (int)screenvirtices[1].x, (int)screenvirtices[1].y, 0xAAAAAAFF);
		Novice::DrawLine((int)screenvirtices[0].x, (int)screenvirtices[0].y, (int)screenvirtices[2].x, (int)screenvirtices[2].y, 0xAAAAAAFF);
	}

	for (int zIndex = 0; zIndex <= kSubdivision; ++zIndex) {

		Vector3 grid1 = {0.0f,0, 0 + kGridEvery * zIndex - (kSubdivision) / 4 };
		Vector3 grid2 = {kGridHalfWidth ,0, 0 + kGridEvery * zIndex - (kSubdivision) / 4 };
		Vector3 grid3 = { -kGridHalfWidth,0, 0 + kGridEvery * zIndex - (kSubdivision) / 4 };

		Vector3 screenvirtices[3] = {};
		Vector3 ndcVertex1 = amf_.Transform(grid1, viewProjectionMatrix);
		Vector3 ndcVertex2 = amf_.Transform(grid2, viewProjectionMatrix);
		Vector3 ndcVertex3 = amf_.Transform(grid3, viewProjectionMatrix);
		screenvirtices[0] = amf_.Transform(ndcVertex1, viewPortMatrix);
		screenvirtices[1] = amf_.Transform(ndcVertex2, viewPortMatrix);
		screenvirtices[2] = amf_.Transform(ndcVertex3, viewPortMatrix);

		Novice::DrawLine((int)screenvirtices[0].x, (int)screenvirtices[0].y, (int)screenvirtices[1].x, (int)screenvirtices[1].y, 0xAAAAAAFF);
		Novice::DrawLine((int)screenvirtices[0].x, (int)screenvirtices[0].y, (int)screenvirtices[2].x, (int)screenvirtices[2].y, 0xAAAAAAFF);
	}
}
