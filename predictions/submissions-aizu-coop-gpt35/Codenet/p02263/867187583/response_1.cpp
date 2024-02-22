#include <stdio.h>
#include <stdlib.h>

class Stack {
public:
  Stack(int n) : size_(n), top_(-1) {
    s_ = new long long[size_];
  };

  ~Stack() {
    delete[] s_;
  }

  bool isEmpty() { return top_ == -1; }
  bool isFull() { return top_ == size_ - 1; }
  void push(long long x) {
    if (isFull()) {
      return;
    }
    top_++;
    s_[top_] = x;
  }
  long long pop() {
    if (isEmpty()) {
      return -1;
    }
    top_--;
    return s_[top_ + 1];
  }

private:
  long long* s_;
  int size_;
  int top_;
};

int main() {
  char s[1000];
  Stack stack(110);
  while (scanf("%s", s) != EOF) {
    switch (s[0]) {
      case '+': {
        long long rhs = stack.pop();
        long long lhs = stack.pop();
        long long t = lhs + rhs;
        stack.push(t);
        break;
      }
      case '-': {
        long long rhs = stack.pop();
        long long lhs = stack.pop();
        long long t = lhs - rhs;
        stack.push(t);
        break;
      }
      case '*': {
        long long rhs = stack.pop();
        long long lhs = stack.pop();
        long long t = lhs * rhs;
        stack.push(t);
        break;
      }
      default: {
        stack.push(atoll(s));
      }
    }
  }
  printf("%lld\n", stack.pop());
  return 0;
}