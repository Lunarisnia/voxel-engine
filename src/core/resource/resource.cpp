#include "voxelengine/resource/resource.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
using namespace VoxelEngine;

std::string Resource::loadCodeFromPath(std::string path) {
  std::ifstream file(path);
  std::string code;
  try {
    file.exceptions(std::ifstream::failbit | std::ifstream::badbit);

    std::stringstream codeStream;
    codeStream << file.rdbuf();

    code = codeStream.str();

    file.close();
  } catch (const std::ifstream::failure &error) {
    std::cout << "READ::ERROR: " << error.what() << std::endl;
  }
  return code;
}
