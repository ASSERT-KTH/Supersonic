#include <complex>
#include <vector>
#include <algorithm>

using namespace std;
using D = double;
using P = complex<D>;
using VP = vector<P>;
using Vcon = vector<VP>;

const D EPS = 1e-7;

D dot(P a, P b) { return (conj(a) * b).real(); }
D cross(P a, P b) { return (conj(a) * b).imag(); }

int ccw(P a, P b, P c) {
  b -= a; c -= a;
  if (cross(b, c) > EPS) return +1;
  if (cross(b, c) < -EPS) return -1;
  if (dot(b, c) < -EPS) return +2;
  if (norm(b) < norm(c)) return -2;
  return 0;
}

bool isecSP(P a1, P a2, P b) {
  return abs(a1 - b) + abs(a2 - b) - abs(a2 - a1) < EPS;
}

bool isecSS(P a1, P a2, P b1, P b2) {
  return ccw(a1, a2, b1) * ccw(a1, a2, b2) <= 0 &&
         ccw(b1, b2, a1) * ccw(b1, b2, a2) <= 0;
}

bool inPolygon(const VP &ps, P p) {
  int n = ps.size();
  bool in = false;
  for(int i = 0; i < n; i++) {
    P a = ps[i] - p;
    P b = ps[(i + 1) % n] - p;
    if (cross(a, b) == 0 && dot(a, b) <= 0) return true;
    if (a.imag() > b.imag()) swap(a, b);
    if ((a.imag() < 0 || a.imag() < EPS && b.imag() > EPS) && cross(a, b) < 0) in = !in;
  }
  return in;
}

int main() {
  int n, m, q;
  scanf("%d", &n);

  VP V[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &m);
    D x, y;
    for (int j = 0; j < m; j++) {
      scanf("%lf %lf", &x, &y);
      V[i].emplace_back(x, y);
    }
  }

  scanf("%d", &q);
  while (q--) {
    D a1, a2, b1, b2;
    scanf("%lf %lf %lf %lf", &a1, &a2, &b1, &b2);
    int A = -1, B = -1;
    for (int i = 0; i < n; i++) {
      if (inPolygon(V[i], P(a1, a2))) A = i;
      if (inPolygon(V[i], P(b1, b2))) B = i;
    }
    printf("%d\n", A == B ? 0 : 1);
  }
}