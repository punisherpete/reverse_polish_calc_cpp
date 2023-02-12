#include "DivisionOperation.hpp"

#include <iostream>

std::string DivisionToken::GetName() const {
  return "/";
}
double DivisionToken::Apply(const std::vector<double> &args) const {
  // TODO: check zero-div. Exception?
  return args[1] / args[0];
}
unsigned int DivisionToken::GetArity() const {
  return 2;
}
DivisionToken::~DivisionToken() { }
