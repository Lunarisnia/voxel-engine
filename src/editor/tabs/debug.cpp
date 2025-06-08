#include "voxedit/tabs/debug.hpp"
#include <format>
#include <memory>
#include "glm/ext/matrix_float4x4.hpp"
#include "glm/ext/vector_float3.hpp"
#include "imgui.h"
#include "voxedit/tabs/viewport.hpp"
#include "voxelengine/components/camera.hpp"
#include "voxelengine/components/chunk.hpp"
#include "voxelengine/input_manager/input_manager.hpp"
#include "voxelengine/log/logger.hpp"
#include "voxelengine/math/vec3.hpp"
#include "voxelengine/renderer/renderer.hpp"
#include "voxelengine/utilities/object_primitives.hpp"
#include "voxelengine/world/world.hpp"
using namespace Voxedit;

void Debug::Tick() {
  ImGui::Begin(name.c_str(), nullptr, flags);

  ImGuiIO io = ImGui::GetIO();
  ImGui::Text("Framerate: %.1f", io.Framerate);

  if (ImGui::Button("Create Cube")) {
    object = VoxelEngine::ObjectPrimitives::GenerateCube("Cube");
    VoxelEngine::World::AddObject(object);
  }
  if (ImGui::Button("Create Plane")) {
    object = VoxelEngine::ObjectPrimitives::GeneratePlane("Plane");
    VoxelEngine::World::AddObject(object);
  }
  if (ImGui::Button("Create Multi Voxel Cubes")) {
    int dimension = 16;
    for (int x = 0; x < dimension; x++) {
      for (int y = 0; y < dimension; y++) {
        for (int z = 0; z < dimension; z++) {
          object = VoxelEngine::ObjectPrimitives::GenerateCube(
              std::format("Cube ({},{},{})", x, y, z));
          object->transform->position = VoxelEngine::Vec3(x, y, z - 5.0f);
          VoxelEngine::World::AddObject(object);
        }
      }
    }

    VoxelEngine::Renderer::mainCamera->transform->SetRotationEuler(
        VoxelEngine::Vec3(-0.695f, -0.500, 0.00f));
    VoxelEngine::Renderer::mainCamera->transform->position =
        VoxelEngine::Vec3(-3.4f, 6.545f, 2.353f);
  }

  if (ImGui::Button("Create Chunk")) {
    object = VoxelEngine::ObjectPrimitives::GenerateChunk("Chunk", 2);
    object->transform->position.y = -2.0f;
    VoxelEngine::World::AddObject(object);
  }
  if (ImGui::Button("Toggle Block")) {
    std::shared_ptr<VoxelEngine::Chunk> chunk =
        object->GetComponent<VoxelEngine::Chunk>();
    if (chunk != nullptr) {
      VoxelEngine::Logger::Log(VoxelEngine::LogCategory::DEBUG, "Block toggled",
                               "ToggleBlock");
      chunk->SetBlockActiveState(0, 0, 0, !chunk->blocks[0][0][0].isActive);
    }
  }

  ImGui::Text("Mouse Coord: %.2f, %.2f",
              VoxelEngine::InputManager::mouse.position.x,
              VoxelEngine::InputManager::mouse.position.y);
  float xPos =
      VoxelEngine::InputManager::mouse.position.x - Viewport::position.x;
  float yPos =
      VoxelEngine::InputManager::mouse.position.y - Viewport::position.y;

  // Transforming screen space coord to world space
  VoxelEngine::Vec2 ndcMouseCoord =
      VoxelEngine::Vec2((xPos / Viewport::size.x) * 2.0f - 1.0f,
                        (yPos / Viewport::size.y) * 2.0f - 1.0f);
  std::shared_ptr<VoxelEngine::Camera> mainCamera =
      VoxelEngine::Renderer::mainCamera->GetComponent<VoxelEngine::Camera>();

  glm::mat4 inv = glm::inverse(mainCamera->GetProjectionMatrix() *
                               mainCamera->GetViewMatrix());
  glm::vec4 wSpace =
      inv * glm::vec4(ndcMouseCoord.x, -ndcMouseCoord.y, 0.5f, 1.0f);

  // Perspective division
  wSpace.w = 1.0 / wSpace.w;
  wSpace.x *= wSpace.w;
  wSpace.y *= wSpace.w;
  wSpace.z *= wSpace.w;

  if (xPos >= 0.0f && xPos <= Viewport::size.x && yPos >= 0.0f &&
      yPos <= Viewport::size.y) {
    ImGui::Text("Scaled Mouse Coord: %.2f, %.2f", xPos, yPos);
    ImGui::Text("NDC Mouse Coord: %.2f, %.2f", ndcMouseCoord.x,
                -ndcMouseCoord.y);
    ImGui::Text("World Space \nMouse Coord: %.2f, %.2f, %.2f", wSpace.x,
                wSpace.y, wSpace.z);
  }

  if (object != nullptr) {
    ImGui::DragFloat3("Position", &object->transform->position.x, 0.005f);
  }

  ImGui::End();
}
