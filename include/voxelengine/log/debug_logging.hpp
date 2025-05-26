#pragma once
#include <iostream>
#include "glm/ext/matrix_float4x4.hpp"
#include "glm/ext/vector_float3.hpp"
/*#include <glm/gtc/matrix_transform.hpp>*/
namespace VoxelEngine {
class DebugLogger {
 public:
  inline static void Matrix4x4(glm::mat4 mat4) {
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        std::cout << mat4[i][j] << " ";
      }
      std::cout << std::endl;
    }
  }

  inline static void Vec3(glm::vec3 vec) {
    std::cout << "X: " << vec.x << " Y: " << vec.y << " Z: " << vec.z
              << std::endl;
  }
};
}  // namespace VoxelEngine
