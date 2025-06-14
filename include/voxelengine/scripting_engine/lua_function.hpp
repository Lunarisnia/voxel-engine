#pragma once
#include <string>
namespace VoxelEngine {
class LuaFunction {
 private:
  std::string functionName;
  int nargs = 0;
  int nresults = 0;

 public:
  LuaFunction *AddParamString(const std::string &value);
  LuaFunction *AddParamBoolean(bool value);

  LuaFunction *AddParamNumber(int value);
  LuaFunction *AddParamNumber(float value);
  LuaFunction *AddParamNumber(double value);
  void Execute();

 public:
  LuaFunction(const std::string &name);
  LuaFunction(const std::string &name, const std::string &tableName);
};
};  // namespace VoxelEngine
