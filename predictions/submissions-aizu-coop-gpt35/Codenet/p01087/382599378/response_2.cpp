#include <iostream>
#include <vector>
#include <stack>
#include <sstream>
#include <numeric>

int solve(const std::vector<std::string>& s, int n) {
  std::stack<std::string> expressions;
  int y = 0, x = 0;
  while (y < n && (int)s[y].size() > x) {
    if (isdigit(s[y][x])) {
      expressions.push(std::string(1, s[y][x]));
      x++;
    } else {
      char op = s[y][x];
      x++;
      int term = 0;
      while (!expressions.empty() && expressions.top() != "(") {
        term += std::stoi(expressions.top());
        expressions.pop();
      }
      if (op == '+') {
        expressions.push(std::to_string(term));
      } else {
        if (term == 0) {
          expressions.push("0");
        } else {
          expressions.push(std::to_string(term));
        }
      }
      if (op == '(') {
        x--;
        y++;
        expressions.push("(");
      } else if (op == ')') {
        x--;
        y++;
        int term = 0;
        while (!expressions.empty() && expressions.top() != "(") {
          term += std::stoi(expressions.top());
          expressions.pop();
        }
        expressions.pop(); // Remove "("
        expressions.push(std::to_string(term));
      }
    }
  }
  int result = 0;
  while (!expressions.empty()) {
    result += std::stoi(expressions.top());
    expressions.pop();
  }
  return result;
}

int main() {
  int n;
  while (std::cin >> n, n) {
    std::vector<std::string> s(n);
    for (int i = 0; i < n; i++) {
      std::cin >> s[i];
    }
    int result = solve(s, n);
    std::cout << result << std::endl;
  }
  return 0;
}