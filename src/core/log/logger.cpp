#include "voxelengine/log/logger.hpp"
#include <iostream>
#include <string>
#include "voxelengine/time/time.hpp"
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

  std::cout << "[" << Time::timeSinceStartup << "]" << logSymbol << "["
            << context << "]: " << message << std::endl;
}

void Logger::Debug(const std::string &message) {
  Log(LogCategory::DEBUG, message, "Logger::Debug");
}

// TODO: add system to allow logging into files
