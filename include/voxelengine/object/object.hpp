#pragma once

#include <cstdint>
#include <memory>
#include <string>
#include <vector>
#include "voxelengine/components/component.hpp"
#include "voxelengine/components/transform.hpp"

namespace VoxelEngine {
class Object {
 public:
  std::string name;
  std::shared_ptr<Transform> transform;

 private:
  inline static uint64_t nextComponentId = 0;
  std::vector<std::shared_ptr<Component>> components;

 public:
  Object();

  template <class Type, typename... Args>
  std::shared_ptr<Type> createComponent(Args... args);

  template <class Type>
  void addComponent(const std::shared_ptr<Type> &component);
};

template <class Type, typename... Args>
std::shared_ptr<Type> Object::createComponent(Args... args) {
  std::shared_ptr<Type> component = Component::createComponent<Type>(args...);
  if (component == nullptr) {
    return nullptr;
  }

  component->id = nextComponentId++;
  component->owner = this;

  addComponent(component);

  return component;
}

template <class Type>
void Object::addComponent(const std::shared_ptr<Type> &component) {
  components.push_back(component);
}
}  // namespace VoxelEngine
