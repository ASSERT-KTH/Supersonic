#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class Stack {
public:
  Stack(int n) : s_(n), top_(0){};
  bool isEmpty() { return top_ == 0; }
  bool isFull() { return top_ == size_; } // Change isFull() implementation
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
  static const int size_ = 110; // Change to a fixed-size array
  int s_[size_]; // Change to a fixed-size array
  size_t top_;
};

int main() {
  char s[1000];
  Stack stack(Stack::size_); // Use the fixed-size array size
  while (scanf("%s", s) != EOF) {
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
      stack.push(atoi(s));
    }
  }
  printf("%d\n", stack.pop());
  return 0;
}