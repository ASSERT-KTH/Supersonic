// ... (the same until the main function)

signed main() {
  vector<P> s1, s2;
  int n, m, q;
  cin >> n;
  VP V[n];
  rep(i, n) {
    cin >> m;
    D x[m], y[m];
    rep(j, m) {
      cin >> x[j] >> y[j];
      V[i].push_back(P(x[j], y[j]));
    }
    rep(j, m) {
      s1.push_back(P(x[j], y[j]));
      s2.push_back(P(x[(j + 1) % m], y[(j + 1) % m]));
    }
  }
  VP convex;
  convex.push_back(P(-200000, -200000));
  convex.push_back(P(200000, -200000));
  convex.push_back(P(200000, 200000));
  convex.push_back(P(-200000, 200000));
  Vcon v;
  divide_convex(convex, s1, s2, v);
  vector<vector<int>> a = Convex_arrangement(v);
  int cnt[v.size()] = {};
  rep(i, v.size()) {
    rep(j, n) {
      if (con_in_con(V[j], v[i])) {
        cnt[i]++;
      }
    }
  }
  rep(i, v.size()) {
    rep(j, v.size()) {
      if (i == j)
        a[i][j] = 0;
      if (a[i][j] == 1) {
        a[i][j] = abs(cnt[i] - cnt[j]);
      }
    }
  }
  rep(k, v.size()) rep(i, v.size()) rep(j, v.size()) a[i][j] =
      min(a[i][j], a[i][k] + a[k][j]);
  cin >> q;
  while (q--) {
    int A = 1e9, B = 1e9;
    D a1, a2, b1, b2;
    cin >> a1 >> a2 >> b1 >> b2;
    int inPolyA, inPolyB;
    rep(i, v.size()) {
      inPolyA = inPolygon(v[i], P(a1, a2));
      if (inPolyA) {
        A = i;
        if (inPolyA == 1)
          break;
      }
    }
    rep(i, v.size()) {
      inPolyB = inPolygon(v[i], P(b1, b2));
      if (inPolyB) {
        B = i;
        if (inPolyB == 1)
          break;
      }
    }
    cout << a[A][B] << endl;
  }
}