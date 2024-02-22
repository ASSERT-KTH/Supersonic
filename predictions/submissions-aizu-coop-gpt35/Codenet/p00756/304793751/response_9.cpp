bool ok(int a, int bit) {
  for (int i = 0; i < a; i++) {
    if (((bit >> i) & 1) == 0)
      continue;
    int dist_squared = (x[i] - x[a]) * (x[i] - x[a]) + (y[i] - y[a]) * (y[i] - y[a]);
    int sum_squared = (r[i] + r[a]) * (r[i] + r[a]);
    if (dist_squared < sum_squared)
      return false;
  }
  return true;
}