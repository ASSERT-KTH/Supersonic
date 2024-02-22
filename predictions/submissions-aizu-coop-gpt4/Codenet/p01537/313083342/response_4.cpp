#include <bits/stdc++.h>
using namespace std;
using ld = long double;
using P = complex<ld>;
using C = pair<ld, P>;
using G = vector<P>;

const ld eps = 1e-10;

ld cross(const P &a, const P &b) {
  return a.real() * b.imag() - a.imag() * b.real();
}

ld norm(const P &a) {
    return a.real() * a.real() + a.imag() * a.imag();
}

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
  };

  auto in_circle = [](const P &a, const C &c) {
    return norm(a - c.second) <= c.first * c.first + eps;
  };

  int n = ps.size();
  random_shuffle(ps.begin(), ps.end());
  C c = c2(ps[0], ps[1]);
  for (int i = 2; i < n; ++i) {
    if (!in_circle(ps[i], c)) {
      c = c2(ps[0], ps[i]);
      for (int j = 1; j < i; ++j) {
        if (!in_circle(ps[j], c)) {
          c = c2(ps[j], ps[i]);
          for (int k = 0; k < j; ++k) {
            if (!in_circle(ps[k], c)) {
              c = c3(ps[i], ps[j], ps[k]);
            }
          }
        }
      }
    }
  }
  return c;
}

bool chk(int s, vector<ld> mb, vector<bool> used, vector<ld> r) {
  vector<ld> a;
  for (int i = s; i < mb.size(); ++i) a.emplace_back(mb[i]);
  sort(a.begin(), a.end());
  vector<ld> b;
  for (int i = 0; i < r.size(); ++i) if (!used[i]) b.emplace_back(r[i]);
  sort(b.begin(), b.end());
  for (ld radius : a) {
    auto it = lower_bound(b.begin(), b.end(), radius - eps);
    if (it == b.end()) return false;
    b.erase(it);
  }
  return true;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<ld> r(n), mb(m);
  for (ld &ri : r) cin >> ri;
  vector<bool> used(n, false);
  vector<int> ans;
  for (ld &mbi : mb) {
    int k;
    cin >> k;
    G g(k);
    for (P &p : g) {
      ld x, y;
      cin >> x >> y;
      p = P(x, y);
    }
    mbi = smallest_enclosing_disc(g).first;
  }
  for (int i = 0; i < m; ++i) {
    bool found = false;
    for (int j = 0; j < n; ++j) {
      if (used[j] || !(mb[i] < r[j] + eps)) continue;
      used[j] = true;
      if (chk(i + 1, mb, used, r)) {
        ans.push_back(j);
        found = true;
        break;
      }
      used[j] = false;
    }
    if (!found) {
      cout << "NG" << endl;
      return 0;
    }
  }
  for (int i : ans) cout << i + 1 << "\n";
}