#pragma once

#include "OperationToken.hpp"

class MultiplyToken : public OperationToken {
 public:
  std::string GetName() const override;
  double Apply(const std::vector<double> &args) const override;
  unsigned int GetArity() const override;
  virtual ~MultiplyToken();
};
