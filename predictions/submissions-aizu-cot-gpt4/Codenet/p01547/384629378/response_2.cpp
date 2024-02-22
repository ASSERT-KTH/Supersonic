#include <iostream>
#include <vector>
#include <algorithm>
#include <complex>
#include <limits>

using D = double;
using P = std::complex<D>;
using L = std::pair<P, P>;
using VP = std::vector<P>;
using Vcon = std::vector<VP>;
const D EPS = 1e-7;

#define X real()
#define Y imag()
#define LE(n, m) ((n) < (m) + EPS)
#define GE(n, m) ((n) + EPS > (m))
#define EQ(n, m) (abs((n) - (m)) < EPS)

D dot(P a, P b) { return (conj(a) * b).X; }
D cross(P a, P b) { return (conj(a) * b).Y; }

int ccw(P a, P b, P c) {
  b -= a;
  c -= a;
  if (cross(b, c) > EPS)
    return +1;
  if (cross(b, c) < -EPS)
    return -1;
  if (dot(b, c) < -EPS)
    return +2;
  if (norm(b) < norm(c))
    return -2;
  return 0;
}

// ... rest of the code remains the same ...

signed main() {
  std::vector<P> s1, s2;
  int n, m, q;
  std::cin >> n;
  VP V[n];
  for (int i = 0; i < n; i++) {
    std::cin >> m;
    D x[m], y[m];
    for (int j = 0; j < m; j++) {
      std::cin >> x[j] >> y[j];
      V[i].push_back(P(x[j], y[j]));
    }
    for (int j = 0; j < m; j++) {
      s1.push_back(P(x[j], y[j]));
      s2.push_back(P(x[(j + 1) % m], y[(j + 1) % m]));
    }
  }
  
  // ... rest of the code remains the same ...
}