#pragma once
namespace Voxedit {
class Editor {
 private:
  void newFrame();
  void drawFrame();

 public:
  void Initialize();
  void Render();

  ~Editor();

  void Tick();
};
};  // namespace Voxedit
