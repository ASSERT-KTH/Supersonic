#include <algorithm>
#include <complex>
#include <iostream>
#include <vector>

using namespace std;
using ld = long double;
using P = complex<ld>;
using C = pair<ld, P>;

const ld eps = 1e-10;

ld norm(const P &a, const P &b) {
  return abs(a - b);
}

C smallest_enclosing_disc(vector<P> ps) {
  auto c3 = [](const P &a, const P &b, const P &c) {
    ld A = norm(b - c);
    ld B = norm(c - a);
    ld C = norm(a - b);
    ld S = abs(((b - a) * conj(c - a)).imag());
    P p = (A * (B + C - A) * a + B * (C + A - B) * b + C * (A + B - C) * c) /
          (4 * S * S);
    ld r = norm(p - a);
    return make_pair(r, p);
  };

  auto c2 = [](const P &a, const P &b) {
    P c = (a + b) / (ld)2;
    ld r = norm(a - c);
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
  for (auto &x : r) cin >> x;
  vector<ld> mb(m);
  for (auto &x : mb) {
    int k;
    cin >> k;
    vector<P> g(k);
    for (auto &y : g) {
      ld a, b;
      cin >> a >> b;
      y = P(a, b);
    }
    x = smallest_enclosing_disc(g).first;
  }

  vector<int> ans, used(n);
  for (const auto &x : mb) {
    bool found = false;
    for (int j = 0; j < n; ++j) {
      if (used[j] || !(x < r[j] + eps)) continue;
      used[j] = true;
      if (all_of(mb.begin() + (&x - mb.data()) + 1, mb.end(),
                 [&](const ld &y) {
                   return *lower_bound(r.begin(), r.end(), y - eps) <= y + eps;
                 })) {
        ans.push_back(j);
        found = true;
        break;
      }
      used[j] = false;
    }
    if (!found) {
      cout << "NG\n";
      return 0;
    }
  }
  for (const auto &x : ans) cout << x + 1 << "\n";
}