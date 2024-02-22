#include <iostream>
#include <vector>
using namespace std;

const int STACK_SIZE = 110;

class Stack {
public:
  Stack() : s_(STACK_SIZE), top_(0) {}
  bool isEmpty() { return top_ == 0; }
  void push(int x) {
    top_++;
    s_.emplace_back(x);
  }
  int pop() {
    top_--;
    return s_[top_];
  }

private:
  vector<int> s_;
  size_t top_;
};

int main() {
  char s[1000];
  Stack stack;
  while (cin >> s) {
    if (s[0] == '+') {
      stack.push(stack.pop() + stack.pop());
    } else if (s[0] == '-') {
      int rhs = stack.pop();
      int lhs = stack.pop();
      stack.push(lhs - rhs);
    } else if (s[0] == '*') {
      stack.push(stack.pop() * stack.pop());
    } else {
      stack.push(atoi(s));
    }
  }
  cout << stack.pop() << endl;
  return 0;
}