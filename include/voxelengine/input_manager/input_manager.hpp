#pragma once

namespace VoxelEngine {
class InputManager {
 public:
  static void initialize();
  static bool getKey(int keyCode);
};
}  // namespace VoxelEngine
