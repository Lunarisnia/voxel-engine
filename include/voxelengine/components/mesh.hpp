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
  GLuint VAO, VBO, EBO;
  std::vector<VertexData> vertices;
  std::vector<int> indices;

 public:
  std::shared_ptr<Material> material;

  void SetupMesh();
  void Invalidate();
  GLuint GetVAO();
  int GetVerticeSize();
  void ClearVertice();
  int GetIndiceSize();
  void AddVertexData(VertexData vertexData);
  void AddIndex(int index);

 public:
  Mesh();
  Mesh(std::shared_ptr<Material> mat);
};
}  // namespace VoxelEngine
