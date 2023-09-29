#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(c) begin(c), end(c)
#define dump(x) cerr << __LINE__ << ":\t" #x " = " << x << endl
using ld = long double;
using P = complex<ld>;
using G = vector<P>;
const ld pi = acos(-1);
const ld eps = 1e-10;
const ld inf = 1e12;
ld cross(const P &a, const P &b) {
  return a.real() * b.imag() - a.imag() * b.real();
}
ld dot(const P &a, const P &b) {
  return a.real() * b.real() + a.imag() * b.imag();
}
using C = pair<ld, P>;
#define rad first
#define pnt second
C smallest_enclosing_disc(vector<P> ps) {
  auto c3 = [](const P &a, const P &b, const P &c) {
    ld A = norm(b - c);
    ld B = norm(c - a);
    ld C = norm(a - b);
    ld S = abs(cross(b - a, c - a));
    P p = (A * (B + C - A) * a + B * (C + A - B) * b + C * (A + B - C) * c) /
           (4 * S * S);
    ld r = abs(p - a);
    return make_pair(r, p);
  };
  auto c2 = [](const P &a, const P &b) {
    P c = (a + b) / (ld)2;
    ld r = abs(a - c);
    return make_pair(r, c);