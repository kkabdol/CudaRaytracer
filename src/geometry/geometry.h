#ifndef _GEOMETRY_H_
#define _GEOMETRY_H_

#include "assimp/mesh.h"
#include "math/math.h"
#include "materials/materials.h"
#include "utils/vector.h"

namespace acr
{

	struct Vertex
	{
		math::vec3 position;
		math::vec3 normal;
		Color3 color;
	};

	struct Face
	{
		uint32_t indices[3];
	};

	struct Ray
	{
		math::vec3 o;
		math::vec3 d;
	};

	struct HitInfo
	{
		float t;
		Vertex point;
		uint32_t materialIndex;
	};

	class Shape
	{
	public:
		virtual bool intersect(const Ray &r, HitInfo &info) = 0;
	};


	class Mesh
	{
	public:

		__host__ __device__
		Mesh();
		
		__host__
		Mesh(const aiMesh *aiMesh);

		__host__ __device__
		~Mesh();

		bool intersect(const Ray &r, HitInfo &info);
	private:
		vector<Vertex>  vertices;
		vector<Face>    faces;

		uint32_t materialIndex;
	};

} // namespace acr

#endif //_GEOMETRY_H_
