#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Stack {
public:
  Stack(int n) : s_(n), top_(0){};
  bool isEmpty() { return top_ == 0; }
  bool isFull() { return top_ == s_.size(); }
  void push(int x) {
    if (isFull()) {
      return;
    }
    s_[top_] = x;
    top_++;
  }
  int pop() {
    if (isEmpty()) {
      return -1;
    }
    top_--;
    return s_[top_];
  }

private:
  vector<int> s_;
  size_t top_;
};

int main() {
  string s;
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
      stack.push(stoi(s));
    }
  }
  cout << stack.pop() << "\n";
  return 0;
}