#include <bits/stdc++.h>
using namespace std;
using ld = long double;
using P = complex<ld>;
using G = vector<P>;
const ld eps = 1e-10;
const ld inf = 1e12;
ld cross(const P &a, const P &b) {
  return a.real() * b.imag() - a.imag() * b.real();
}
ld dot(const P &a, const P &b) {
  return a.real() * b.real() + a.imag() * b.imag();
}
using C = pair<ld, P>;
C smallest_enclosing_disc(vector<P> ps) {
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
    return norm(a - c.second) <= c.first * c.first + eps;
  };
  int n = ps.size();
  random_shuffle(ps.begin(), ps.end());
  C c = c2(ps[0], ps[1]);
  for (int i = 2; i < n; ++i) {
    if (!in_circle(ps[i], c)) {
      c = c2(ps[0], ps[i]);
      for (int j = 1; j < i; ++j) {
        if (!in_circle(ps[j], c)) {
          c = c2(ps[j], ps[i]);
          for (int k = 0; k < j; ++k) {
            if (!in_circle(ps[k], c)) {
              c = c3(ps[i], ps[j], ps[k]);
            }
          }
        }
      }
    }
  }
  return c;
}
int main() {
  int n, m;
  cin >> n >> m;
  vector<ld> r(n);
  for (int i = 0; i < n; ++i) cin >> r[i];
  vector<ld> mb(m);
  for (int i = 0; i < m; ++i) {
    int k;
    cin >> k;
    G g(k);
    for (int j = 0; j < k; ++j) {
      ld x, y;
      cin >> x >> y;
      g[j] = P(x, y);
    }
    mb[i] = smallest_enclosing_disc(g).first;
  }
  vector<int> ans(m);
  iota(ans.begin(), ans.end(), 0);
  sort(ans.begin(), ans.end(), [&](int i, int j) { return mb[i] < mb[j]; });
  vector<bool> used(n, false);
  bool f = true;
  for (int i = 0; i < m; ++i) {
    bool found = false;
    int j = 0;
    for (; j < n; ++j) {
      if (used[j]) continue;
      if (r[j] + eps < mb[ans[i]]) break;
      used[j] = true;
      if (i == m - 1 || mb[ans[i]] + eps < mb[ans[i + 1]]) {
        found = true;
        break;
      }
      used[j] = false;
    }
    if (!found) {
      f = false;
      break;
    }
    ans[i] = j;
  }
  if (f) {
    for (int i = 0; i < m; ++i) cout << ans[i] + 1 << "\n";
  } else {
    cout << "NG" << endl;
  }
  return 0;
}