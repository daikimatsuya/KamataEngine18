#include "LineToPlaneCollision.h"

bool LineToPlaneCollision::IsCollosion(const Segment& line, const Plane& plane){

	float distance = vf_.Dot(plane.normal, line.diff);

	if (distance == 0.0f) {
		return false;
	}
	float t = (plane.distance - vf_.Dot(line.origin, plane.normal)) / distance;
	if (t < 0.0f || 1.0f < t) {
		return false;
	}
	return true;
}
