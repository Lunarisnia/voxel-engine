#ifndef VOXEL_WINDOW_H
#define VOXEL_WINDOW_H
#include "GLFW/glfw3.h"
namespace VoxelEngine {
class VoxelWindow {
 private:
  GLFWwindow *window;

  static void framebuffer_resize_callback(GLFWwindow *window, int newWidth,
                                          int newHeight);
  static void error_callback(int code, const char *description);
  static void key_callback(GLFWwindow *window, int key, int scancode,
                           int action, int mods);

 public:
  const char *title;
  int width, height;
  VoxelWindow(int width, int height, const char *title);
  ~VoxelWindow();

  void show();
};
}  // namespace VoxelEngine
#endif
