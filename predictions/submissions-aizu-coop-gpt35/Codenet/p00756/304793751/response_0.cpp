bool ok(int a, int bit) {
  int a_left = x[a] - r[a];
  int a_right = x[a] + r[a];
  int a_top = y[a] + r[a];
  int a_bottom = y[a] - r[a];

  for (int i = 0; i < a; i++) {
    if (((bit >> i) & 1) == 0)
      continue;

    int b_left = x[i] - r[i];
    int b_right = x[i] + r[i];
    int b_top = y[i] + r[i];
    int b_bottom = y[i] - r[i];

    if (a_right < b_left || a_left > b_right || a_bottom > b_top || a_top < b_bottom)
      continue;

    return false;
  }

  return true;
}