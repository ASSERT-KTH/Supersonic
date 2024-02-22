#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

class Stack {
public:
  Stack(int n) : size_(n), top_(0) {
    s_ = new int[size_];
  }

  ~Stack() {
    delete[] s_;
  }

  bool isEmpty() {
    return top_ == 0;
  }

  bool isFull() {
    return top_ == size_;
  }

  void push(int x) {
    if (isFull()) {
      return;
    }
    s_[top_++] = x;
  }

  int pop() {
    if (isEmpty()) {
      return -1;
    }
    return s_[--top_];
  }

private:
  int* s_;
  int size_;
  int top_;
};

int main() {
  char s[1000];
  Stack stack(110);
  while (cin >> s) {
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

  cout << stack.pop() << endl;
  return 0;
}