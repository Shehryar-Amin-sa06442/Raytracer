#include "Simple.hpp"
#include "../utilities/Ray.hpp"
#include "../world/ViewPlane.hpp"
#include "../cameras/Camera.hpp"


Simple::Simple(Camera* c_ptr, ViewPlane* v_ptr) {

    camera_ptr = c_ptr;
    viewplane_ptr = v_ptr;
}

Simple::Simple(const Simple& camera)
    : Sampler(camera.camera_ptr, camera.viewplane_ptr)
{}



Simple& Simple::operator=(const Simple& rhs) {
    if (this == &rhs) {
        return (*this);
    }
    camera_ptr = rhs.camera_ptr;
    viewplane_ptr = rhs.viewplane_ptr;
    return (*this);

}

std::vector<Ray> Simple::get_rays(int px, int py) const {

    std::vector<Ray> rayArray;
    Ray r;
    float length = (viewplane_ptr->bottom_right.x - viewplane_ptr->top_left.x) / (viewplane_ptr->hres);
    float width = (viewplane_ptr->bottom_right.y - viewplane_ptr->top_left.y) / (viewplane_ptr->vres);
    float x = viewplane_ptr->top_left.x + length * px + length / 2;
    float y = viewplane_ptr->top_left.y + width * py + width / 2;;
    float z = viewplane_ptr->top_left.z;
    r.w = 1;
    r.o = Point3D(x, y, z);
    r.d = camera_ptr->get_direction(Point3D(x, y, z));
    rayArray.push_back(r);
    return rayArray;
}
