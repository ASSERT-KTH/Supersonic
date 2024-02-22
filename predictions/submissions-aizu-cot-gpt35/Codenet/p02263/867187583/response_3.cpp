#include <stdio.h>
#include <stdlib.h>

class Stack {
public:
  Stack(int n) : s_(n), top_(0) {}
  bool isEmpty() { return top_ == 0; }
  void push(int x) {
    top_++;
    s_[top_] = x;
  }
  int pop() {
    top_--;
    return s_[top_ + 1];
  }

private:
  int* s_;
  size_t top_;
};

int main() {
  char s[1000];
  Stack stack(110);
  while (scanf("%s", &s[0]) != EOF) {
    switch (s[0]) {
      case '+': {
        int rhs = stack.pop();
        int lhs = stack.pop();
        int t = lhs + rhs;
        stack.push(t);
        break;
      }
      case '-': {
        int rhs = stack.pop();
        int lhs = stack.pop();
        int t = lhs - rhs;
        stack.push(t);
        break;
      }
      case '*': {
        int rhs = stack.pop();
        int lhs = stack.pop();
        int t = lhs * rhs;
        stack.push(t);
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