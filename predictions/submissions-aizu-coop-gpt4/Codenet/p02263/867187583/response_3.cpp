#include <iostream>
#include <stack>
#include <string>

int main() {
  std::stack<int> stack;
  std::string s;
  auto calculate = [&](char op) {
    int rhs = stack.top(); 
    stack.pop();
    int lhs = stack.top(); 
    stack.pop();
    switch (op) {
      case '+': stack.push(lhs + rhs); break;
      case '-': stack.push(lhs - rhs); break;
      case '*': stack.push(lhs * rhs); break;
    }
  };
  while (std::cin >> s) {
    if (s[0] == '+') {
      calculate('+');
    } else if (s[0] == '-') {
      calculate('-');
    } else if (s[0] == '*') {
      calculate('*');
    } else {
      stack.push(std::stoi(s));
    }
  }
  std::cout << stack.top() << std::endl;
  return 0;
}