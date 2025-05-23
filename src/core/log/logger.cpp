#include "voxelengine/log/logger.hpp"
#include <iostream>
using namespace VoxelEngine;
void Logger::Log(LogCategory logCategory, const std::string &message,
                 const std::string &context) {
  // TODO: Add timestamp
  std::cout << "[" << context << "]: " << message << std::endl;
}
