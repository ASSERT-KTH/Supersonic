int main() {
#ifdef LOCAL
  freopen("in", "r", stdin);
#endif
  while (cin >> n >> m) {
    ans.clear();
    rep(i, n) cin >> r[i];
    rep(i, m) {
      int k;
      cin >> k;
      G g(k);
      rep(j, k) {
        R x, y;
        cin >> x >> y;
        g[j] = P(x, y);
      }
      mb[i] = min_ball(g).r;
    }
    vector<int> used(m, 0);
    bool f = true;
    for(int i=0; i<m; ++i) {
      bool found = false;
      for(int j=0; j<n; ++j) {
        if (used[j])
          continue;
        R diff = mb[i] - r[j];
        if (!(diff < eps))
          continue;
        used[j] = 1;
        if (chk(i + 1)) {
          ans.push_back(j);
          found = true;
          break;
        }
        used[j] = 0;
      }
      if (!found) {
        f = false;
        break;
      }
    }
    if (f) {
      for(int i=0; i<m; ++i) cout << ans[i] + 1 << "\n";
    } else
      cout << "NG" << endl;
  }
}