#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Stack {
public:
  Stack(int n) : top_(0) { s_.reserve(n); };
  void push(int x) {
    if (isFull()) {
      return;
    }
    s_[top_] = x;
    top_++;
  }
  int pop() {
    if (isEmpty()) {
      throw out_of_range("Stack Underflow");
    }
    top_--;
    return s_[top_];
  }

private:
  vector<int> s_;
  size_t top_;
  bool isEmpty() { return top_ == 0; }
  bool isFull() { return top_ == s_.capacity(); }
};

int main() {
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
  cout << stack.pop() << endl;
  return 0;
}