#include <iostream>
#include <vector>

class Stack {
public:
  Stack() : s_(), top_(0) {};
  void push(int x) {
    top_++;
    s_.push_back(x);
  }
  int pop() {
    top_--;
    return s_[top_];
  }

private:
  std::vector<int> s_;
  size_t top_;
};

int main() {
  char s[1000];
  Stack stack;
  while (std::cin >> s) {
    if (s[0] == '+') {
      int rhs = stack.pop();
      int lhs = stack.pop();
      int t = lhs + rhs;
      stack.push(t);
    } else if (s[0] == '-') {
      int rhs = stack.pop();
      int lhs = stack.pop();
      int t = lhs - rhs;
      stack.push(t);
    } else if (s[0] == '*') {
      int rhs = stack.pop();
      int lhs = stack.pop();
      int t = lhs * rhs;
      stack.push(t);
    } else {
      stack.push(std::atoi(s));
    }
  }
  std::cout << stack.pop() << std::endl;
  return 0;
}