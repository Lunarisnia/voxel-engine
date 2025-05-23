#pragma once

namespace VoxelEngine {
class InputManager {
 public:
  static void Initialize();
  static bool GetKey(int keyCode);
};
}  // namespace VoxelEngine
