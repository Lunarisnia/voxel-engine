#pragma once
#include <memory>
#include "voxelengine/components/chunk.hpp"
#include "voxelengine/components/mesh.hpp"
namespace VoxelEngine {
class ProceduralMesh {
 public:
  static void GenerateCubeMesh(std::shared_ptr<Mesh>& mesh);
  static void GeneratePlaneMesh(std::shared_ptr<Mesh>& mesh);
  static void GenerateChunk(std::shared_ptr<Mesh>& mesh,
                            std::shared_ptr<Chunk>& chunk);
};
}  // namespace VoxelEngine
