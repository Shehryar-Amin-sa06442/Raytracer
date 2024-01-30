#include "ShadeInfo.hpp"

ShadeInfo::ShadeInfo(const World& wr)
	: hit(false),
	hit_point(),
	material_ptr(NULL),
	normal(),
	w(&wr), 
	ray(),
	depth(0),
	t(0)  
{}
