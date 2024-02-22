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
      s_.resize(s_.size() * 2); // resizing when stack is full
    }
    s_[top_++] = x;  // first insert the element, then increment top_
  }
  
  int pop() {
    if (isEmpty()) {
      throw out_of_range("Stack Underflow"); // throw exception if stack is empty
    }
    return s_[--top_];
  }

private:
  vector<int> s_;
  size_t top_;
};

int main() {
  char s[10];  // reduced buffer size
  Stack stack(100);
  while (fgets(s, sizeof(s), stdin) != NULL) {
    int num = atoi(s);  // store atoi result in a variable
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
      stack.push(num);  // use stored atoi result
    }
  }
  printf("%d\n", stack.pop());
  return 0;
}