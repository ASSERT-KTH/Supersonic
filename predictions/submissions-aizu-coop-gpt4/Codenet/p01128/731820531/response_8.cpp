// ... (same as above)

// Custom comparator for sorting
bool comp(const pair<Point, bool>& a, const pair<Point, bool>& b) {
    return a.first < b.first;
}

int main() {
  fast_io();
  int T;
  cin >> T;
  vector<pair<Point, bool>> c;  // Move vector declaration outside loop
  while (T--) {
    c.clear();  // Clear the vector for each test case
    Seg s;
    cin >> s.first >> s.second;
    int n;
    cin >> n;
    rep(i, n) {
      Seg t;
      int o, l;
      cin >> t.first >> t.second >> o >> l;
      bool intersect = intersect_SS(s, t);  // Save result of function call
      if (intersect) {
        // Only compute rota if segments intersect
        Point rota(1, -arg(s.second - s.first));
        s.first *= rota, s.second *= rota;
        t.first *= rota, t.second *= rota;
        c.pb(mp(ip_SS(s, t), (o ^ l)));
      }
    }
    sort(c.begin(), c.end(), comp);  // Use custom comparator
    int res = 0;
    rep(i, (int)c.size() - 1) if (c[i].second != c[i + 1].second)++ res;
    cout << res << endl;
  }
}