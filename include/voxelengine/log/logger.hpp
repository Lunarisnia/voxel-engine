#pragma once
#include <ctime>
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
                  const std::string &context);
  static void Debug(const std::string &message);

 private:
};
}  // namespace VoxelEngine
