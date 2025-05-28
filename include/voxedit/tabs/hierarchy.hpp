#pragma once
#include <string>
#include "voxedit/tabs/editor_tab.hpp"
namespace Voxedit {
class Hierarchy : public EditorTab {
 public:
  void Tick() override;

 public:
  inline Hierarchy(const std::string &name) : EditorTab(name) {};
};
};  // namespace Voxedit
