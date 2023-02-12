#include "SubtractionOperation.hpp"

std::string SubtractionToken::GetName() const {
  return "-";
}
double SubtractionToken::Apply(const std::vector<double> &args) const {
  return args[1] - args[0];
}
unsigned int SubtractionToken::GetArity() const {
  return 2;
}
