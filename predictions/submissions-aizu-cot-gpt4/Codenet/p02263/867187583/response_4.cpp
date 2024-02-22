#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
using namespace std;
class Stack {
public:
  Stack(int n) : top_(0){};
  bool isEmpty() { return top_ == 0; }
  bool isFull() { return top_ == s_.size(); }
  void push(int x) {
    if (!isFull()) {
      s_.push_back(x);
      top_++;
    }
  }
  int pop() {
    if (!isEmpty()) {
      int val = s_[top_ - 1];
      top_--;
      s_.pop_back();
      return val;
    }
    return -1;
  }

private:
  vector<int> s_;
  size_t top_;
};
int main() {
  char s[1000];
  Stack stack(110);
  while (scanf("%999s", s) != EOF) {
    int rhs, lhs, t;
    if (s[0] == '+') {
      rhs = stack.pop();
      lhs = stack.pop();
      if (rhs != -1 && lhs != -1) {
        t = lhs + rhs;
        stack.push(t);
      }
    } else if (s[0] == '-') {
      rhs = stack.pop();
      lhs = stack.pop();
      if (rhs != -1 && lhs != -1) {
        t = lhs - rhs;
        stack.push(t);
      }
    } else if (s[0] == '*') {
      rhs = stack.pop();
      lhs = stack.pop();
      if (rhs != -1 && lhs != -1) {
        t = lhs * rhs;
        stack.push(t);
      }
    } else {
      stack.push(atoi(s));
    }
  }
  printf("%d\n", stack.pop());
  return 0;
}