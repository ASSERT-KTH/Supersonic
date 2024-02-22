#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Stack {
public:
  Stack(int n) : s_(n) {}
  bool isEmpty() { return s_.empty(); }
  void push(int x) { s_.push_back(x); }
  int pop() {
    if (isEmpty()) {
      return -1;
    }
    int val = s_.back();
    s_.pop_back();
    return val;
  }

private:
  vector<int> s_;
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
        stack.push(t);
        break;
      case '-':
        rhs = stack.pop();
        lhs = stack.pop();
        t = lhs - rhs;
        stack.push(t);
        break;
      case '*':
        rhs = stack.pop();
        lhs = stack.pop();
        t = lhs * rhs;
        stack.push(t);
        break;
      default:
        stack.push(stoi(s));
        break;
    }
  }
  cout << stack.pop() << endl;
  return 0;
}