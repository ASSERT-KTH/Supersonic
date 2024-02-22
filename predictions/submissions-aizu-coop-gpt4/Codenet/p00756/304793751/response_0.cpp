int dfs(int bit) {
  memo[bit] = true;
  int ret = n;
  for (int i = 0; i < n; i++) {
    if ((bit >> i) & 1) ret--;
  }
  for (int i = 0; i < n; i++) {
    int bitShiftI = (bit >> i) & 1;
    if (bitShiftI == 0) continue;
    bool okI = ok(i, bit);
    if (!okI) continue;
    for (int j = i + 1; j < n; j++) {
      int bitShiftJ = (bit >> j) & 1;
      if (bitShiftJ == 0 || c[i] != c[j]) continue;
      int to_bit = bit ^ (1 << i) ^ (1 << j);
      bool okJ = ok(j, bit);
      if (okJ && !memo[to_bit]) {
        ret = max(ret, dfs(to_bit));
      }
    }
  }
  return ret;
}