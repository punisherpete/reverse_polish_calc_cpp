#include "MulptiplyOperation.hpp"

#include <iostream>
std::string MultiplyToken::GetName() const {
  return "*";
}
double MultiplyToken::Apply(const std::vector<double> &args) const {
  return args[0] * args[1];
}
unsigned int MultiplyToken::GetArity() const {
  return 2;
}
MultiplyToken::~MultiplyToken() { }
