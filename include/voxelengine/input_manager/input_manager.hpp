#pragma once
#include "voxelengine/input_manager/mouse_event.hpp"
namespace VoxelEngine {
class InputManager {
 public:
  static MouseEvent mouse;

 public:
  static void Initialize();
  static bool GetKey(int keyCode);
  static void PollMouse();
};
}  // namespace VoxelEngine
