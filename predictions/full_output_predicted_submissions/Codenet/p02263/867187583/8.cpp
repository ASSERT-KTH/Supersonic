#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
  vector<int> s_;
  size_t top_;
};
int main() {
  char s[1000];
  Stack stack[110];
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