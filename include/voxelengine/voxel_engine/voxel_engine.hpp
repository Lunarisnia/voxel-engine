#include "voxelengine/voxel_window/voxel_window.hpp"
#ifndef VOXEL_ENGINE_H
namespace VoxelEngine {
class Engine {
 private:
  VoxelWindow window;
  static void key_callback(GLFWwindow* window, int key, int scancode,
                           int action, int mods);

 public:
  Engine(int width, int height, const char* title);

  void run();
};
}  // namespace VoxelEngine
#endif
