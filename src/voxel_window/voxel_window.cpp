#include "glad/glad.h"
// Force
#include "GLFW/glfw3.h"
#include "voxel_window.hpp"
#include <cstdlib>
#include <iostream>

void VoxelWindow::framebuffer_resize_callback(GLFWwindow *window, int newWidth,
                                              int newHeight) {
  glViewport(0, 0, newWidth, newHeight);
}

void VoxelWindow::error_callback(int code, const char *description) {
  std::cout << "ERROR::GLFW(" << code << "): " << description << std::endl;
}

void VoxelWindow::key_callback(GLFWwindow *window, int key, int scancode,
                               int action, int mods) {
  std::cout << "Key: " << key << std::endl;
  std::cout << "Scancode: " << scancode << std::endl;
  std::cout << "Action: " << action << std::endl;
  std::cout << "Mods: " << mods << std::endl;
}

VoxelWindow::VoxelWindow(int width, int height, const char *title)
    : title(title) {
  glfwSetErrorCallback(error_callback);

  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

  window = glfwCreateWindow(width, height, title, NULL, NULL);
  if (!window) {
    glfwTerminate();
    return;
  }

  glfwMakeContextCurrent(window);
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    glfwTerminate();
    return;
  }

  glfwSetFramebufferSizeCallback(window, framebuffer_resize_callback);
  glfwSetKeyCallback(window, key_callback);
}

void VoxelWindow::show() {
  while (!glfwWindowShouldClose(window)) {
    glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glfwSwapBuffers(window);
    glfwPollEvents();
  }
}

VoxelWindow::~VoxelWindow() { glfwTerminate(); }
