#include <cstdio>
#include <cstdlib>
#include <stack>
#include <cstring>
using namespace std;
int main() {
  char s[1000];
  stack<int> stack;
  while (fgets(s, 1000, stdin) != NULL) {
    if (s[0] == '+') {
      int rhs = stack.top(); stack.pop();
      int lhs = stack.top(); stack.pop();
      int t = lhs + rhs;
      stack.push(t);
    } else if (s[0] == '-') {
      int rhs = stack.top(); stack.pop();
      int lhs = stack.top(); stack.pop();
      int t = lhs - rhs;
      stack.push(t);
    } else if (s[0] == '*') {
      int rhs = stack.top(); stack.pop();
      int lhs = stack.top(); stack.pop();
      int t = lhs * rhs;
      stack.push(t);
    } else {
      stack.push(atoi(s));
    }
  }
  printf("%d\n", stack.top()); stack.pop();
  return 0;
}