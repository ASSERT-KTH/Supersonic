#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
using namespace std;
class Stack {
public:
  Stack(int n) : s_(n), top_(0){};
  bool isEmpty() const { return top_ == 0; }
  bool isFull() const { return top_ == s_.size(); }
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
  vector<int> s_;
  size_t top_;
};
int main() {
  char s[1000];
  Stack stack(110);
  while (scanf("%s", s) != EOF) {
    if (s[0] == '+') {
      int rhs = stack.pop();
      int lhs = stack.pop();
      stack.push(lhs + rhs);
    } else if (s[0] == '-') {
      int rhs = stack.pop();
      int lhs = stack.pop();
      stack.push(lhs - rhs);
    } else if (s[0] == '*') {
      int rhs = stack.pop();
      int lhs = stack.pop();
      stack.push(lhs * rhs);
    } else {
      stack.push(atoi(s));
    }
  }
  printf("%d\n", stack.pop());
  return 0;
}