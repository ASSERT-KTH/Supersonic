inline bool cmp(const Data &a, const Data &b) {
  return a.size < b.size || (a.size == b.size && a.value < b.value);
}