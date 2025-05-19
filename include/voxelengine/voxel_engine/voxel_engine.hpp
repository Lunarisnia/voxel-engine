#include "voxelengine/voxel_window/voxel_window.hpp"
#ifndef VOXEL_ENGINE_H
namespace VoxelEngine {
class Engine {
 private:
  VoxelWindow window;

 public:
  Engine(int width, int height, const char* title);
  void run();
};
}  // namespace VoxelEngine
#endif
