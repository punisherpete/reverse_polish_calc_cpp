#pragma once

#include "AbstractToken.hpp"
#include "OperationToken.hpp"

class OperatorToken : public AbstractToken {
  OperationToken* operation_;

 public:
  explicit OperatorToken(OperationToken* operation);
  void Act(std::stack<double>& s) const override;
  virtual ~OperatorToken();
};
