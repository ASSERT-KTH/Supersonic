vector<int> sum_len(1 << n);
vector<int> string_lengths(n);
for (int i = 0; i < n; ++i) {
  string_lengths[i] = e[i].size();
}
for (int i = 0; i < (1 << n); ++i) {
  sum_len[i] = 0;
  for (int j = 0; j < n; ++j) {
    if ((i & (1 << j)) != 0) {
      sum_len[i] += string_lengths[j];
    }
  }
}