#include <stdio.h>
#include <stdlib.h>

class Stack {
public:
  Stack(int n) : size_(n), top_(0){}
  bool isEmpty() { return top_ == 0; }
  bool isFull() { return top_ == size_; }
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
  int s_[110];
  int size_;
};

int main() {
  char s[1000];
  Stack stack(110);
  int rhs, lhs, t;
  while (scanf("%s", s) != EOF) {
    switch (s[0]) {
    case '+':
      rhs = stack.pop();
      lhs = stack.pop();
      stack.push(lhs + rhs);
      break;
    case '-':
      rhs = stack.pop();
      lhs = stack.pop();
      stack.push(lhs - rhs);
      break;
    case '*':
      rhs = stack.pop();
      lhs = stack.pop();
      stack.push(lhs * rhs);
      break;
    default:
      stack.push(atoi(s));
      break;
    }
  }
  putchar(stack.pop());
  return 0;
}