#include "Cosine.hpp"

Cosine::Cosine(){}
Cosine::Cosine(float c)
    : color(c, c, c)
{}

Cosine::Cosine(float _r, float _g, float _b)
    : color(_r, _g, _b) {}

Cosine::Cosine(const RGBColor& c)
    : color(c.r, c.g, c.b) {}


Cosine::Cosine(const Cosine& other) :
    color(other.color)
{}

Cosine& Cosine::operator=(const Cosine& rhs) {
    if (this == &rhs) {
        return *this;
    }
    Material::operator= (rhs);

    color = rhs.color;

    return (*this);
}

RGBColor Cosine::shade(const ShadeInfo& sinfo) const {
    return color * (sinfo.normal * -sinfo.ray.d);
}