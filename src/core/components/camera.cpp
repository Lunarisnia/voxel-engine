#include "voxelengine/components/camera.hpp"
#include "glm/ext/matrix_clip_space.hpp"
#include "glm/ext/matrix_float4x4.hpp"
#include "glm/ext/matrix_transform.hpp"
#include "glm/ext/vector_float3.hpp"
#include "glm/trigonometric.hpp"
#include "voxelengine/object/object.hpp"
#include "voxelengine/voxel_window/voxel_window.hpp"
using namespace VoxelEngine;

glm::mat4 Camera::GetViewMatrix() {
  Object *o = owner;
  glm::vec3 up = o->transform->GetUpVector();
  glm::vec3 front = o->transform->GetForwardVector();

  glm::mat4 view = glm::lookAt(position, position + front, up);

  return view;
}

glm::mat4 Camera::GetProjectionMatrix() {
  glm::mat4 projection = glm::perspective(
      glm::radians(fov), (float)VoxelWindow::width / (float)VoxelWindow::height,
      near, far);

  return projection;
}
