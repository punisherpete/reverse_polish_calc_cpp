#pragma once

#include <memory>
#include <stack>
#include <string>

#include "AdditionOperation.hpp"
#include "SubtractionOperation.hpp"
#include "DivisionOperation.hpp"
#include "MulptiplyOperation.hpp"
#include "parser.hpp"
#include "tokenizer.hpp"

class Calculator {
 public:
  explicit Calculator() = default;

  static double CalculateExpression(const std::string& text) {
    Tokenizer tokenizer;
    Parser parser;

    parser.Register<AdditionToken>();
    parser.Register<SubtractionToken>();
    parser.Register<MultiplyToken>();
    parser.Register<DivisionToken>();

    auto tokens = tokenizer.tokenize(text);

    auto nodes = parser.parse(tokens);
    std::stack<double> s;
    for (auto& node : nodes) {
      node->Act(s);
    }
    auto result = s.top();

    return result;
  }
};
