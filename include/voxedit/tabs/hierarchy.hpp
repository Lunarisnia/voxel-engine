#pragma once
#include <string>
#include "imgui.h"
#include "voxedit/tabs/editor_tab.hpp"
namespace Voxedit {
class Hierarchy : public EditorTab {
 public:
  static int itemIndex;

 public:
  void Tick() override;

 public:
  inline Hierarchy(const std::string &name) : EditorTab(name) {
    flags = ImGuiWindowFlags_NoCollapse;
  };
};
};  // namespace Voxedit
