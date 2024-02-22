#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
using namespace std;

class Stack {
public:
  Stack(int n) : capacity_(n), size_(0), s_(new int[n]){};
  ~Stack() {
    delete[] s_;
  }
  bool isEmpty() { return size_ == 0; }
  bool isFull() { return size_ == capacity_; }
  void push(int x) {
    if (isFull()) {
      resize();
    }
    s_[size_] = x;
    size_++;
  }
  int pop() {
    if (isEmpty()) {
      return -1;
    }
    size_--;
    return s_[size_];
  }

private:
  void resize() {
    int newCapacity = capacity_ * 2;
    int* newStack = new int[newCapacity];
    memcpy(newStack, s_, size_ * sizeof(int));
    delete[] s_;
    s_ = newStack;
    capacity_ = newCapacity;
  }

  int capacity_;
  int size_;
  int* s_;
};

int main() {
  char s[1000];
  Stack stack(110);
  while (fgets(s, sizeof(s), stdin) != NULL) {
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
  printf("%d\n", stack.pop());
  return 0;
}