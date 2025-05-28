#pragma once
namespace Voxedit {
class Editor {
 private:
  void newFrame();
  void drawFrame();

 public:
  void Initialize();
  void Render();
  void Tick();

 public:
  ~Editor();
};
};  // namespace Voxedit
