#pragma once
#include <vector>
#include "voxelengine/block/block.hpp"
#include "voxelengine/components/component.hpp"
namespace VoxelEngine {
class Chunk : public Component {
  MAKE_UNIQUE_COMPONENT();
  MAKE_COMPONENT_TYPE(CHUNK);

 public:
  int size;
  // TODO: Reference to a block data structure
  std::vector<std::vector<std::vector<Block>>> blocks;

 private:
  void rebuild();

 public:
  void SetBlockActiveState(const int &x, const int &y, const int &z,
                           const bool &state);
  void Tick() override;

 public:
  inline Chunk() {};
  Chunk(int size);
};
}  // namespace VoxelEngine
