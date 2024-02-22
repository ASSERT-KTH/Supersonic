int damerau_levenshtein_distance(const string& a, const string& b, const int alphabet_size) {
  unordered_map<int, int> da;
  vector<int> d(b.size() + 1), prev_d(b.size() + 1);
  int maxdist = a.size() + b.size();
  prev_d[0] = maxdist;

  for (int i = 0; i <= a.size(); ++i) {
    d[0] = i;
    for (int j = 1; j <= b.size(); ++j) {
      int k = da[b[j - 1]], l = j - 1, cost;
      if (a[i - 1] == b[j - 1]) {
        cost = 0;
        l = j;
      } else {
        cost = 1;
      }
      d[j] = min({prev_d[j - 1] + cost, d[j - 1] + 1, prev_d[j] + 1, prev_d[k - 1] + (i - k - 1) + 1 + (j - l - 1)});
    }
    da[a[i - 1]] = i;
    swap(d, prev_d);
  }
  return prev_d[b.size()];
}