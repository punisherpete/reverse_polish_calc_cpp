#pragma once

#include "AbstractToken.hpp"

class OperandToken : public AbstractToken {
  const double value_;

 public:
  explicit OperandToken(double value) : value_(value) {}
  void Act(std::stack<double> &s) const override;
  virtual ~OperandToken();
};
