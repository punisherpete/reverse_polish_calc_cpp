#include "AdditionOperation.hpp"


std::string AdditionToken::GetName() const {
  return "+";
}
double AdditionToken::Apply(const std::vector<double> &args) const {
  return args.at(0) + args.at(1);
}
unsigned int AdditionToken::GetArity() const {
  return 2;
}
AdditionToken::~AdditionToken() = default;
