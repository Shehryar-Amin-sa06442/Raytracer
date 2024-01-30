#include "Image.hpp"
#include <fstream>

Image::Image(int _hres, int _vres)
{
    hres = _hres;
    vres = _vres;
    colors = new RGBColor *[hres * vres];
    for (int i = 0; i < hres * vres; i++)
    {
        colors[i] = new RGBColor(0.0, 0.0, 0.0);
    }
}

Image::Image(const ViewPlane& vp)
{
    hres = vp.hres;
    vres = vp.vres;
    colors = new RGBColor *[hres * vres];
    for (int i = 0; i < hres * vres; i++)
    {
        colors[i] = new RGBColor(0.0, 0.0, 0.0);
    }
}

Image::~Image()
{
    for (int i = 0; i < hres * vres; i++)
    {
        delete colors[i];
    }
    delete[] colors;
};

void Image::set_pixel(int x, int y, const RGBColor& color)
{
    colors[y * hres + x] = new RGBColor(color);
}

void Image::write_ppm(std::string path) const
{
    std::ofstream file(path);

    file << "P3" << "\n" << hres << " " << vres << "\n" << 255 << "\n";

    for (int i = 0; i < hres * vres; i++)
    {
        file << (int)(colors[i]->r * 255) << " " << (int)(colors[i]->g * 255) << " " << (int)(colors[i]->b * 255) << "\n";
    }
    file.close();
}
