#pragma once
#include <string>
#include "voxelengine/components/component.hpp"
namespace VoxelEngine {
class Script : public Component {
 public:
  void Tick() override;

 public:
  inline Script() {};
  Script(const std::string &name, const std::string &path);
};
};  // namespace VoxelEngine
