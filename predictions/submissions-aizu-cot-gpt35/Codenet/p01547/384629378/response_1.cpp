#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

typedef double D;
typedef complex<D> P;
typedef vector<P> VP;
typedef vector<VP> Vcon;
const D EPS = 1e-7;

D cross(P a, P b) { return (conj(a) * b).imag(); }
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
bool isecLP(P a1, P a2, P b) { return abs(ccw(a1, a2, b)) != 1; }
bool isecLS(P a1, P a2, P b1, P b2) {
  return cross(a2 - a1, b1 - a1) * cross(a2 - a1, b2 - a1) < EPS;
}
bool isecSS(P a1, P a2, P b1, P b2) {
  return ccw(a1, a2, b1) * ccw(a1, a2, b2) <= 0 &&
         ccw(b1, b2, a1) * ccw(b1, b2, a2) <= 0;
}
bool isecSP(P a1, P a2, P b) {
  return abs(a1 - b) + abs(a2 - b) - abs(a2 - a1) < EPS;
}
P crosspointLL(P a1, P a2, P b1, P b2) {
  D d1 = cross(b2 - b1, b1 - a1);
  D d2 = cross(b2 - b1, a2 - a1);
  if (EQ(d1, 0) && EQ(d2, 0))
    return a1;
  if (EQ(d2, 0))
    throw "kouten ga nai";
  return a1 + d1 / d2 * (a2 - a1);
}

VP convexHull(VP ps) {
  int n = ps.size(), k = 0;
  sort(ps.begin(), ps.end(), [](const P& a, const P& b) {
    return a.real() != b.real() ? a.real() < b.real() : a.imag() < b.imag();
  });
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

int inPolygon(const VP& ps, P p) {
  int n = ps.size();
  bool in = false;
  for (int i = 0, j = n - 1; i < n; j = i++) {
    if ((ps[i].imag() > p.imag()) != (ps[j].imag() > p.imag()) &&
        p.real() < (ps[j].real() - ps[i].real()) * (p.imag() - ps[i].imag()) / (ps[j].imag() - ps[i].imag()) + ps[i].real()) {
      in = !in;
    }
  }
  return in;
}

bool con_in_con(const VP& a1, const VP& a2) {