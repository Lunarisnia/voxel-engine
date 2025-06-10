#pragma once
#include "voxelengine/components/component.hpp"
namespace VoxelEngine {
class Script : public Component {
 public:
  void Tick() override;

 public:
  inline Script() {};
};
};  // namespace VoxelEngine
