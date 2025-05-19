#include "glad/glad.h"
#include "voxelengine/voxel_window/voxel_window.hpp"
#include <OpenGL/gl.h>
#include "GLFW/glfw3.h"
#include "voxelengine/input_manager/input_manager.hpp"
#include <cstdlib>
#include <iostream>
#include <memory>

using namespace VoxelEngine;

std::shared_ptr<InputManager> inputManager = std::make_shared<InputManager>();

void VoxelWindow::framebuffer_resize_callback(GLFWwindow *window, int newWidth,
                                              int newHeight) {
  glViewport(0, 0, newWidth, newHeight);
}

void VoxelWindow::error_callback(int code, const char *description) {
  std::cout << "ERROR::GLFW(" << code << "): " << description << std::endl;
}

void VoxelWindow::key_callback(GLFWwindow *window, int key, int scancode,
                               int action, int mods) {
  inputManager->pressKey(key, scancode, action, mods);
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

void renderDummyTriangle() {
  GLfloat vertices[] = {
      0.5f,  0.0f,  0.0f,  //
      0.5f,  -0.5f, 0.0f,  //
      -0.5f, -0.5f, 0.0f,
  };

  GLuint VBO;
  glGenBuffers(1, &VBO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
};

void VoxelWindow::show() {
  while (!glfwWindowShouldClose(window)) {
    glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    renderDummyTriangle();

    glfwSwapBuffers(window);
    glfwPollEvents();
  }
}

VoxelWindow::~VoxelWindow() { glfwTerminate(); }
