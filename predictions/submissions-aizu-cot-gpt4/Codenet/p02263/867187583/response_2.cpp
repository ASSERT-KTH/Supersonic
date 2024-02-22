#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
using namespace std;
class Stack {
public:
  Stack(int n) : s_(n), top_(0){
      s_.reserve(n);
  };
  void push(int x) {
    s_[++top_] = x;
  }
  int pop() {
    return s_[top_--];
  }

private:
  vector<int> s_;
  size_t top_;
};
int main() {
  char s[1000];
  Stack stack(110);
  while (scanf("%s", s) != EOF) {
    switch(s[0]) {
      case '+':
        stack.push(stack.pop() + stack.pop());
        break;
      case '-':
        {int rhs = stack.pop();
        stack.push(stack.pop() - rhs);}
        break;
      case '*':
        stack.push(stack.pop() * stack.pop());
        break;
      default:
        stack.push(atoi(s));
    }
  }
  printf("%d\n", stack.pop());
  return 0;
}