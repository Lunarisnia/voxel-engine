#include "voxelengine/log/logger.hpp"
#include <iostream>
#include <string>
using namespace VoxelEngine;
void Logger::Log(LogCategory logCategory, const std::string &message,
                 const std::string &context) {
  std::string logSymbol;
  if (logCategory == LogCategory::INFO) {
    logSymbol = "[INFO]";
  } else if (logCategory == LogCategory::ERROR) {
    logSymbol = "[ERROR]";
  } else if (logCategory == LogCategory::DEBUG) {
    logSymbol = "[DEBUG]";
  } else {
    logSymbol = "[UNKNOWN]";
  }

  // TODO: Add timestamp
  std::cout << logSymbol << "[" << context << "]: " << message << std::endl;
}

// TODO: add system to allow logging into files
