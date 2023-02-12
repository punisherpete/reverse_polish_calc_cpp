#include "OperandToken.hpp"

#include <iostream>

void OperandToken::Act(std::stack<double> &s) const {
  s.push(value_);
}
OperandToken::~OperandToken() {
}
