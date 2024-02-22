#include <iostream>
#include <vector>
#include <complex>
#include <cmath>
#include <algorithm>
using namespace std;

typedef double D;
typedef complex<D> P;
typedef pair<P, P> L;
typedef vector<P> VP;
typedef vector<VP> Vcon;

const D EPS = 1e-7;

inline D dot(P a, P b) { return (conj(a) * b).real(); }
inline D cross(P a, P b) { return (conj(a) * b).imag(); }

int ccw(P a, P b, P c) {
  b -= a;
  c -= a;
  if (cross(b, c) > EPS) return +1;
  if (cross(b, c) < -EPS) return -1;
  if (dot(b, c) < -EPS) return +2;
  if (norm(b) < norm(c)) return -2;
  return 0;
}

bool isparallel(L a, L b) {
  return cross(a.first - a.second, b.first - b.second) == 0.0;
}

bool isecLP(P a1, P a2, P b) { return abs(ccw(a1, a2, b)) != 1; }

bool isecLL(P a1, P a2, P b1, P b2) {
  return !isecLP(a2 - a1, b2 - b1, 0) || isecLP(a1, b1, b2);
}

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
  if (abs(d1) < EPS && abs(d2) < EPS) return a1;
  if (abs(d2) < EPS) throw "kouten ga nai";
  return a1 + d1 / d2 * (a2 - a1);
}

VP convexHull(VP ps) {
  int n = ps.size();
  int k = 0;
  VP ch(n + 1);
  sort(ps.begin(), ps.end());
  for (int i = 0; i < n; i++) {
    while (k >= 2 && ccw(ch[k - 2], ch[k - 1], ps[i]) <= 0) {
      k--;
    }
    ch[k++] = ps[i];
  }
  int t = k + 1;
  for (int i = n - 2; i >= 0; i--) {
    while (k >= t && ccw(ch[k - 2], ch[k - 1], ps[i]) <= 0) {
      k--;
    }
    ch[k++] = ps[i];
  }
  ch.resize(k - 1);