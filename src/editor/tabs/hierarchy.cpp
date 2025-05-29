#include "voxedit/tabs/hierarchy.hpp"
#include <memory>
#include <string>
#include <unordered_set>
#include <vector>
#include "imgui.h"
#include "voxedit/tabs/inspector.hpp"
#include "voxelengine/object/object.hpp"
#include "voxelengine/world/world.hpp"
using namespace Voxedit;

int Hierarchy::itemIndex = 0;

std::map<uint64_t, const std::shared_ptr<VoxelEngine::Object>&>
    Hierarchy::hierarchyItem;

void Hierarchy::Tick() {
  ImGui::SetNextWindowPos(ImVec2(500.0f, 0.0f));
  ImGui::Begin("Hierarchy", nullptr, flags);

  const std::unordered_set<std::shared_ptr<VoxelEngine::Object>>& worldObjects =
      VoxelEngine::World::GetWorldObjects();

  std::vector<const char*> items;
  std::vector<std::shared_ptr<VoxelEngine::Object>> objects;
  for (std::shared_ptr<VoxelEngine::Object> object : worldObjects) {
    items.emplace_back(object->name.c_str());
    objects.emplace_back(object);
  }

  if (ImGui::ListBox("Objects", &itemIndex, items.data(), (int)items.size())) {
    Inspector::selectedObject = objects[itemIndex];
  }

  ImGui::End();
}

void Hierarchy::AddObjectToHierarchy(
    const uint64_t& id, const std::shared_ptr<VoxelEngine::Object>& object) {
  hierarchyItem.insert(std::make_pair(id, object));
};
