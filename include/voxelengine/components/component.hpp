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
 protected:
  std::shared_ptr<Object> owner;

 public:
  inline std::shared_ptr<Object> getOwner() const { return owner; }

  virtual inline bool isUnique() { return false; }
};
};  // namespace VoxelEngine
