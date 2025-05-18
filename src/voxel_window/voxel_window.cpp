#include "glad/glad.h"
// Force
#include "GLFW/glfw3.h"
#include "voxel_window.hpp"
#include <cstdlib>
#include <iostream>

void displayGLFWError() {
  const char *description;
  int code = glfwGetError(&description);
  if (code != GLFW_NO_ERROR) {
    std::cout << "ERROR::GLFW(" << code << "): " << description << std::endl;
  }
};

void VoxelWindow::framebuffer_resize_callback(GLFWwindow *window, int newWidth,
                                              int newHeight) {
  glViewport(0, 0, newWidth, newHeight);
}

VoxelWindow::VoxelWindow(int width, int height, const char *title)
    : title(title) {
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

  window = glfwCreateWindow(width, height, title, NULL, NULL);
  if (!window) {
    displayGLFWError();
    glfwTerminate();
    return;
  }

  glfwMakeContextCurrent(window);
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    displayGLFWError();
    glfwTerminate();
    return;
  }
  glfwSetFramebufferSizeCallback(window, framebuffer_resize_callback);
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
