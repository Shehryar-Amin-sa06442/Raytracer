#include "Plane.hpp"
#include <string>
#include "math.h"
#include <cmath>
#include <sstream>
#include "../utilities/Ray.hpp"
#include "../utilities/ShadeInfo.hpp"
#include "../utilities/Constants.hpp"
#include "../utilities/BBox.hpp"



Plane::Plane(void)
	: Geometry(),
	a(0.0),
	n(0, 1, 0)
{}

Plane::Plane(const Point3D& pt, const Vector3D& normal)
	: Geometry(),
	a(pt),
	n(normal)
{
	n.normalize();
}

Plane::Plane(const Plane& plane)
	: Geometry(plane),
	a(plane.a),
	n(plane.n)
{}

Plane& Plane::operator= (const Plane& rhs) {
	if (this == &rhs)
		return (*this);

	Geometry::operator= (rhs);

	a = rhs.a;
	n = rhs.n;

	return (*this);
}

std::string Plane::to_string() const {
	std::stringstream output;
	output << "Point: (" << a.x << "," << a.y << "," << a.z << ")" << '\n';
	output << "Normal: (" << n.x << "," << n.y << "," << n.z << ")";
	return output.str();
}

bool Plane::hit(const Ray& ray, float& tmin, ShadeInfo& sr) const {
	float t = (a - ray.o) * n / (ray.d * n);

	if (t > kEpsilon) {
		tmin = t;
		sr.normal = n;
		sr.normal.normalize();
		sr.hit_point = ray.o + t * ray.d;
		sr.ray = ray;
		sr.t = t;

		return (true);
	}

	return(false);
}


BBox Plane::getBBox() const {
	BBox box;
	return box;
}



