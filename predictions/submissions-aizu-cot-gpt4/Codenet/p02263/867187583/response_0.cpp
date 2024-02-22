#include <iostream>
#include <vector>
#include <map>
#include <functional>
using namespace std;

class Stack {
public:
  Stack() : top_(0) {}
  void push(int x) {
    if (top_ == s_.size()) {
      s_.resize(s_.size() + 1);
    }
    s_[top_++] = x;
  }
  int pop() {
    if (top_ == 0) {
      throw out_of_range("Stack underflow");
    }
    return s_[--top_];
  }

private:
  vector<int> s_;
  size_t top_;
};

int main() {
  std::string s;
  Stack stack;
  map<char, function<int(int, int)>> ops {
      {'+', [](int a, int b) { return a + b; }},
      {'-', [](int a, int b) { return a - b; }},
      {'*', [](int a, int b) { return a * b; }}
  };
  
  while (cin >> s) {
    if (ops.count(s[0])) {
      int rhs = stack.pop();
      int lhs = stack.pop();
      stack.push(ops[s[0]](lhs, rhs));
    } else {
      stack.push(stoi(s));
    }
  }
  cout << stack.pop() << endl;
  return 0;
}