#ifndef _SCENE_H_
#define _SCENE_H_

#include "assimp/scene.h"
#include "geometry/geometry.h"
#include "math/math.h"
#include <unordered_map>
#include <string>

namespace acr
{

	class Object : Shape
	{
	public:
		Object(const aiNode &node, Object *parent);
		std::string name;
		
		int index;
		int parentIndex;
		
		vector<int> children;
		vector<int> meshes;
		math::mat4 globalTransform;
		math::mat4 localTransform;
		math::mat4 globalNormalTransform;

		math::mat4 globalInverseTransform;
		math::mat4 globalInverseNormalTransform;
		
		virtual bool intersect(const Ray &r, HitInfo &info);
	};

	class Camera
	{
	public:
		Camera(const aiCamera &camera);
		float aspectRatio;
		float horizontalFOV;
		math::mat4 globalTransform;
	};

	class Light
	{
	public:
		Light(const aiLight &aiLight);
		
		enum Type
		{
			POINT,
			DIRECTIONAL,
			SPOT
		}
		
		Type type;
		
		Color3 ambient;
		Color3 diffuse;
		Color3 specular;

		math::vec3 position;
		math::vec3 direction;

		float attConstant;
		float attLinear;
		float attQuadratic;

		float innerConeAngle;
		float outerConeAngle;
		
		virtual float getFlux(math::vec3 position);
	};
	
	class Scene : Shape
	{
	public:
		struct Args
		{
			const char* filePath;
		};

		Scene(const aiScene *scene);
		Scene(const Args &args);
		~Scene();

		virtual bool intersect(const Ray& r, HitInfo &info);
	private:
		void loadScene(const aiScene* scene);
		void loadObject(const aiNode* node, Object* parent);
		void loadLights(const aiScene* scene);
		void loadMaterials(const aiScene* scene);
		void loadCamera(const aiScene* scene);
		void loadMeshes(const aiScene* scene);
		void getMathMatrix(aiMatrix4x4& aiMatrix, math::mat4& mathMat);

		std::unordered_map<std::string, Light*> light_map;
		std::unordered_map<std::string, Camera*> camera_map;

		vector<Object>		objects;
		vector<Material>	materials;
		vector<Mesh>			meshes;
		vector<Light>			lights;
		
		int rootObject;
		Camera camera;
	
	};

} // namespace acr

#endif //_SCENE_H_
