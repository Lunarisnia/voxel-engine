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
  bool isActive = true;

 private:
  inline static uint64_t nextComponentId = 0;
  std::vector<std::shared_ptr<Component>> components;

 public:
  inline Object(std::string name) : name(name) {
    id = std::time(nullptr);
    transform = CreateComponent<Transform>();
  };

  void Tick();

  template <DerivedFromComponent Type, typename... Args>
  std::shared_ptr<Type> CreateComponent(Args... args);

  template <DerivedFromComponent Type>
  std::shared_ptr<Type> GetComponent();

  template <DerivedFromComponent Type>
  void addComponent(const std::shared_ptr<Type> &component);
};

template <DerivedFromComponent Type, typename... Args>
std::shared_ptr<Type> Object::CreateComponent(Args... args) {
  std::shared_ptr<Type> component = Component::CreateComponent<Type>(args...);
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
std::shared_ptr<Type> Object::GetComponent() {
  if constexpr (!std::is_base_of<Component, Type>::value) {
    return nullptr;
  }

  std::shared_ptr<Type> temp = Component::CreateComponent<Type>();
  for (std::shared_ptr<Component> &comp : components) {
    if (temp->GetType() == comp->GetType()) {
      return std::dynamic_pointer_cast<Type>(comp);
    }
  }
  return nullptr;
}
}  // namespace VoxelEngine
