#pragma once
#include <string>
namespace VoxelEngine {
enum LogCategory {
  ERROR,
  DEBUG,
  INFO,
};

class Logger {
 public:
  static void Log(LogCategory logCategory, const std::string &message,
                  std::string &context);

 private:
  static void getTimestamp();
};
}  // namespace VoxelEngine
