#include "glad/glad.h"
#include "voxelengine/renderer/renderer.hpp"
#include <memory>
#include "voxelengine/object/object.hpp"
#include "voxelengine/voxel_window/voxel_window.hpp"
using namespace VoxelEngine;

void Renderer::initialize() {
  int width = VoxelWindow::width;
  int height = VoxelWindow::height;

#if defined(WIN32)
  setViewport(0, 0, width, height);
#else
  setViewport(0, 0, width * 2, height * 2);
#endif

  glEnable(GL_DEPTH_TEST);
}

void Renderer::addToRenderQueue(const std::shared_ptr<Mesh>& mesh) {
  renderQueue.emplace_back(mesh);
}

void Renderer::drawMesh(const std::shared_ptr<Mesh>& mesh) {
  mesh->material->useShader();

  Object* owner = mesh->getOwner();
  mesh->material->setMatrix4x4("transform",
                               owner->transform->getTransformMatrix());

  glBindVertexArray(mesh->getVAO());
  glDrawArrays(GL_TRIANGLES, 0, mesh->getVerticeSize());
}

void Renderer::setBackgroundColor(float r, float g, float b, float a) {
  glClearColor(r, g, b, a);
}

void Renderer::clear() { glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); }

void Renderer::setViewport(int bottomLeftX, int bottomLeftY, int width,
                           int height) {
  glViewport(bottomLeftX, bottomLeftY, width, height);
}

void Renderer::tick() {
  for (const std::shared_ptr<Mesh>& mesh : renderQueue) {
    drawMesh(mesh);
  }
}
