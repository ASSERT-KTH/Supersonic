#include <iostream>
#include <vector>
#include <algorithm>

typedef double D;
typedef std::complex<D> P;
typedef std::pair<P, P> L;
typedef std::vector<P> VP;
typedef std::vector<VP> Vcon;

const D EPS = 1e-7;

D dot(P a, P b) { return (std::conj(a) * b).real(); }
D cross(P a, P b) { return (std::conj(a) * b).imag(); }

int ccw(P a, P b, P c) {
  b -= a;
  c -= a;
  if (cross(b, c) > EPS)
    return +1;
  if (cross(b, c) < -EPS)
    return -1;
  if (dot(b, c) < -EPS)
    return +2;
  if (std::norm(b) < std::norm(c))
    return -2;
  return 0;
}

VP convexHull(VP ps) {
  int n = ps.size();
  std::sort(ps.begin(), ps.end());
  VP ch;
  ch.reserve(n);
  for (int i = 0; i < n; i++) {
    while (ch.size() >= 2 && ccw(ch[ch.size() - 2], ch[ch.size() - 1], ps[i]) <= 0)
      ch.pop_back();
    ch.emplace_back(ps[i]);
  }
  int t = ch.size() + 1;
  for (int i = n - 2; i >= 0; i--) {
    while (ch.size() >= t && ccw(ch[ch.size() - 2], ch[ch.size() - 1], ps[i]) <= 0)
      ch.pop_back();
    ch.emplace_back(ps[i]);
  }
  ch.pop_back();
  return ch;
}

std::vector<std::vector<int>> Convex_arrangement(const Vcon &ps) {
  int n = ps.size();
  std::vector<std::vector<int>> V(n, std::vector<int>(n, 1e8));
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (isecCC(ps[i], ps[j])) {
        V[i][j] = 1;
        V[j][i] = 1;
      }
    }
  }
  return V;
}

int main() {
  int n, m, q;
  std::cin >> n;
  VP V[n];
  std::vector<P> s1, s2;