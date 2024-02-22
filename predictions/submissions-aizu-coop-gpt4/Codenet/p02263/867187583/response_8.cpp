#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

class Stack {
public:
  Stack(int n) : size_(n), top_(0) { 
    s_ = new int[n]; 
  }
  ~Stack() { 
    delete[] s_; 
  }
  void push(int x) {
    if (top_ != size_) {
      s_[top_++] = x;
    }
  }
  int pop() {
    if (top_ != 0) {
      return s_[--top_];
    }
    return -1;
  }

private:
  int* s_;
  size_t size_;
  size_t top_;
};

int main() {
  char s[1000];
  Stack stack(110);
  while (cin >> s) {
    switch (s[0]) {
    case '+':
      stack.push(stack.pop() + stack.pop());
      break;
    case '-':
      {
        int rhs = stack.pop();
        stack.push(stack.pop() - rhs);
      }
      break;
    case '*':
      stack.push(stack.pop() * stack.pop());
      break;
    default:
      stack.push(stoi(s));
    }
  }
  cout << stack.pop() << endl;
  return 0;
}