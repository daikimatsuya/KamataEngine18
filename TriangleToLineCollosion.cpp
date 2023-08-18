#include "TriangleToLineCollosion.h"
#include "Novice.h"

bool TriangleToLineCollosion::IsCollision(const Triangle& triangle, const Segment& line)
{
    Vector3 v1 = vf_.Subtract(triangle.vertices[1], triangle.vertices[0]);
    Vector3 v2 = vf_.Subtract(triangle.vertices[2], triangle.vertices[1]);
    Vector3 v3 = vf_.Subtract(triangle.vertices[0], triangle.vertices[2]);

    Vector3 normal = vf_.Normalize(vf_.Cross(v1, v2));
    Plane plane;
    plane.normal = normal;
    plane.distance = vf_.Dot(triangle.vertices[0], normal);

    float dot = vf_.Dot(plane.normal, line.diff);
    if (dot == 0.0f) {
        return false;
    }
    float t = (plane.distance, vf_.Dot(line.origin, plane.normal)) / dot;

    Vector3 p = vf_.Add(line.origin, vf_.Multiply(line.diff, t));

    Vector3 pv1 = vf_.Subtract(p, triangle.vertices[1]);
    Vector3 pv2 = vf_.Subtract(p, triangle.vertices[2]);
    Vector3 pv3 = vf_.Subtract(p, triangle.vertices[0]);

    Vector3 cross1 = vf_.Cross(v1, pv1);
    Vector3 cross2 = vf_.Cross(v2, pv2);
    Vector3 cross3 = vf_.Cross(v3, pv3);

    if (0.0f <= vf_.Dot(cross1, normal) && 0.0f <= vf_.Dot(cross2, normal) && 0.0f <= vf_.Dot(cross3, normal)) {
        return true;
    }

    return false;
}

void TriangleToLineCollosion::Draw(const Triangle& triangle, const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewportMatrix, uint32_t color)
{
    Triangle triangle_;
    for (size_t i = 0; i < 3; i++) {
        triangle_.vertices[i] = amf_.Transform(amf_.Transform(triangle.vertices[i], viewProjectionMatrix), viewportMatrix);
    }
    Novice::DrawTriangle((int)triangle_.vertices[0].x, (int)triangle_.vertices[0].y, (int)triangle_.vertices[1].x, (int)triangle_.vertices[1].y, (int)triangle_.vertices[2].x, (int)triangle_.vertices[2].y, color, kFillModeWireFrame);
}
