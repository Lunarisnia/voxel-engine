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

 private:
  GLuint VAO, VBO;
  std::vector<VertexData> vertices;

 public:
  std::shared_ptr<Material> material;

  void setupMesh();
  void bindVertexArray();
};
}  // namespace VoxelEngine
