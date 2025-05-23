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
  virtual inline bool IsUnique() override { \
    return true;                            \
  }  // namespace VoxelEngine

#define MAKE_COMPONENT_TYPE(type)                         \
 public:                                                  \
  virtual inline ComponentType GetType() const override { \
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
  inline Object* GetOwner() const { return owner; }

  virtual inline void Tick() {};

  virtual inline bool IsUnique() { return false; }

  virtual inline ComponentType GetType() const {
    return ComponentType::TRANSFORM;
  }

  template <DerivedFromComponent Type, typename... Args>
  static std::shared_ptr<Type> CreateComponent(Args... args);
};

template <DerivedFromComponent Type, typename... Args>
std::shared_ptr<Type> Component::CreateComponent(Args... args) {
  return std::make_shared<Type>(args...);
}
};  // namespace VoxelEngine
