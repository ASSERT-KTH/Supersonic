#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class Stack {
public:
  Stack(int n) : s_(new int[n]), top_(s_){};
  ~Stack() {
    delete[] s_;
  }
  bool isEmpty() { return top_ == s_; }
  void push(int x) {
    *(++top_) = x;
  }
  int pop() {
    return *(top_--);
  }

private:
  int* s_;
  int* top_;
};

int main() {
  char s[1000];
  Stack stack(110);
  fgets(s, sizeof(s), stdin);
  char* p = s;
  while (*p != '\0' && *p != '\n') {
    if (*p >= '0' && *p <= '9') {
      int num = 0;
      while (*p >= '0' && *p <= '9') {
        num = num * 10 + (*p - '0');
        p++;
      }
      stack.push(num);
    } else if (*p == '+') {
      int rhs = stack.pop();
      int lhs = stack.pop();
      int t = lhs + rhs;
      stack.push(t);
      p++;
    } else if (*p == '-') {
      int rhs = stack.pop();
      int lhs = stack.pop();
      int t = lhs - rhs;
      stack.push(t);
      p++;
    } else if (*p == '*') {
      int rhs = stack.pop();
      int lhs = stack.pop();
      int t = lhs * rhs;
      stack.push(t);
      p++;
    } else if (*p == ' ' || *p == '\t') {
      p++;
    } else {
      printf("Invalid input\n");
      return 1;
    }
  }
  printf("%d\n", stack.pop());
  return 0;
}