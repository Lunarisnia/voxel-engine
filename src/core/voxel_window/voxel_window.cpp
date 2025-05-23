#include "glad/glad.h"
#include "voxelengine/voxel_window/voxel_window.hpp"
#include <OpenGL/gl.h>
#include "GLFW/glfw3.h"
#include <cstdlib>
#include <iostream>

using namespace VoxelEngine;

void VoxelWindow::framebuffer_resize_callback(GLFWwindow *window, int newWidth,
                                              int newHeight) {
  glViewport(0, 0, newWidth, newHeight);
}

void VoxelWindow::error_callback(int code, const char *description) {
  std::cout << "ERROR::GLFW(" << code << "): " << description << std::endl;
}

void VoxelWindow::RegisterKeyCallback(GLFWkeyfun callback) {
  glfwSetKeyCallback(window, callback);
}

GLFWwindow *VoxelWindow::window;
const char *VoxelWindow::title;
int VoxelWindow::width;
int VoxelWindow::height;

void VoxelWindow::Initialize(int width, int height, const char *title) {
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

  VoxelWindow::width = width;
  VoxelWindow::height = height;
  glfwSetFramebufferSizeCallback(window, framebuffer_resize_callback);
}

void VoxelWindow::Render() {
  if (glfwWindowShouldClose(window)) {
    glfwTerminate();
    exit(0);
  }

  glfwSwapBuffers(window);
  glfwPollEvents();
}

GLFWwindow *VoxelWindow::GetWindow() { return VoxelWindow::window; }

VoxelWindow::~VoxelWindow() { glfwTerminate(); }
