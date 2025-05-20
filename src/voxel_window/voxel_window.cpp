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

void VoxelWindow::registerKeyCallback(GLFWkeyfun callback) {
  glfwSetKeyCallback(window, callback);
}

GLFWwindow *VoxelWindow::window;
const char *VoxelWindow::title;
int VoxelWindow::width;
int VoxelWindow::height;

void VoxelWindow::initialize(int width, int height, const char *title) {
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
}

void VoxelWindow::render() {
  if (glfwWindowShouldClose(window)) {
    glfwTerminate();
  }

  /*glUseProgram(shaderProgram);*/
  /*mesh.bindVertexArray();*/
  glDrawArrays(GL_TRIANGLES, 0, 3);

  glfwSwapBuffers(window);
  glfwPollEvents();
}

VoxelWindow::~VoxelWindow() { glfwTerminate(); }
