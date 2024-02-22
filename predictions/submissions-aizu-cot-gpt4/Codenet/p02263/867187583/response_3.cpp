#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

class Stack {
public:
  Stack(int n) : s_(n), top_(0) { s_.reserve(n); };

  bool isEmpty() { return top_ == 0; }

  void push(int x) {
    if (top_ == s_.size()) {
      throw overflow_error("Stack is full");
    }
    s_[top_++] = x;
  }

  int pop() {
    if (isEmpty()) {
      throw underflow_error("Stack is empty");
    }
    return s_[--top_];
  }

private:
  vector<int> s_;
  size_t top_;
};

int main() {
  string s;
  Stack stack(110);
  while (cin >> s) {
    int rhs, lhs, t;
    switch (s[0]) {
    case '+':
      rhs = stack.pop();
      lhs = stack.pop();
      t = lhs + rhs;
      break;
    case '-':
      rhs = stack.pop();
      lhs = stack.pop();
      t = lhs - rhs;
      break;
    case '*':
      rhs = stack.pop();
      lhs = stack.pop();
      t = lhs * rhs;
      break;
    default:
      t = stoi(s);
      break;
    }
    stack.push(t);
  }
  try {
    cout << stack.pop() << endl;
  } catch (const underflow_error& e) {
    cerr << "Error: " << e.what() << endl;
    return 1;
  }
  return 0;
}