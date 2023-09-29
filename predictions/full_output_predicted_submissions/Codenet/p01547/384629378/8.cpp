#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long double D;
typedef complex<D> P;
typedef pair<P, P> L;
typedef vector<P> VP;
typedef vector<VP> Vcon;
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
bool isparallel(L a, L b) {
  return cross(a.first - a.second, b.first - b.second) == 0.0;
}
bool isecLP(P a1, P a2, P b) { return abs(ccw(a1, a2, b)) != 1; }
bool isecLL(P a1, P a2, P b1, P b2) {
  return !isecLP(a2 - a1, b2 - b1, 0) || isecLP(a1, b1, b2);
}
bool isecLS(P a1, P a2, P b1, P b2) {
  return cross(a2 - a1