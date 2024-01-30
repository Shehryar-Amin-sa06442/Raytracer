#include "World.hpp"
#include "../utilities/Constants.hpp"

World::World()
{
    vplane = ViewPlane();
    bg_color = RGBColor();
    camera_ptr = nullptr;
    sampler_ptr = nullptr;
}


World::~World()
{
    for (auto i : geometry)
    {
        delete i;
    }

    delete camera_ptr;
    delete sampler_ptr;
}
void World::add_geometry(Geometry* geom_ptr)
{
    this->geometry.push_back(geom_ptr);
}
void World::set_camera(Camera* c_ptr)
{
    this->camera_ptr = c_ptr;
}

ShadeInfo World::hit_objects(const Ray& ray)
{
    float tmin = kHugeValue;
    ShadeInfo sr(*this);
    float t;
    Vector3D normal;
    Point3D local_hit_point;


    for (auto i : geometry)
    {

        if (i->hit(ray, t, sr) && t < tmin)
        {
            tmin = t;
            sr.material_ptr = i->get_material();
            sr.hit = true;
            normal = sr.normal;
            local_hit_point = sr.hit_point;

        }
    }

    if (sr.hit) {
        sr.t = tmin;
        sr.normal = normal;
        sr.hit_point = local_hit_point;
    }

    return sr;
}
