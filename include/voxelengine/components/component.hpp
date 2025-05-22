#pragma once
#include <memory>
namespace VoxelEngine {
class Object;
class Component;
template <class Type>
concept DerivedFromComponent = std::is_base_of_v<Component, Type>;

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
  Object* owner;

 protected:
 public:
  inline Object* getOwner() const { return owner; }

  virtual inline void tick() {};

  virtual inline bool isUnique() { return false; }

  virtual inline ComponentType getType() const {
    return ComponentType::TRANSFORM;
  }

  template <DerivedFromComponent Type, typename... Args>
  static std::shared_ptr<Type> createComponent(Args... args);
};

template <DerivedFromComponent Type, typename... Args>
std::shared_ptr<Type> Component::createComponent(Args... args) {
  return std::make_shared<Type>(args...);
}
};  // namespace VoxelEngine
