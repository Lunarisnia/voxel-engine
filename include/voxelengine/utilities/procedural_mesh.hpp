#pragma once
#include <memory>
#include "voxelengine/components/mesh.hpp"
namespace VoxelEngine {
class ProceduralMesh {
 public:
  static void GenerateCubeMesh(std::shared_ptr<Mesh>& mesh);
  static void GeneratePlaneMesh(std::shared_ptr<Mesh>& mesh);
};
}  // namespace VoxelEngine
