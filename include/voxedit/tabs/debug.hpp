#pragma once
#include "voxedit/tabs/editor_tab.hpp"
namespace Voxedit {
class Debug : public EditorTab {
 public:
  void Tick() override;

 public:
  inline Debug(const std::string &name) : EditorTab(name) {};
};
};  // namespace Voxedit
