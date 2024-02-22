int compress(int *x1, int *x2, int w) {
  set<int> xs;
  rep(i, n) {
    for (int d = -1; d <= 1; ++d) {
      int tx1 = x1[i] + d, tx2 = x2[i] + d;
      if (0 <= tx1 && tx1 <= w)
        xs.insert(tx1);
      if (0 <= tx2 && tx2 <= w)
        xs.insert(tx2);
    }
  }
  int idx = 0;
  map<int, int> compress_map;
  for (const auto& x : xs) {
    compress_map[x] = idx++;
  }
  rep(i, n) {
    x1[i] = compress_map[x1[i]];
    x2[i] = compress_map[x2[i]];
  }
  return xs.size();
}