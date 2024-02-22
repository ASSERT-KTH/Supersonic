#include <iostream>
#include <vector>
#include <complex>
#include <algorithm>
using namespace std;

typedef double D;
typedef complex<D> P;
typedef vector<P> VP;
typedef vector<VP> Vcon;

const D EPS = 1e-7;

D cross(P a, P b) { return (conj(a) * b).imag(); }
D dot(P a, P b) { return (conj(a) * b).real(); }

int ccw(P a, P b, P c) {
  b -= a;
  c -= a;
  D cross_product = cross(b, c);
  if (cross_product > EPS)
    return +1;
  if (cross_product < -EPS)
    return -1;
  if (dot(b, c) < -EPS)
    return +2;
  if (norm(b) < norm(c))
    return -2;
  return 0;
}

VP convexHull(VP ps) {
  int n = ps.size(), k = 0;
  sort(ps.begin(), ps.end());
  VP ch(2 * n);
  for (int i = 0; i < n; ch[k++] = ps[i++])
    while (k >= 2 && ccw(ch[k - 2], ch[k - 1], ps[i]) <= 0)
      --k;
  for (int i = n - 2, t = k + 1; i >= 0; ch[k++] = ps[i--])
    while (k >= t && ccw(ch[k - 2], ch[k - 1], ps[i]) <= 0)
      --k;
  ch.resize(k - 1);
  return ch;
}

bool isecSP(P a1, P a2, P b) { return abs(a1 - b) + abs(a2 - b) - abs(a2 - a1) < EPS; }

bool isecSS(P a1, P a2, P b1, P b2) {