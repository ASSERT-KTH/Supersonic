class Stack {
public:
  Stack(int n) : size_(n), top_(0) {
    s_ = new int[size_];
  }
  ~Stack() {
    delete[] s_;
  }
  bool isEmpty() { return top_ == 0; }
  void push(int x) {
    if (top_ < size_) {
      s_[top_++] = x;
    }
  }
  int pop() {
    if (top_ > 0) {
      return s_[--top_];
    }
    return -1;
  }

private:
  int* s_;
  int size_;
  int top_;
};