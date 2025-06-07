#pragma once
#include "voxelengine/components/component.hpp"
namespace VoxelEngine {
class Chunk : public Component {
  MAKE_UNIQUE_COMPONENT();
  MAKE_COMPONENT_TYPE(CHUNK);

 public:
  int size;
  // TODO: Reference to a block data structure

 private:
 public:
  void Tick() override;

 public:
  inline Chunk() {};
  Chunk(int size);
};
}  // namespace VoxelEngine
