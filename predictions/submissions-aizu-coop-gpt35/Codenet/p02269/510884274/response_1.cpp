int h(string s) {
  int ret = 0;
  int lookup[128] = {};  // Initialize the lookup table with zeros
  lookup['A'] = 1;
  lookup['C'] = 2;
  lookup['G'] = 3;
  lookup['T'] = 4;
  for (int i = 0; i < (int)s.size(); ++i) {
    ret *= 5;
    ret += lookup[s[i]];
  }
  return ret;
}