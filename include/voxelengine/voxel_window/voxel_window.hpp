#pragma once

#include "GLFW/glfw3.h"
namespace VoxelEngine {
class VoxelWindow {
 private:
  static GLFWwindow *window;

  static void framebuffer_resize_callback(GLFWwindow *window, int newWidth,
                                          int newHeight);
  static void error_callback(int code, const char *description);

 public:
  static const char *title;
  static int width, height;

  static void initialize(int width, int height, const char *title);
  static void render();
  static void registerKeyCallback(GLFWkeyfun callback);

  ~VoxelWindow();
};
}  // namespace VoxelEngine
