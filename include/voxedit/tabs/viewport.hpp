#pragma once
#include <string>
#include "voxedit/tabs/editor_tab.hpp"
namespace Voxedit {
class Viewport : public EditorTab {
 public:
  void Tick() override;
  void TickGizmo();

 public:
  inline Viewport(const std::string &name) : EditorTab(name) {}
};
}  // namespace Voxedit
