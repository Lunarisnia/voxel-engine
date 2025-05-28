#pragma once
#include <memory>
#include <vector>
#include "voxedit/tabs/editor_tab.hpp"
namespace Voxedit {
class Editor {
 private:
  std::vector<std::shared_ptr<EditorTab>> tabs;

 private:
  void newFrame();
  void drawFrame();

 public:
  void Initialize();
  void Render();
  void Tick();

  template <DerivedFromEditorTab Type, typename... Args>
  inline void CreateTab(Args... args) {
    std::shared_ptr<Type> tab = std::make_shared<Type>(args...);
    tabs.emplace_back(tab);
  };

 public:
  ~Editor();
};
};  // namespace Voxedit
