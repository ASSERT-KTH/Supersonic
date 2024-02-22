#include <iostream>
#include <vector>
#include <complex>
#include <algorithm>

typedef double D;
typedef std::complex<D> P;
typedef std::vector<P> VP;
typedef std::vector<VP> Vcon;

const D EPS = 1e-7;

D cross(P a, P b) {
  return (std::conj(a) * b).imag();
}

int ccw(P a, P b, P c) {
  b -= a;
  c -= a;
  D cross_product = cross(b, c);
  if (cross_product > EPS)
    return 1;
  if (cross_product < -EPS)
    return -1;
  if (std::real(b) * std::real(c) < -EPS || std::imag(b) * std::imag(c) < -EPS)
    return 2;
  if (std::norm(b) < std::norm(c))
    return -2;
  return 0;
}

VP convexHull(VP ps) {
  int n = ps.size();
  std::sort(ps.begin(), ps.end(), [](const P& a, const P& b) {
    return a.real() != b.real() ? a.real() < b.real() : a.imag() < b.imag();
  });

  VP ch;
  for (int i = 0; i < n; i++) {
    while (ch.size() >= 2 && ccw(ch[ch.size() - 2], ch[ch.size() - 1], ps[i]) <= 0)
      ch.pop_back();
    ch.push_back(ps[i]);
  }

  int k = ch.size();
  for (int i = n - 2; i >= 0; i--) {
    while (ch.size() >= k + 1 && ccw(ch[ch.size() - 2], ch[ch.size() - 1], ps[i]) <= 0)
      ch.pop_back();
    ch.push_back(ps[i]);
  }

  return ch;
}

bool isecCC(const VP& a1, const VP& a2) {
  for (int i = 0; i < a1.size(); i++) {
    for (int j = 0; j < a2.size(); j++) {
      P e1 = a1[i];
      P e2 = a1[(i + 1) % a1.size()];