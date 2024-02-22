#include <stdlib.h>
#include <string.h>

class Stack {
public:
  Stack(int n) : top_(0){};
  void push(int x) {
    top_++;
    s_[top_] = x;
  }
  int pop() {
    top_--;
    return s_[top_ + 1];
  }

private:
  int s_[110];
  size_t top_;
};

int main() {
  char s[1000];
  Stack stack(110);
  while (fgets(s, sizeof(s), stdin) != NULL) {
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
  int result = stack.pop();
  sprintf(s, "%d\n", result);
  fputs(s, stdout);
  return 0;
}