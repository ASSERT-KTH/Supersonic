#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
using namespace std;

class Stack {
public:
  Stack(int n) : s_(n), top_(0){};
  bool isEmpty() { return top_ == 0; }
  bool isFull() { return top_ == s_.size(); }
  void push(int x) {
    if (!isFull()) {
      s_[top_++] = x;
    }
  }
  int pop() {
    if (!isEmpty()) {
      return s_[--top_];
    }
    return -1;
  }

private:
  vector<int> s_;
  size_t top_;
};

int main() {
  std::ios_base::sync_with_stdio(false);
  string s;
  Stack stack(110);
  while (cin >> s) {
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
      stack.push(stoi(s));
    }
  }
  cout << stack.pop() << "\n";
  return 0;
}