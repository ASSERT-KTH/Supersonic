struct UnionFind {
  int* data;
  UnionFind(int sz) : data(new int[sz]) {
    for (int i = 0; i < sz; i++) {
      data[i] = -1;
    }
  }
  bool unite(int x, int y) {
    x = find(x), y = find(y);
    if (x == y)
      return (false);
    if (data[x] > data[y])
      swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return (true);
  }
  int find(int k) {
    if (data[k] < 0)
      return (k);
    return (data[k] = find(data[k]));
  }
  int size(int k) { return (-data[find(k)]); }
};