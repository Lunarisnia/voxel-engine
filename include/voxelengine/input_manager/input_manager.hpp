#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H
#include "GLFW/glfw3.h"
#include "key_event.hpp"
namespace VoxelEngine {
class InputManager {
 private:
  static KeyEvent keys[349];
  static void key_callback(GLFWwindow* window, int key, int scancode,
                           int action, int mods);

 public:
  static void initialize();
  static void pressKey(int key, int scancode, int action, int mods);
};
}  // namespace VoxelEngine
#endif
