#include "glad/glad.h"
#include "voxelengine/renderer/renderer.hpp"
#include <memory>
#include <vector>
#include "voxelengine/components/camera.hpp"
#include "voxelengine/log/logger.hpp"
#include "voxelengine/object/object.hpp"
#include "voxelengine/voxel_window/voxel_window.hpp"
using namespace VoxelEngine;

std::shared_ptr<Object> Renderer::mainCamera;
std::vector<std::shared_ptr<Mesh>> Renderer::renderQueue;
std::unique_ptr<Framebuffer> Renderer::framebuffer;
std::shared_ptr<Texture> Renderer::renderTexture;
std::unique_ptr<Renderbuffer> Renderer::renderbuffer;

void Renderer::Initialize() {
  int width = VoxelWindow::width;
  int height = VoxelWindow::height;

  glEnable(GL_DEPTH_TEST);

  framebuffer = std::make_unique<Framebuffer>();
  framebuffer->Bind();
  renderTexture = std::make_shared<Texture>();
  renderbuffer = std::make_unique<Renderbuffer>(width, height);

  renderTexture->SetTexture(width, height, NULL);
  framebuffer->SetTexture(renderTexture);
  if (glCheckFramebufferStatus(GL_FRAMEBUFFER) == GL_FRAMEBUFFER_COMPLETE) {
    Logger::Log(LogCategory::INFO, "Framebuffer initialized",
                "Renderer::Initialize");
  }
  framebuffer->Unbind();

#if defined(WIN32)
  SetViewport(0, 0, width, height);
#else
  SetViewport(0, 0, width * 2, height * 2);
#endif

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
  if (mainCamera != nullptr) {
    mesh->material->SetMatrix4x4(
        "view", mainCamera->GetComponent<Camera>()->GetViewMatrix());
    mesh->material->SetMatrix4x4(
        "projection",
        mainCamera->GetComponent<Camera>()->GetProjectionMatrix());
  }

  glBindVertexArray(mesh->GetVAO());
  // TODO: Find a way to do chunk with an index
  /*glDrawElements(GL_TRIANGLES, mesh->GetIndiceSize(), GL_UNSIGNED_INT, 0);*/
  glDrawArrays(GL_TRIANGLES, 0, mesh->GetVerticeSize());
  glBindVertexArray(0);
}

void Renderer::SetBackgroundColor(float r, float g, float b, float a) {
  glClearColor(r, g, b, a);
}

void Renderer::Clear() { glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); }

void Renderer::SetViewport(int bottomLeftX, int bottomLeftY, int width,
                           int height) {
  VoxelEngine::VoxelWindow::width = width;
  VoxelEngine::VoxelWindow::height = height;
  renderTexture->SetTexture(width, height, NULL);
  renderbuffer->Resize(width, height);
  glViewport(bottomLeftX, bottomLeftY, width, height);
}

void Renderer::Tick() {
  if (mainCamera == nullptr) {
    return;
  }
  for (const std::shared_ptr<Mesh>& mesh : renderQueue) {
    drawMesh(mesh);
  }
}
