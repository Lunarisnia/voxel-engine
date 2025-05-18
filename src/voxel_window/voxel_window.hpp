#ifndef VOXEL_WINDOW_H
#define VOXEL_WINDOW_H
#include "GLFW/glfw3.h"
class VoxelWindow {
private:
  GLFWwindow *window;

  static void framebuffer_resize_callback(GLFWwindow *window, int newWidth,
                                          int newHeight);

public:
  const char *title;
  int width, height;
  VoxelWindow(int width, int height, const char *title);
  ~VoxelWindow();

  void show();
};
#endif
