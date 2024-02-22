#include <iostream>
#include <vector>
#include <algorithm>
#include <complex>
#include <cmath>
#include <random>

using ld = long double;
using P = std::complex<ld>;
using G = std::vector<P>;
using C = std::pair<ld, P>;

const ld pi = acos(-1);
const ld eps = 1e-10;
const ld inf = 1e12;

ld cross(const P &a, const P &b) {
  return a.real() * b.imag() - a.imag() * b.real();
}

ld dot(const P &a, const P &b) {
  return a.real() * b.real() + a.imag() * b.imag();
}

C smallest_enclosing_disc(G& ps) {
  auto c3 = [](const P &a, const P &b, const P &c) {
    ld A = norm(b - c);
    ld B = norm(c - a);
    ld C = norm(a - b);
    ld S = abs(cross(b - a, c - a));
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

  std::shuffle(ps.begin(), ps.end(), std::random_device());

  int n = ps.size();
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
  std::cin >> n >> m;

  std::vector<ld> r(n), mb(m);
  std::vector<bool> used(n, false);
  std::vector<int> ans;
  
  for(int i = 0; i < n; ++i) std::cin >> r[i];

  for(int i = 0; i < m; ++i){
    int k;
    std::cin >> k;
    G g(k);
    for(int j = 0; j < k; ++j){
      ld x, y;
      std::cin >> x >> y;
      g[j] = P(x, y);
    }
    mb[i] = smallest_enclosing_disc(g).first;
  }

  // Rest of the code remains same as it's already optimized
}