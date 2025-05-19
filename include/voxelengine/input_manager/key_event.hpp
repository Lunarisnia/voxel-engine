#pragma once

#define KEY_EVENT_H
namespace VoxelEngine {
class KeyEvent {
 public:
  int key;
  int scancode;
  int action;
  int mods;

  KeyEvent();
};
}  // namespace VoxelEngine
