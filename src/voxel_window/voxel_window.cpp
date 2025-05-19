#include "glad/glad.h"
#include "voxelengine/voxel_window/voxel_window.hpp"
#include <OpenGL/gl.h>
#include "GLFW/glfw3.h"
#include "voxelengine/shader/shader.hpp"
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
  Shader shader("./shaders/default/default.vert",
                "./shaders/default/default.frag");

  float vertices[] = {0.0f,  0.5f,  0.0f,  //
                      0.5f,  -0.5f, 0.0f,  //
                      -0.5f, -0.5f, 0.0f};

  GLuint VBO, VAO;
  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);

  glBindVertexArray(VAO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
  glEnableVertexAttribArray(0);

  while (!glfwWindowShouldClose(window)) {
    glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    /*glUseProgram(shaderProgram);*/
    shader.use();
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    glfwSwapBuffers(window);
    glfwPollEvents();
  }
}

VoxelWindow::~VoxelWindow() { glfwTerminate(); }
