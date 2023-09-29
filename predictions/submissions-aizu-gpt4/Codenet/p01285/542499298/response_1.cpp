#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef complex<ld> P;
typedef vector<P> VP;
const ld eps = 1e-8, pi = acos(-1.0);

bool eq(ld a, ld b) { return abs(a - b) < eps; }

ld dot(P a, P b) { return real(conj(a) * b); }

ld cross(P a, P b) { return imag(conj(a) * b); }

bool isIntersectSP(P a1, P a2, P b) {
  return abs(a1 - b) + abs(a2 - b) - abs(a2 - a1) < eps;
}

bool isIntersectSS(P a1, P a2, P b1, P b2) {
  if (isIntersectSP(a1, a2, b1) || isIntersectSP(a1, a2, b2) ||
      isIntersectSP(b1, b2, a1) || isIntersectSP(b1, b2, a2))
    return true;
  return cross(a2 - a1, b1 - a1) * cross(a2 - a1, b2 - a1) < eps &&
         cross(b2 - b1, a1 - b1) * cross(b2 - b1, a2 - b1) < eps;
}

P crosspointSS(P a1, P a2, P b1, P b2) {
  ld d1 = cross(b2 - b1, b1 - a1), d2 = cross(b2 - b1, a2 - a1);
  if (eq(d1, 0) && eq(d2, 0)) return a1;
  return a1 + d1 / (d1 + d2) * (a2 - a1);
}

bool isParallel(P a1, P a2, P b1, P b2) {
  return abs(cross(a1 - a2, b1 - b2)) < eps;
}

vector<P> crosspointCL(P a1, P a2, P b, ld r) {
  vector<P> res;
  P base = a2 - a1;
  ld t = dot(b - a1, base);
  P n = base * t / norm(base) + a1;
  ld d = abs(n - b);
  if (r + eps < d) return res;
  ld len = sqrt(r * r - d * d);
  res.push_back(n + len * base / abs(base));
  res.push_back(n - len * base / abs(base));
  return res;
}

vector<P> crosspointCS(P a1, P a2, P b, ld r) {
  vector<P> tmp = crosspointCL(a1, a2, b, r), res;
  for (P p : tmp)
    if (dot(a2 - a1, p - a1) < eps) res.push_back(p);
  return res;
}

vector<P> tangentPoints(P a, ld ar, P b, ld br) {
  vector<P> res;
  ld g = abs(b - a);
  if (g < eps) return res;
  P u = (b - a) / g;
  P v(-u.imag(), u.real());
  for (int s : {-1, 1}) {
    ld h = (ar + s * br) / g;
    if (h * h > 1) continue;
    P U = h * v;
    for (int t : {-1, 1}) res.push_back(a + ar * (U + t * sqrt(max(ld(0), 1 - norm(U))) * u));
  }
  return res;
}

vector<P> crosspointCC(P a, ld ar, P b, ld br) {
  vector<P> res;
  ld d = abs(b - a);
  ld rc = (d * d + ar * ar - br * br) / (2 * d);
  ld rs = sqrt(ar * ar - rc * rc);
  if (isnan(rs)) {
    if (eq(d, ar + br)) res.push_back(a + (b - a) * ar / d);
    return res;
  }
  P diff = (b - a) / d;
  res.push_back(a + diff * P(rc, rs));
  res.push_back(a + diff * P(rc, -rs));
  return res;
}

int main() {
  int N;
  while (cin >> N, N) {
    VP p(N * 2);
    for (int i = 0; i < N * 2; i += 2) {
      ld x1, y1, x2, y2;
      cin >> x1 >> y1 >> x2 >> y2;
      p[i] = P(x1, y1);
      p[i + 1] = P(x2, y2);
    }
    vector<VP> segs;
    for (int i = 0; i < N * 2; i += 2) {
      segs.push_back(VP{p[i], p[i + 1]});
      for (int j = 0; j < i; j += 2)
        if (isIntersectSS(p[i], p[i + 1], p[j], p[j + 1])) {
          P cp = crosspointSS(p[i], p[i + 1], p[j], p[j + 1]);
          segs.back().push_back(cp);
          for (int k = 0; k < (int)segs.size() - 1; ++k)
            for (int l = 0; l < (int)segs[k].size() - 1; ++l)
              if (isIntersectSP(segs[k][l], segs[k][l + 1], cp)) segs[k].insert(segs[k].begin() + l + 1, cp);
        }
    }
    for (auto &seg : segs) sort(seg.begin(), seg.end());
    ld ans = 1e30;
    for (int i = 0; i < N * 2; i += 2)
      for (int j = 0; j < i; j += 2) {
        if (isParallel(p[i], p[i + 1], p[j], p[j + 1])) {
          vector<P> cps = crosspointCL(p[j], p[j + 1], p[i], abs(p[i + 1] - p[i]) / 2);
          for (P cp : cps)
            if (isIntersectSP(p[i], p[i + 1], cp) && isIntersectSP(p[j], p[j + 1], cp)) ans = min(ans, abs(p[i + 1] - p[i]) / 2);
        } else {
          P cp = crosspointSS(p[i], p[i + 1], p[j], p[j + 1]);
          if (isIntersectSP(p[i], p[i + 1], cp)) ans = min(ans, abs(p[i + 1] - p[i]) / 2);
          if (isIntersectSP(p[j], p[j + 1], cp)) ans = min(ans, abs(p[j + 1] - p[j]) / 2);
        }
        vector<P> tp1 = tangentPoints(p[i], abs(p[i + 1] - p[i]) / 2, p[j], abs(p[j + 1] - p[j]) / 2);
        for (P tp : tp1)
          if (isIntersectSP(p[i], p[i + 1], tp) && isIntersectSP(p[j], p[j + 1], tp)) ans = min(ans, abs(p[i + 1] - p[i]) / 2);
        vector<P> tp2 = tangentPoints(p[j], abs(p[j + 1] - p[j]) / 2, p[i], abs(p[i + 1] - p[i]) / 2);
        for (P tp : tp2)
          if (isIntersectSP(p[i], p[i + 1], tp) && isIntersectSP(p[j], p[j + 1], tp)) ans = min(ans, abs(p[j + 1] - p[j]) / 2);
        vector<P> cp1 = crosspointCC(p[i], abs(p[i + 1] - p[i]) / 2, p[j], abs(p[j + 1] - p[j]) / 2);
        for (P cp : cp1)
          if (isIntersectSP(p[i], p[i + 1], cp) && isIntersectSP(p[j], p[j + 1], cp)) ans = min(ans, abs(p[i + 1] - p[i]) / 2);
        vector<P> cp2 = crosspointCC(p[j], abs(p[j + 1] - p[j]) / 2, p[i], abs(p[i + 1] - p[i]) / 2);
        for (P cp : cp2)
          if (isIntersectSP(p[i], p[i + 1], cp) && isIntersectSP(p[j], p[j + 1], cp)) ans = min(ans, abs(p[j + 1] - p[j]) / 2);
      }
    for (int i = 0; i < (int)segs.size(); ++i)
      for (int j = 0; j < (int)segs[i].size() - 1; ++j) {
        P mid = (segs[i][j] + segs[i][j + 1]) / (ld)2;
        ld r = abs(segs[i][j + 1] - segs[i][j]) / 2;
        bool ok = true;
        for (int k = 0; k < (int)segs.size(); ++k)
          for (int l = 0; l < (int)segs[k].size() - 1; ++l)
            if (i != k || (j != l && j + 1 != l)) {
              if (k == i && isParallel(p[i], p[i + 1], segs[k][l], segs[k][l + 1])) continue;
              vector<P> cps = crosspointCS(segs[k][l], segs[k][l + 1], mid, r);
              for (P cp : cps)
                if (isIntersectSP(mid, segs[i][j + 1], cp) && isIntersectSP(segs[k][l], segs[k][l + 1], cp)) {
                  ok = false;
                  break;
                }
              if (!ok) break;
            }
        if (ok) ans = min(ans, r);
      }
    if (ans > 1e29)
      cout << "Many" << endl;
    else
      printf("%.10Lf\n", ans);
  }
}