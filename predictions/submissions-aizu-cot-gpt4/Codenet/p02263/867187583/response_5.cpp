#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>

using namespace std;

class Stack {
public:
  Stack(int n) : top_(0) {
    s_.reserve(n);
  }

  bool isEmpty() {
    return top_ == 0;
  }

  bool isFull() {
    return top_ == s_.size();
  }

  void push(int x) {
    if (!isFull()) {
      s_[top_++] = x;
    }
  }

  int pop() {
    return isEmpty() ? -1 : s_[--top_];
  }

private:
  vector<int> s_;
  size_t top_;
};

int main() {
  char s[1000];
  Stack stack(110);
  while (scanf("%s", s) != EOF) {
    int rhs, lhs, t;
    switch(s[0]) {
      case '+':
        rhs = stack.pop();
        lhs = stack.pop();
        t = lhs + rhs;
        stack.push(t);
        break;
      case '-':
        rhs = stack.pop();
        lhs = stack.pop();
        t = lhs - rhs;
        stack.push(t);
        break;
      case '*':
        rhs = stack.pop();
        lhs = stack.pop();
        t = lhs * rhs;
        stack.push(t);
        break;
      default:
        stack.push(atoi(s));
        break;
    }
  }
  printf("%d\n", stack.pop());
  return 0;
}