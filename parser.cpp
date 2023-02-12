#include "parser.hpp"

#include <memory>

#include "OperandToken.hpp"
#include "OperatorToken.hpp"
#include "iostream"
#include "utils.hpp"

using namespace std;

vector<unique_ptr<AbstractToken>> Parser::parse(const vector<string> &tokens) const {
  vector<unique_ptr<AbstractToken>> nodes{};

  for (const auto &token : tokens) {
    if (IsNumber(token)) {
      auto value = ParseDouble(token);
      nodes.push_back(make_unique<OperandToken>(value));
      continue;
    }
    if (IsOperator(token)) {
      auto op = operations_.at(token).get();
      nodes.push_back(make_unique<OperatorToken>(op));
      continue;
    }

    std::cerr << "[ERROR] unexpected token " << token << std::endl;
    exit(-1);
  }

  return nodes;
}
bool Parser::IsOperator(const std::string &token) const {
  return operations_.count(token) == 1;
}
