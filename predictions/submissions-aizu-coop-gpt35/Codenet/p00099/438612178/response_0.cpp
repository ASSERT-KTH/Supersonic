struct data {
  int num;
  int* score_ptr;
  data() {}
  data(int n, int* s) : num(n), score_ptr(s) {}
  bool operator<(const data& d) const {
    if (*score_ptr != *(d.score_ptr))
      return *score_ptr < *(d.score_ptr);
    return num > d.num;
  }
};