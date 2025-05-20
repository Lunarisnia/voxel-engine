#pragma once
#include <memory>
namespace VoxelEngine {
class Object;

enum ComponentType {
  TRANSFORM,
  MESH,
};

#define MAKE_UNIQUE_COMPONENT()             \
 public:                                    \
  virtual inline bool isUnique() override { \
    return true;                            \
  }  // namespace VoxelEngine

#define MAKE_COMPONENT_TYPE(type)                         \
 public:                                                  \
  virtual inline ComponentType getType() const override { \
    return ComponentType::type;                           \
  }

class Component {
  friend class Object;

 private:
  uint64_t id = 0;
  ComponentType type;

 protected:
  Object* owner;

 public:
  inline Object* getOwner() const { return owner; }

  virtual inline bool isUnique() { return false; }

  virtual inline ComponentType getType() const {
    return ComponentType::TRANSFORM;
  }

  template <class Type, typename... Args>
  static std::shared_ptr<Type> createComponent(Args... args);
};

template <class Type, typename... Args>
std::shared_ptr<Type> Component::createComponent(Args... args) {
  if (!std::is_base_of<Component, Type>()) {
    return nullptr;
  }

  return std::make_shared<Type>(args...);
}
};  // namespace VoxelEngine
