#pragma once
#include <memory>
#include <vector>
#include "voxelengine/components/mesh.hpp"
#include "voxelengine/components/mesh.hpp"
#include "voxelengine/framebuffer/framebuffer.hpp"
#include "voxelengine/renderbuffer/renderbuffer.hpp"
#include "voxelengine/texture/texture.hpp"
namespace VoxelEngine {
class Renderer {
 private:
  static std::vector<std::shared_ptr<Mesh>> renderQueue;
  static std::unique_ptr<Framebuffer> framebuffer;
  static std::unique_ptr<Renderbuffer> renderbuffer;
  static std::shared_ptr<Texture> renderTexture;
  static void drawMesh(const std::shared_ptr<Mesh>& mesh);

 public:
  static std::shared_ptr<Object> mainCamera;

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
