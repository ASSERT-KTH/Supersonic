#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 110

class Stack {
public:
  Stack() : top_(0){};
  bool isEmpty() { return top_ == 0; }
  bool isFull() { return top_ == MAX_SIZE; }
  void push(int x) {
    if (isFull()) {
      return;
    }
    s_[top_++] = x;
  }
  int pop() {
    if (isEmpty()) {
      return -1;
    }
    return s_[--top_];
  }

private:
  int s_[MAX_SIZE];
  size_t top_;
};
int main() {
  char s[1000];
  Stack stack;
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