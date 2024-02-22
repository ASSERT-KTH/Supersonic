inline bool check(int u, int v) {
  for (int i = 0; i < 3; ++i) {
    int p1 = (v >> (i * 8)) & 255;
    if (wall[p1]) {
      return false;
    }
  }
  return true;
}