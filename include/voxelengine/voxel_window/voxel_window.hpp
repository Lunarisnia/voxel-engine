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

 public:
  const char *title;
  int width, height;
  VoxelWindow(int width, int height, const char *title);
  ~VoxelWindow();

  void show();
  void registerKeyCallback(GLFWkeyfun callback);
};
}  // namespace VoxelEngine
#endif
