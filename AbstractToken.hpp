#pragma once

#include <stack>

class AbstractToken {
 public:
  virtual void Act(std::stack<double>& s) const = 0;
  virtual ~AbstractToken() = default;
};
