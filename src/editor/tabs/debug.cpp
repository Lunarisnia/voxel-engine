#include "voxedit/tabs/debug.hpp"
#include <format>
#include <memory>
#include "imgui.h"
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
          object = VoxelEngine::ObjectPrimitives::GeneratePlane(
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

  if (object != nullptr) {
    ImGui::DragFloat3("Position", &object->transform->position.x, 0.005f);
  }

  ImGui::End();
}
