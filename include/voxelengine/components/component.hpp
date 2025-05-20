#pragma once
#include <memory>
namespace VoxelEngine {
class Object;

#define MAKE_UNIQUE_COMPONENT()             \
 public:                                    \
  virtual inline bool isUnique() override { \
    return true;                            \
  }  // namespace VoxelEngine

class Component {
  friend class Object;

 public:
  uint64_t id = 0;

 protected:
  Object* owner;

 public:
  inline Object* getOwner() const { return owner; }

  virtual inline bool isUnique() { return false; }

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
