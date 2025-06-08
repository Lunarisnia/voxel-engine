#pragma once
#include <string>
#include "ImGuizmo.h"
#include "voxedit/tabs/editor_tab.hpp"
#include "voxelengine/math/vec2.hpp"
namespace Voxedit {
class Viewport : public EditorTab {
 public:
  inline static ImGuizmo::OPERATION operation = ImGuizmo::OPERATION::TRANSLATE;
  inline static ImGuizmo::MODE mode = ImGuizmo::MODE::LOCAL;

  inline static VoxelEngine::Vec2 position = VoxelEngine::Vec2(0.0f);
  inline static VoxelEngine::Vec2 size = VoxelEngine::Vec2(0.0f);

 public:
  void Tick() override;
  void TickGizmo();

 public:
  inline Viewport(const std::string &name) : EditorTab(name) {}
};
}  // namespace Voxedit
