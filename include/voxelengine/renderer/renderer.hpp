#pragma once
#include <memory>
#include "voxelengine/components/mesh.hpp"
namespace VoxelEngine {
class Renderer {
 public:
  static void initialize();

  static void drawMesh(const std::shared_ptr<Mesh>& mesh);

  static void clear();
  static void setBackgroundColor(float r, float g, float b, float a);

  static void setViewport(int bottomLeftX, int bottomLeftY, int width,
                          int height);
};
}  // namespace VoxelEngine
