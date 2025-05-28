#pragma once
#include <string>
#include <type_traits>
#include "imgui.h"
namespace Voxedit {
class EditorTab;
template <class Type>
concept DerivedFromEditorTab = std::is_base_of_v<EditorTab, Type>;

class EditorTab {
 protected:
  std::string name = "My Tab";
  int flags = ImGuiWindowFlags_NoCollapse;

 public:
  inline virtual void Tick() {};

 public:
  inline EditorTab(const std::string &name) : name(name) {};
  inline virtual ~EditorTab() {};
};
};  // namespace Voxedit
