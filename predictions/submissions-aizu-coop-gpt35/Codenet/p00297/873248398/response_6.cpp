signed main() {
  omajinai;
  int N, d;
  cin >> N >> d;
  SegTree x_seg, y_seg;
  x_seg.init(N), y_seg.init(N);

  for (int i = 0; i < N; ++i) {
    int x, y, b;
    cin >> x >> y >> b;
    X[i] = x, Y[i] = y;
    x_seg.min_update(i, x);
    x_seg.max_update(i, x);
    y_seg.min_update(i, y);
    y_seg.max_update(i, y);
  }

  ll ans = -inf;
  for (int i = 0; i < N; ++i) {
    int b = X[i];
    int idx = upper_bound(X, X + N, b + d) - X;
    int min_x = x_seg.get_min(i, idx);
    int max_x = x_seg.get_max(i, idx);
    int min_y = y_seg.get_min(i, idx);
    int max_y = y_seg.get_max(i, idx);
    ans = max(ans, 1ll * (max_x - min_x) * (max_y - min_y));
  }

  cout << ans << endl;
}