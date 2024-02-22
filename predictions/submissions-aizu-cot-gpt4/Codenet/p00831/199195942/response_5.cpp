int damerau_levenshtein_distance(const string &a, const string &b, const int alphabet_size) {
  vector<int> da(alphabet_size, -1);
  vector<vector<int>> d(a.size() + 1, vector<int>(b.size() + 1));
  int maxdist = a.size() + b.size();
  d[0][0] = maxdist;
  for (int i = 0; i <= a.size(); ++i) {
    d[i][0] = i;
  }
  for (int i = 0; i <= b.size(); ++i) {
    d[0][i] = i;
  }
  for (int i = 1; i <= a.size(); ++i) {
    int db = 0;
    for (int j = 1; j <= b.size(); ++j) {
      int k = da[b[j - 1]], l = db, cost;
      if (a[i - 1] == b[j - 1]) {
        cost = 0;
        db = j;
      } else
        cost = 1;
      d[i][j] = min({d[i - 1][j - 1] + cost, d[i][j - 1] + 1, d[i - 1][j] + 1,
                     d[k][l] + (i - k - 1) + 1 + (j - l - 1)});
    }
    da[a[i - 1]] = i;
  }
  return d[a.size()][b.size()];
}