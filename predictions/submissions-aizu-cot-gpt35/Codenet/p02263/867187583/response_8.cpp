#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;

class Stack {
public:
  Stack(int n) : s_(n), top_(0){};
  bool isEmpty() { return top_ == 0; }
  bool isFull() { return top_ == s_.size(); }
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
  vector<int> s_;
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