#pragma once
#include <memory>
#include <vector>
#include "voxelengine/components/mesh.hpp"
namespace VoxelEngine {
class Renderer {
 private:
  inline static std::vector<std::shared_ptr<Mesh>> renderQueue;
  static void drawMesh(const std::shared_ptr<Mesh>& mesh);

 public:
  static void AddToRenderQueue(const std::shared_ptr<Mesh>& mesh);

  static void Initialize();
  static void Tick();

  static void Clear();
  static void SetBackgroundColor(float r, float g, float b, float a);

  static void SetViewport(int bottomLeftX, int bottomLeftY, int width,
                          int height);
};
}  // namespace VoxelEngine
