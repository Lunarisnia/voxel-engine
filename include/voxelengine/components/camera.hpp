#include "voxelengine/components/component.hpp"
namespace VoxelEngine {
class Camera : public Component {
  MAKE_UNIQUE_COMPONENT();
  MAKE_COMPONENT_TYPE(CAMERA);

 public:
  static void GetViewMatrix();
  static void GetProjectionMatrix();
};
}  // namespace VoxelEngine
