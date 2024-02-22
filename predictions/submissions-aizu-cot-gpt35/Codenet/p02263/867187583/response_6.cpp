#include <stdio.h>
#include <stdlib.h>
#include <array>

class Stack {
public:
  Stack(int n) : s_{}, top_(0){};
  bool isEmpty() { return top_ == 0; }
  bool isFull() { return top_ == s_.size(); }
  void push(int x) {
    if (isFull()) {
      return;
    }
    top_++;
    s_[top_] = x;
  }
  int pop() {
    if (isEmpty()) {
      return -1;
    }
    top_--;
    return s_[top_ + 1];
  }

private:
  std::array<int, 110> s_;
  size_t top_;
};

int main() {
  char s[10];
  Stack stack(110);
  while (scanf("%9s", s) != EOF) {
    switch (s[0]) {
      case '+': {
        int rhs = stack.pop();
        int lhs = stack.pop();
        stack.push(lhs + rhs);
        break;
      }
      case '-': {
        int rhs = stack.pop();
        int lhs = stack.pop();
        stack.push(lhs - rhs);
        break;
      }
      case '*': {
        int rhs = stack.pop();
        int lhs = stack.pop();
        stack.push(lhs * rhs);
        break;
      }
      default: {
        stack.push(atoi(s));
        break;
      }
    }
  }
  printf("%d\n", stack.pop());
  return 0;
}