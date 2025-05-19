#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H
#include "key_event.hpp"
namespace VoxelEngine {
class InputManager {
 private:
  KeyEvent keys[349];

 public:
  InputManager();

  void pressKey(int key, int scancode, int action, int mods);
};
}  // namespace VoxelEngine
#endif
