a.out: Parallel.o Perspective.o Geometry.o Plane.o Sphere.o Triangle.o Cosine.o Sampler.o Simple.o BBox.o Image.o Point3D.o Ray.o RGBColor.o ShadeInfo.o Vector3D.o ViewPlane.o World.o raytracer.o buildChapter14.o
	g++ Parallel.o Perspective.o Geometry.o Plane.o Sphere.o Triangle.o Cosine.o Sampler.o Simple.o BBox.o Image.o Point3D.o Ray.o RGBColor.o ShadeInfo.o Vector3D.o ViewPlane.o World.o raytracer.o buildChapter14.o

Parallel.o: Camera.hpp Parallel.hpp Parallel.cpp
	g++ -c Parallel.cpp

Perspective.o: Camera.hpp Perspective.hpp Perspective.cpp
	g++ -c Perspective.cpp

Geometry.o: Geometry.hpp Geometry.cpp
	g++ -c Geometry.cpp

Plane.o: Plane.hpp Plane.cpp 
	g++ -c Plane.cpp

Sphere.o: Sphere.hpp Sphere.cpp 
	g++ -c Sphere.cpp

Triangle.o: Triangle.hpp Triangle.cpp 
	g++ -c Triangle.cpp

Cosine.o: Cosine.hpp Cosine.cpp Material.hpp 
	g++ -c Cosine.cpp

Sampler.o: Sampler.hpp Sampler.cpp 
	g++ -c Sampler.cpp

Simple.o: Simple.hpp Simple.cpp 
	g++ -c Simple.cpp

BBox.o: BBox.hpp BBox.cpp 
	g++ -c BBox.cpp

Image.o: Image.hpp Image.cpp 
	g++ -c Image.cpp

Point3D.o: Point3D.hpp Point3D.cpp 
	g++ -c Point3D.cpp

Ray.o: Ray.hpp Ray.cpp 
	g++ -c Ray.cpp

RGBColor.o: RGBColor.hpp RGBColor.cpp 
	g++ -c RGBColor.cpp

ShadeInfo.o: ShadeInfo.hpp ShadeInfo.cpp 
	g++ -c ShadeInfo.cpp

Vector3D.o: Vector3D.hpp Vector3D.cpp 
	g++ -c Vector3D.cpp

ViewPlane.o: ViewPlane.hpp ViewPlane.cpp 
	g++ -c ViewPlane.cpp

World.o: World.hpp World.cpp 
	g++ -c World.cpp

raytracer.o: raytracer.cpp 
	g++ -c raytracer.cpp

buildChapter14.o: buildChapter14.cpp
	g++ -c buildChapter14.cpp

clean:
	rm *.o a.out

run: a.out
	./a.out