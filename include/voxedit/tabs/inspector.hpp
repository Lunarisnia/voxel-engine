#pragma once
#include <string>
#include "voxedit/tabs/editor_tab.hpp"
namespace Voxedit {
class Inspector : public EditorTab {
 public:
  void Tick() override;

 public:
  inline Inspector(const std::string &name) : EditorTab(name) {};
};
};  // namespace Voxedit
