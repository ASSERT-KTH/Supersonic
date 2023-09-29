#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

class Stack {
public:
  Stack(int n) : s_(n), top_(0){}
  void push(int x) {
    if (top_ < s_.size()) {
      s_[top_++] = x;
    }
  }
  int pop() {
    return top_ > 0 ? s_[--top_] : -1;
  }

private:
  std::vector<int> s_;
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