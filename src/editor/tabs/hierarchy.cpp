#include "voxedit/tabs/hierarchy.hpp"
#include <memory>
#include <string>
#include <unordered_set>
#include <vector>
#include "imgui.h"
#include "voxelengine/object/object.hpp"
#include "voxelengine/world/world.hpp"
using namespace Voxedit;

int Hierarchy::itemIndex = 0;

void Hierarchy::Tick() {
  ImGui::SetNextWindowPos(ImVec2(500.0f, 0.0f));
  ImGui::Begin("Hierarchy", nullptr, flags);

  const std::unordered_set<std::shared_ptr<VoxelEngine::Object>>& worldObjects =
      VoxelEngine::World::GetWorldObjects();

  std::vector<const char*> items;
  for (std::shared_ptr<VoxelEngine::Object> object : worldObjects) {
    items.emplace_back(object->name.c_str());
  }

  if (ImGui::ListBox("Objects", &itemIndex, items.data(), (int)items.size())) {
    // TODO: send this information to the editor for the transform inspector
  }

  ImGui::End();
}
