#pragma once
#include <memory>
#include <vector>
#include "glad/glad.h"
#include "voxelengine/components/component.hpp"
#include "voxelengine/material/material.hpp"
#include "voxelengine/vertex_data.hpp"
namespace VoxelEngine {
class Mesh : public Component {
  MAKE_UNIQUE_COMPONENT();
  MAKE_COMPONENT_TYPE(MESH);

 private:
  GLuint VAO, VBO;
  std::vector<VertexData> vertices;

 public:
  Mesh();
  Mesh(std::shared_ptr<Material> mat);
  std::shared_ptr<Material> material;

  void SetupMesh();
  GLuint GetVAO();
  int GetVerticeSize();
  void AddVertexData(VertexData vertexData);
};
}  // namespace VoxelEngine
