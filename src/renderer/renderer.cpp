#include "glad/glad.h"
#include "voxelengine/renderer/renderer.hpp"
#include <memory>
#include "voxelengine/voxel_window/voxel_window.hpp"
using namespace VoxelEngine;

std::vector<const std::shared_ptr<Mesh>> Renderer::renderQueue;

void Renderer::initialize() {
  int width = VoxelWindow::width;
  int height = VoxelWindow::height;

  if (__APPLE__) {
    setViewport(0, 0, width * 2, height * 2);
  } else {
    setViewport(0, 0, width, height);
  }
}

void Renderer::addToRenderQueue(const std::shared_ptr<Mesh>& mesh) {
  Renderer::renderQueue.push_back(mesh);
}

void Renderer::drawMesh(const std::shared_ptr<Mesh>& mesh) {
  mesh->material->useShader();
  glBindVertexArray(mesh->getVAO());
  glDrawArrays(GL_TRIANGLES, 0, mesh->getVerticeSize());
}

void Renderer::setBackgroundColor(float r, float g, float b, float a) {
  glClearColor(r, g, b, a);
}

void Renderer::clear() { glClear(GL_COLOR_BUFFER_BIT); }

void Renderer::setViewport(int bottomLeftX, int bottomLeftY, int width,
                           int height) {
  glViewport(bottomLeftX, bottomLeftY, width, height);
}

void Renderer::tick() {
  for (const std::shared_ptr<Mesh>& mesh : renderQueue) {
    drawMesh(mesh);
  }
}
