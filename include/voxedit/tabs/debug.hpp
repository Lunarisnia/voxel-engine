#pragma once
#include <memory>
#include "imgui.h"
#include "voxedit/tabs/editor_tab.hpp"
#include "voxelengine/object/object.hpp"
namespace Voxedit {
class Debug : public EditorTab {
  // TODO: position this elsewhere
 private:
  std::shared_ptr<VoxelEngine::Object> object;

 public:
  void Tick() override;

 public:
  inline Debug(const std::string &name) : EditorTab(name) {
    flags = ImGuiWindowFlags_NoCollapse;
  };
};
};  // namespace Voxedit
