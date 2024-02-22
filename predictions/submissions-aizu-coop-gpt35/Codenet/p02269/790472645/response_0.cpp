ull dic_op(char str[], int len) {
  static const int values[256] = {0}; // Initialize all elements to 0
  values['A'] = 1;
  values['C'] = 2;
  values['G'] = 3;
  values['T'] = 4;
  ull g = 0;
  for (int j = 0; j < len; j++) {
    g += values[str[j]];
    if (j < len - 1)
      g *= 5;
  }
  return g;
}