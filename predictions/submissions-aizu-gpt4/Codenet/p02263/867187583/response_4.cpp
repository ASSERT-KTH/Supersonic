#include <stdio.h>
#include <stdlib.h>
#include <stack>
using namespace std;

int main() {
  char s[1000];
  stack<int> stack;
  while (scanf("%s", s) != EOF) {
    if (s[0] == '+') {
      int rhs = stack.top(); stack.pop();
      int lhs = stack.top(); stack.pop();
      stack.push(lhs + rhs);
    } else if (s[0] == '-') {
      int rhs = stack.top(); stack.pop();
      int lhs = stack.top(); stack.pop();
      stack.push(lhs - rhs);
    } else if (s[0] == '*') {
      int rhs = stack.top(); stack.pop();
      int lhs = stack.top(); stack.pop();
      stack.push(lhs * rhs);
    } else {
      stack.push(atoi(s));
    }
  }
  printf("%d\n", stack.top()); stack.pop();
  return 0;
}