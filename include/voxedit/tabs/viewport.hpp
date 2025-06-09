#pragma once
#include <string>
#include "ImGuizmo.h"
#include "voxedit/tabs/editor_tab.hpp"
namespace Voxedit {
class Viewport : public EditorTab {
 public:
  inline static ImGuizmo::OPERATION operation = ImGuizmo::OPERATION::TRANSLATE;
  inline static ImGuizmo::MODE mode = ImGuizmo::MODE::LOCAL;

 public:
  void Tick() override;
  void TickGizmo();

 public:
  inline Viewport(const std::string &name) : EditorTab(name) {}
};
}  // namespace Voxedit
