// ... same as before ...

// Change the Seg struct to store the transformed segment
struct Seg {
  Point first, second;
  Point first_trans, second_trans; // transformed points
  Seg() {}
  Seg(const Point &first, const Point &second) : first(first), second(second) {
    if (first == second)
      this->first.real() += 1e-12;
  }
  void transform(const Point &rota) {
    first_trans = first * rota;
    second_trans = second * rota;
  }
};

// ... same as before ...

int main() {
  fast_io();
  int T;
  cin >> T;
  while (T--) {
    Seg s;
    cin >> s.first >> s.second;
    Point rota(1, -arg(s.second - s.first));
    s.transform(rota);
    vector<Seg> intersecting_segs;
    vector<pair<Point, bool>> c;
    int n;
    cin >> n;
    rep(i, n) {
      Seg t;
      int o, l;
      cin >> t.first >> t.second >> o >> l;
      t.transform(rota);
      if (intersect_SS(s, t))
        intersecting_segs.push_back(t);
    }
    for (const auto &t : intersecting_segs) {
      c.pb(mp(ip_SS(s, t), (o ^ l)));
    }
    sort(all(c));
    int res = 0;
    rep(i, (int)c.size() - 1) if (c[i].second != c[i + 1].second)++ res;
    cout << res << endl;
  }
}