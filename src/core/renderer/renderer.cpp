#include "glad/glad.h"
#include "voxelengine/renderer/renderer.hpp"
#include <memory>
#include "voxelengine/log/logger.hpp"
#include "voxelengine/object/object.hpp"
#include "voxelengine/voxel_window/voxel_window.hpp"
using namespace VoxelEngine;

void Renderer::Initialize() {
  int width = VoxelWindow::width;
  int height = VoxelWindow::height;

#if defined(WIN32)
  SetViewport(0, 0, width, height);
#else
  SetViewport(0, 0, width * 2, height * 2);
#endif

  glEnable(GL_DEPTH_TEST);

  Logger::Log(LogCategory::INFO, "Initialized Renderer",
              "Renderer::Initialize");
}

void Renderer::AddToRenderQueue(const std::shared_ptr<Mesh>& mesh) {
  renderQueue.emplace_back(mesh);
}

void Renderer::drawMesh(const std::shared_ptr<Mesh>& mesh) {
  Object* owner = mesh->GetOwner();
  if (!owner->isActive) {
    return;
  }

  mesh->material->Use();
  mesh->material->SetMatrix4x4("transform",
                               owner->transform->GetTransformMatrix());

  glBindVertexArray(mesh->GetVAO());
  glDrawArrays(GL_TRIANGLES, 0, mesh->GetVerticeSize());
}

void Renderer::SetBackgroundColor(float r, float g, float b, float a) {
  glClearColor(r, g, b, a);
}

void Renderer::Clear() { glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); }

void Renderer::SetViewport(int bottomLeftX, int bottomLeftY, int width,
                           int height) {
  glViewport(bottomLeftX, bottomLeftY, width, height);
}

void Renderer::Tick() {
  for (const std::shared_ptr<Mesh>& mesh : renderQueue) {
    drawMesh(mesh);
  }
}
