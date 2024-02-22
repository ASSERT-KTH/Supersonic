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
    if (!isFull()) {
      s_[++top_] = x;
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
  char s[10];
  Stack stack(110);
  while (scanf("%s", s) != EOF) {
    int val = stack.pop();
    if (s[0] == '+') {
      int t = val + stack.pop();
      stack.push(t);
    } else if (s[0] == '-') {
      int t = val - stack.pop();
      stack.push(t);
    } else if (s[0] == '*') {
      int t = val * stack.pop();
      stack.push(t);
    } else {
      stack.push(atoi(s));
    }
  }
  printf("%d\n", stack.pop());
  return 0;
}