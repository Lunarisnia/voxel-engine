#pragma once
#include <memory>
#include <string>
#include "voxedit/tabs/editor_tab.hpp"
#include "voxelengine/math/vec3.hpp"
#include "voxelengine/object/object.hpp"
namespace Voxedit {
class Inspector : public EditorTab {
 public:
  static std::shared_ptr<VoxelEngine::Object> selectedObject;

 public:
  void Tick() override;
  void DrawComponents();
  void DrawTransform();

 public:
  inline Inspector(const std::string &name) : EditorTab(name) {};
};
};  // namespace Voxedit
