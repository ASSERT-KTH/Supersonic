#include <bits/stdc++.h>
using namespace std;
using ld = long double;
using P = complex<ld>;
using C = pair<ld, P>;
#define rad first
#define pnt second

C smallest_enclosing_disc(vector<P>& ps) {
  auto c3 = [](const P &a, const P &b, const P &c) {
    ld A = norm(b - c);
    ld B = norm(c - a);
    ld C = norm(a - b);
    ld S = abs(cross(b - a, c - a));
    P p = (A * (B + C - A) * a + B * (C + A - B) * b + C * (A + B - C) * c) /
          (4 * S * S);
    ld r = abs(p - a);
    return make_pair(r, p);
  };
  auto c2 = [](const P &a, const P &b) {
    P c = (a + b) / (ld)2;
    ld r = abs(a - c);
    return make_pair(r, c);
  };
  auto in_circle = [](const P &a, const C &c) {
    return norm(a - c.pnt) <= c.rad * c.rad + 1e-10;
  };

  random_shuffle(ps.begin(), ps.end());
  C c = c2(ps[0], ps[1]);
  for (int i = 2; i < ps.size(); ++i)
    if (!in_circle(ps[i], c))
      for (int j = 0; j < i; ++j)
        if (!in_circle(ps[j], c = c2(ps[i], ps[j])))
          for (int k = 0; k < j; ++k)
            if (!in_circle(ps[k], c))
              c = c3(ps[i], ps[j], ps[k]);
  return c;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<ld> r(n), mb(m);
  vector<bool> used(n);
  for(ld& ri : r) cin >> ri;
  for(ld& mbi : mb) {
    int k;
    cin >> k;
    vector<P> g(k);
    for(P& gj : g) {
      ld x, y;
      cin >> x >> y;
      gj = P(x, y);
    }
    mbi = smallest_enclosing_disc(g).rad;
  }
  vector<int> ans;
  for(int i = 0; i < m; i++) {
    bool found = false;
    for(int j = 0; j < n; j++) {
      if (used[j] || !(mb[i] < r[j] + 1e-10)) continue;
      used[j] = true;
      if (is_sorted(used.begin(), used.end()))
        ans.push_back(j), found = true;
      used[j] = false;
    }
    if (!found)
      return cout << "NG" << endl, 0;
  }
  for(int& ansi : ans) cout << ansi + 1 << "\n";
}