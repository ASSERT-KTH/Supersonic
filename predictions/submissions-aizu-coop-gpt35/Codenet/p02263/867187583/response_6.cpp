#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class Stack {
public:
  Stack(int n) : size_(n), top_(-1) {
    s_ = new int[size_];
  };
  
  ~Stack() {
    delete[] s_;
  }
  
  bool isEmpty() { return top_ == -1; }
  
  bool isFull() { return top_ == size_ - 1; }
  
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
    int value = s_[top_];
    top_--;
    return value;
  }
  
  int top() {
    if (isEmpty()) {
      return -1;
    }
    return s_[top_];
  }

private:
  int* s_;
  int size_;
  int top_;
};

int main() {
  char s[1000];
  Stack stack(110);
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
  printf("%d\n", stack.pop());
  return 0;
}