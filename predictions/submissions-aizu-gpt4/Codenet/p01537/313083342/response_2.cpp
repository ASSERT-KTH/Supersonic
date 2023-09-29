#include <complex>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>
#include <iostream>

using namespace std;
using ld = long double;
using P = complex<ld>;
using C = pair<ld, P>;

const ld eps = 1e-10;

C smallest_enclosing_disc(vector<P> ps) {
  auto c3 = [](const P &a, const P &b, const P &c) {
    ld A = norm(b - c);
    ld B = norm(c - a);
    ld C = norm(a - b);
    ld S = abs((b - a).real() * (c - a).imag() - (b - a).imag() * (c - a).real());
    P p = (A * (B + C - A) * a + B * (C + A - B) * b + C * (A + B - C) * c) / (4 * S * S);
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
  
  random_shuffle(ps.begin(), ps.end());
  C c = c2(ps[0], ps[1]);
  for (size_t i = 2; i < ps.size(); ++i) {
    if (!in_circle(ps[i], c)) {
      for (size_t j = 0; j < i; ++j) {
        if (!in_circle(ps[j], c)) {
          for (size_t k = 0; k < j; ++k) {
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
  for(auto& ri : r) cin >> ri;
  vector<bool> used(n);
  vector<int> ans;
  
  for(auto& mbi : mb) {
    int k;
    cin >> k;
    vector<P> g(k);
    for(auto& gj : g) {
      ld x, y;
      cin >> x >> y;
      gj = P(x, y);
    }
    mbi = smallest_enclosing_disc(move(g)).first;
  }
  
  for(int i = 0; i < m; ++i) {
    bool found = false;
    for (int j = 0; j < n; ++j) {
      if (used[j] || !(mb[i] < r[j] + eps)) continue;
      used[j] = true;
      if (is_sorted(r.begin(), r.begin() + i+1) && is_sorted(mb.begin(), mb.begin() + i+1)) {
        ans.push_back(j);
        found = true;
        break;
      }
      used[j] = false;
    }
    if (!found) {
      cout << "NG" << endl;
      return 0;
    }
  }
  for(auto& ansi : ans) cout << ansi + 1 << "\n";
  return 0;
}