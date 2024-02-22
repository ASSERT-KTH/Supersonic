#include <stdio.h>
#include <stdlib.h>

class Stack {
public:
  Stack(int n) : top_(0) {}
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
  static const int MAX_SIZE = 110; // Fixed size for stack
  int s_[MAX_SIZE]; // Fixed-size array for stack
  size_t top_;
};

int main() {
  char s[1000];
  Stack stack(110);
  while (scanf("%s", s) != EOF) {
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