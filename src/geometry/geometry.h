#ifndef _GEOMETRY_H_
#define _GEOMETRY_H_

#include "math/math.h"

namespace acr {

  struct Vertex {
    math::vec3 position;
    math::vec3 normal;
    math::vec3 color;
  };

  struct Face {
    uint32_t indices[3];
  };


  class Mesh {
    public:
      Mesh(float *positions, float *normals, float *colors, uint32_t *indices, uint32_t numVertices, uint32_t numFaces);
      ~Mesh();
    private:
      Vertex   *vertices;
      Face     *faces;
      uint32_t numVertices;
      uint32_t numFaces;

      char *data;
  };
  
} // namespace acr

#endif //_GEOMETRY_H_