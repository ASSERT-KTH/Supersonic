#include <stdio.h>
#include <cstdlib>
#include <stack>
using namespace std;

int main() {
  char s[20];
  stack<int> stk;
  while (scanf("%s", s) != EOF) {
    switch(s[0]) {
      case '+':
        {
          int rhs = stk.top(); stk.pop();
          int lhs = stk.top(); stk.pop();
          stk.push(lhs + rhs);
        }
        break;
      case '-':
        {
          int rhs = stk.top(); stk.pop();
          int lhs = stk.top(); stk.pop();
          stk.push(lhs - rhs);
        }
        break;
      case '*':
        {
          int rhs = stk.top(); stk.pop();
          int lhs = stk.top(); stk.pop();
          stk.push(lhs * rhs);
        }
        break;
      default:
        stk.push(atoi(s));
    }
  }
  printf("%d\n", stk.top());
  return 0;
}