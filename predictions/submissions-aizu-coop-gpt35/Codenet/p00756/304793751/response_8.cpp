bool ok(int a, int bit, int* r_squared, int* dist_squared) {
  for (int i = 0; i < a; i++) {
    if (((bit >> i) & 1) == 0)
      continue;
    if (dist_squared[i] < r_squared[i] + r_squared[a])
      return false;
  }
  return true;
}