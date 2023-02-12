#pragma once

#include <string>
#include <vector>
#include "sstream"

class Tokenizer {
  const char delimiter_;

  int prec(char c) const {
    if (c == '^')
      return 3;
    else if (c == '/' || c == '*')
      return 2;
    else if (c == '+' || c == '-')
      return 1;
    else
      return -1;
  }

  std::vector<std::string> GetAllNumbers(std::string& string) const {
    std::vector<std::string> result;
    std::vector<char> delimiters;

    for (char element : string) {
      if (element >= '0' and element <= '9' || element == '.') {
        continue;
      }

      delimiters.emplace_back(element);
    }

    sort(delimiters.begin(), delimiters.end());
    delimiters.erase(unique(delimiters.begin(), delimiters.end()),
                     delimiters.end());

    size_t pos = 0;
    std::string token;

    for(char character: delimiters) {
      std::replace( string.begin(), string.end(), character, ' ');
    }

    while ((pos = string.find(" ")) != std::string::npos) {
      token = string.substr(0, pos);
      result.push_back(token);
      string.erase(0, pos + 1);
    }

    result.push_back(string);

    return result;
  }

 public:
  explicit Tokenizer(char delimiter = ' ') : delimiter_(delimiter) {}

  std::vector<std::string> tokenize(const std::string& text) const {
    std::string copy = text;
    copy.erase(remove(copy.begin(), copy.end(), ' '), copy.end());
    std::vector<std::string> expectedNumbers = GetAllNumbers(copy);
    std::stack<char> st;
    std::stack<AbstractToken*> tokens;
    std::vector<std::string> result;

    for (int i = 0; i < text.length(); i++) {
      char c = text[i];

      if ((c >= '0' && c <= '9') || c == '.') {
        for (std::string expected_number : expectedNumbers) {
          if (c == expected_number[0]) {
            for (int j = 0; j < expected_number.length(); j++) {
              if (text[i + j] == expected_number[j]) {
                if (j == expected_number.length() - 1) {
                  result.push_back(expected_number);
                  i += j;
                  expectedNumbers.erase(std::remove(expectedNumbers.begin(), expectedNumbers.end(), expected_number),
                                        expectedNumbers.end());
                  break;
                }
                continue;
              }
              break;
            }
          }
        }
      }
      else if (c == '(')
        st.push('(');
      else if (c == ')') {
        while (st.top() != '(') {
          result.emplace_back(1, st.top());
          st.pop();
        }
        st.pop();
      }
      else {
        while (!st.empty() && prec(text[i]) <= prec(st.top())) {
          result.emplace_back(1, st.top());
          st.pop();
        }
        st.push(c);
      }
    }
    while (!st.empty()) {
      result.emplace_back(1, st.top());
      st.pop();
    }

    return result;
  };
};