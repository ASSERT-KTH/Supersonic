#include <vector>
#include <complex>
#include <algorithm>
#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::complex;

using ld = long double;
using P = complex<ld>;
using C = std::pair<ld, P>;

ld cross(const P &a, const P &b) {
  return a.real() * b.imag() - a.imag() * b.real();
}

C smallest_enclosing_disc(vector<P> ps) {
  auto c3 = [](const P &a, const P &b, const P &c) {
    ld A = norm(b - c);
    ld B = norm(c - a);
    ld C = norm(a - b);
    ld S = abs(cross(b - a, c - a));
    P p = (A * (B + C - A) * a + B * (C + A - B) * b + C * (A + B - C) * c) /
          (4 * S * S);
    ld r = abs(p - a);
    return std::make_pair(r, p);
  };
  auto c2 = [](const P &a, const P &b) {
    P c = (a + b) / (ld)2;
    ld r = abs(a - c);
    return std::make_pair(r, c);
  };
  auto in_circle = [](const P &a, const C &c) {
    return norm(a - c.second) <= c.first * c.first;
  };
  int n = ps.size();
  std::random_shuffle(ps.begin(), ps.end());
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

  vector<ld> r(n), mb(m);
  vector<int> ans;
  vector<bool> used(n, false);

  for (int i = 0; i < n; ++i) cin >> r[i];
  for (int i = 0; i < m; ++i) {
    int k;
    cin >> k;
    vector<P> g(k);
    for (int j = 0; j < k; ++j) {
      ld x, y;
      cin >> x >> y;
      g[j] = P(x, y);
    }
    mb[i] = smallest_enclosing_disc(g).first;
  }

  for (int i = 0; i < m; ++i) {
    bool found = false;
    for (int j = 0; j < n; ++j) {
      if (used[j] || !(mb[i] < r[j])) continue;
      used[j] = true;
      found = true;
      if (auto it = std::lower_bound(r.begin(), r.end(), mb[i]); it != r.end()) {
        ans.push_back(std::distance(r.begin(), it));
      }
      used[j] = false;
      if (found) break;
    }
    if (!found) {
      cout << "NG" << endl;
      return 0;
    }
  }
  
  for (const auto &a : ans) cout << a + 1 << "\n";
  return 0;
}