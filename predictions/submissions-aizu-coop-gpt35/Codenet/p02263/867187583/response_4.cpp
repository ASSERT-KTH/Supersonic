class Stack {
public:
  Stack(int n) : s_(new int[n]), capacity_(n), top_(0) {}
  ~Stack() { delete[] s_; }
  bool isEmpty() { return top_ == 0; }
  bool isFull() { return top_ == capacity_; }
  void push(int x) {
    if (isFull()) {
      resize();
    }
    s_[top_++] = x;
  }
  int pop() {
    if (isEmpty()) {
      return -1;
    }
    return s_[--top_];
  }
  int top() {
    if (isEmpty()) {
      return -1;
    }
    return s_[top_ - 1];
  }

private:
  int* s_;
  size_t capacity_;
  size_t top_;

  void resize() {
    size_t newCapacity = capacity_ * 2;
    int* newStack = new int[newCapacity];
    memcpy(newStack, s_, top_ * sizeof(int));
    delete[] s_;
    s_ = newStack;
    capacity_ = newCapacity;
  }
};