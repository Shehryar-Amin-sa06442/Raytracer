#include "BBox.hpp"
#include <sstream>
#include "../utilities/Ray.hpp"
#include "../geometry/Geometry.hpp"
#include "../utilities/Constants.hpp"

BBox::BBox(const Point3D& min, const Point3D& max)
    : pmin(min),
    pmax(max)
{}

bool BBox::hit(const Ray& ray, float& t_enter, float& t_exit) const {
    Point3D o(ray.o);
    Point3D d(ray.d.x, ray.d.y, ray.d.z);
    Point3D tMin;
    Point3D tMax;

    double a = 1.0 / d.x;
    if (a >= 0) {
        tMin.x = (pmin.x - o.x) * a;
        tMax.x = (pmax.x - o.x) * a;
    }
    else {
        tMin.x = (pmax.x - o.x) * a;
        tMax.x = (pmin.x - o.x) * a;
    }
    double b = 1.0 / d.y;
    if (b >= 0) {
        tMin.y = (pmin.y - o.y) * b;
        tMax.y = (pmax.y - o.y) * b;
    }
    else {
        tMin.y = (pmax.y - o.y) * b;
        tMax.y = (pmin.y - o.y) * b;
    }
    double c = 1.0 / d.z;
    if (c >= 0) {
        tMin.z = (pmin.z - o.z) * c;
        tMax.z = (pmax.z - o.z) * c;
    }
    else {
        tMin.z = (pmax.z - o.z) * c;
        tMax.z = (pmin.z - o.z) * c;
    }
    if (tMin.x > tMin.y) {
        t_enter = tMin.x;
    }
    else {
        t_enter = tMin.y;
    }
    if (tMin.z > t_enter) {
        t_enter = tMin.z;
    }
    if (tMax.x < tMax.y) {
        t_exit = tMax.x;
    }
    else {
        t_exit = tMax.y;
    }
    if (tMax.z < t_exit) {
        t_exit = tMax.z;
    }
    return (t_enter < t_exit&& t_exit > kEpsilon);

}

std::string BBox::to_string() const {
    std::stringstream output;
    output << "pmin: " << pmin.to_string() << '\n';
    output << "pmax: " << pmax.to_string();
    return output.str();
}

bool BBox::contains(const Point3D& p) {
    bool cont = ((p.x > pmin.x && p.x < pmax.x) && (p.y > pmin.y && p.y < pmax.y) && (p.z > pmin.z && p.z < pmax.z));
    return cont;
}

bool BBox::overlaps(Geometry* g) {
    BBox box = g->getBBox();
    return ((pmax.x > box.pmin.x) && (pmax.y > box.pmin.y) && (pmax.z > box.pmin.z));
}

bool BBox::overlaps(const BBox& b) {
    return ((pmax.x > b.pmin.x) && (pmax.y > b.pmin.y) && (pmax.z > b.pmin.z));
}


void BBox::extend(Geometry* g) {
    this->pmin = min(g->getBBox().pmin, pmin);
    this->pmax = max(g->getBBox().pmax, pmax);
}

void BBox::extend(const BBox& b) {
    this->pmin = min(b.pmin, pmin);
    this->pmax = max(b.pmax, pmax);
}
