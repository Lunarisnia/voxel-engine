#include "voxelengine/input_manager/input_manager.hpp"

InputManager::InputManager() {}

void InputManager::pressKey(int key, int scancode, int action, int mods) {
  KeyEvent ke;
  ke.key = key;
  ke.scancode = scancode;
  ke.action = action;
  ke.mods = mods;
  keys[key] = ke;
}
