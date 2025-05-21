#pragma once
#include <memory>
#include "voxelengine/components/mesh.hpp"
#include "voxelengine/object/object.hpp"
namespace VoxelEngine {
class Engine {
 public:
  Object obj = Object("test");
  std::shared_ptr<Mesh> mesh;

  Engine(int width, int height, const char* title);

  void tick();
  void run();
};
}  // namespace VoxelEngine
