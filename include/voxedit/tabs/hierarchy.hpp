#pragma once
#include <map>
#include <memory>
#include <string>
#include "imgui.h"
#include "voxedit/tabs/editor_tab.hpp"
#include "voxedit/tabs/inspector.hpp"
#include "voxelengine/object/object.hpp"
#include "voxelengine/renderer/renderer.hpp"
namespace Voxedit {
class Hierarchy : public EditorTab {
 public:
  static int itemIndex;
  static std::map<uint64_t, const std::shared_ptr<VoxelEngine::Object>&>
      hierarchyItem;

 public:
  void Tick() override;

  static void AddObjectToHierarchy(
      const uint64_t& id, const std::shared_ptr<VoxelEngine::Object>& object);

 public:
  inline Hierarchy(const std::string& name) : EditorTab(name) {
    flags = ImGuiWindowFlags_NoCollapse;
    Inspector::selectedObject = VoxelEngine::Renderer::mainCamera;
  };
};
};  // namespace Voxedit
