#include "voxelengine/components/camera.hpp"
#include "glm/ext/matrix_clip_space.hpp"
#include "glm/ext/matrix_float4x4.hpp"
#include "glm/ext/matrix_transform.hpp"
#include "glm/trigonometric.hpp"
#include "voxelengine/object/object.hpp"
#include "voxelengine/voxel_window/voxel_window.hpp"
using namespace VoxelEngine;

// TODO: abstract mat4
glm::mat4 Camera::GetViewMatrix() {
  Object *o = owner;
  Vec3 up = o->transform->GetUpVector();
  Vec3 front = o->transform->GetForwardVector();

  glm::mat4 view =
      glm::lookAt(o->transform->position.ToGlm(),
                  o->transform->position.ToGlm() + front.ToGlm(), up.ToGlm());

  return view;
}

glm::mat4 Camera::GetProjectionMatrix() {
  glm::mat4 projection = glm::perspective(
      glm::radians(fov), (float)VoxelWindow::width / (float)VoxelWindow::height,
      near, far);

  return projection;
}
