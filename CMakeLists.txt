cmake_minimum_required(VERSION 3.15)
project(reverse_polish_calc)

set(CMAKE_CXX_STANDARD 17)

add_executable(reverse_polish_calc main.cpp Calculator.hpp tokenizer.hpp AbstractToken.hpp OperandToken.cpp OperandToken.hpp OperatorToken.cpp OperatorToken.hpp parser.cpp parser.hpp utils.hpp utils.hpp utils.cpp OperationToken.hpp AdditionOperation.cpp AdditionOperation.hpp MulptiplyOperation.cpp MulptiplyOperation.hpp DivisionOperation.cpp DivisionOperation.hpp SubtractionOperation.cpp SubtractionOperation.hpp)