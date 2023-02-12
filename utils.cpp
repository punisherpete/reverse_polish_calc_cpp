#include "utils.hpp"

#include <stdexcept>

bool IsNumber(const std::string &str) {
  try {
    auto res = std::stod(str);
  } catch (const std::invalid_argument &ex) {
    return false;
  }

  return true;
}
double ParseDouble(const std::string &str) {
  return std::stod(str);
}
