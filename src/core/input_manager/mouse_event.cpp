#include "voxelengine/input_manager/mouse_event.hpp"
#include <memory>
#include "glm/ext/matrix_float4x4.hpp"
#include "glm/ext/vector_float4.hpp"
#include "glm/fwd.hpp"
#include "voxelengine/components/camera.hpp"
#include "voxelengine/log/logger.hpp"
#include "voxelengine/math/vec3.hpp"
#include "voxelengine/renderer/renderer.hpp"
using namespace VoxelEngine;

Vec3 MouseEvent::ToWorldPosition() {
  float xPos = position.x - Renderer::viewportPosition.x;
  float yPos = position.y - Renderer::viewportPosition.y;

  Vec2 ndcMouseCoord = Vec2((xPos / Renderer::viewportSize.x) * 2.0f - 1.0f,
                            (yPos / Renderer::viewportSize.y) * 2.0f - 1.0f);

  if (Renderer::mainCamera == nullptr) {
    Logger::Log(LogCategory::ERROR, "Main Camera is empty",
                "MouseEvent::ToWorldPosition");
    return Vec3(0.0f);
  }

  std::shared_ptr<Camera> mainCamera =
      Renderer::mainCamera->GetComponent<Camera>();
  glm::mat4 inv = glm::inverse(mainCamera->GetProjectionMatrix() *
                               mainCamera->GetViewMatrix());

  // TODO: Maybe use glReadpixels for the depth?
  glm::vec4 wSpace = inv * glm::vec4(ndcMouseCoord.toGlmVec2(), 0.0f, 1.0f);

  wSpace.w = 1.0f / wSpace.w;

  wSpace.x *= wSpace.w;
  wSpace.y *= wSpace.w;
  wSpace.z *= wSpace.w;

  return Vec3(wSpace.x, wSpace.y, wSpace.z);
}
