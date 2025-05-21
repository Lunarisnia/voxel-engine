#pragma once

#include <cstdint>
#include <memory>
#include <string>
#include <type_traits>
#include <vector>
#include "voxelengine/components/component.hpp"
#include "voxelengine/components/transform.hpp"

namespace VoxelEngine {
class Object {
 public:
  uint64_t id;
  std::string name;
  std::shared_ptr<Transform> transform;

 private:
  inline static uint64_t nextComponentId = 0;
  std::vector<std::shared_ptr<Component>> components;

 public:
  Object(std::string name);

  template <DerivedFromComponent Type, typename... Args>
  std::shared_ptr<Type> createComponent(Args... args);

  template <DerivedFromComponent Type>
  std::shared_ptr<Type> getComponent();

  template <DerivedFromComponent Type>
  void addComponent(const std::shared_ptr<Type> &component);
};

template <DerivedFromComponent Type, typename... Args>
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

template <DerivedFromComponent Type>
void Object::addComponent(const std::shared_ptr<Type> &component) {
  components.push_back(component);
}

template <DerivedFromComponent Type>
std::shared_ptr<Type> Object::getComponent() {
  if constexpr (!std::is_base_of<Component, Type>::value) {
    return nullptr;
  }

  std::shared_ptr<Type> temp = Component::createComponent<Type>();
  for (std::shared_ptr<Component> &comp : components) {
    if (temp->getType() == comp->getType()) {
      return std::dynamic_pointer_cast<Type>(comp);
    }
  }
  return nullptr;
}
}  // namespace VoxelEngine
