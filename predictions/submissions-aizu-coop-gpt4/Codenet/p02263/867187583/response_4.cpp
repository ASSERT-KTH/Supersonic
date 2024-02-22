#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

class Stack {
public:
  Stack(int n) : top_(0) {};
  inline bool isEmpty() { return top_ == 0; }
  inline bool isFull() { return top_ == 100; }
  void push(int x) {
    if (!isFull()) {
      s_[top_++] = x;
    }
  }
  int pop() {
    if (!isEmpty()) {
      return s_[--top_];
    }
    return -1;
  }

private:
  int s_[100];
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
      int num = 0;
      for (int i = 0; s[i] != '\0'; ++i) {
        num = num * 10 + (s[i] - '0');
      }
      stack.push(num);
      break;
    }
    }
  }
  printf("%d\n", stack.pop());
  return 0;
}