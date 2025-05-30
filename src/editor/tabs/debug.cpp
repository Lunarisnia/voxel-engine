#include "voxedit/tabs/debug.hpp"
#include <memory>
#include "imgui.h"
#include "voxelengine/utilities/object_primitives.hpp"
#include "voxelengine/world/world.hpp"
using namespace Voxedit;

void Debug::Tick() {
  /*ImGui::SetNextWindowSize(ImVec2(200.0f, 200.0f));*/
  /*ImGui::SetNextWindowPos(ImVec2(0.0f, 0.0f));*/
  ImGui::Begin(name.c_str(), nullptr, flags);

  ImGuiIO io = ImGui::GetIO();
  ImGui::Text("Framerate: %.1f", io.Framerate);

  if (ImGui::Button("Create Object")) {
    object = VoxelEngine::ObjectPrimitives::GenerateCube("Cube");
    VoxelEngine::World::AddObject(object);
  }

  if (object != nullptr) {
    ImGui::DragFloat3("Position", &object->transform->position.x, 0.005f);
  }

  ImGui::End();
}
