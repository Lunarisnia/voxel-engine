#pragma once
#include <memory>
#include "voxelengine/components/mesh.hpp"
namespace VoxelEngine {
class Engine {
 public:
  std::shared_ptr<Mesh> mesh;

  Engine(int width, int height, const char* title);

  void tick();
  void run();
};
}  // namespace VoxelEngine
