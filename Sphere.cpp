#include "Sphere.hpp"
#include "math.h"
#include <cmath>
#include <sstream>
#include "../utilities/Constants.hpp"
#include "../utilities/Ray.hpp"
#include "../utilities/ShadeInfo.hpp"
#include "../utilities/BBox.hpp"

Sphere::Sphere()
    : Geometry(),
    c(0.0),
    r(0.0)
{}

Sphere::Sphere(const Point3D& c, float r) :
    Geometry(),
    c(c),
    r(r)
{}

Sphere::Sphere(const Sphere& sphere)
    : Geometry(sphere),
    c(sphere.c),
    r(sphere.r)
{}

Sphere& Sphere::operator= (const Sphere& rhs)
{
    if (this == &rhs)
        return (*this);

    Geometry::operator= (rhs);

    c = rhs.c;
    r = rhs.r;

    return (*this);
}

std::string Sphere::to_string() const {
    std::stringstream output;
    output << "c: (" << c.x << "," << c.y << "," << c.z << ")" << '\n';
    output << "r: " << r;
    return output.str();
}

bool Sphere::hit(const Ray& ray, float& t, ShadeInfo& s) const {
    Vector3D oc = ray.o - c;
    double aa = ray.d * ray.d;
    double bb = 2 * oc * ray.d;
    double cc = (oc * oc) - (r * r);
    double dis = (bb * bb) - (4 * aa * cc);

    if (dis < 0) {
        return false;
    }

    double term = std::sqrt(dis);
    double denom = 2 * aa;
    double t0 = (-bb - term) / denom;

    if (t0 > kEpsilon) {
        t = t0;
        s.normal = (oc + t * ray.d) / r;
        s.normal.normalize();
        s.hit_point = ray.o + (t * ray.d);
        s.ray = ray;
        s.t = t;
        return true;
    }

    if (t0 > kEpsilon) {
        t = t0;
        s.normal = (oc + t * ray.d) / r;
        s.normal.normalize();
        s.hit_point = ray.o + (t * ray.d);
        s.ray = ray;
        s.t = t;
        return true;
    }
    return false;
}

BBox Sphere::getBBox() const {
    Point3D pointmin(c.x - r, c.y - r, c.z - r);
    Point3D pointmax(c.x + r, c.y + r, c.z + r);
    return BBox(pointmin, pointmax);
}
