#pragma once
#include <memory>
#include <vector>
#include "voxelengine/components/mesh.hpp"
namespace VoxelEngine {
class Renderer {
 private:
  static std::vector<const std::shared_ptr<Mesh>> renderQueue;
  static void drawMesh(const std::shared_ptr<Mesh>& mesh);

 public:
  static void addToRenderQueue(const std::shared_ptr<Mesh>& mesh);

  static void initialize();
  static void tick();

  static void clear();
  static void setBackgroundColor(float r, float g, float b, float a);

  static void setViewport(int bottomLeftX, int bottomLeftY, int width,
                          int height);
};
}  // namespace VoxelEngine
