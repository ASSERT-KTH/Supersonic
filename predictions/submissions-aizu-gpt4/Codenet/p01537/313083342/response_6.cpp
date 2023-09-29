#include <bits/stdc++.h>
using namespace std;
using ld = long double;
using P = complex<ld>;
using C = pair<ld, P>;
#define rad first
#define pnt second
random_device rd;
mt19937 rng(rd());

ld cross(const P &a, const P &b) {
  return a.real() * b.imag() - a.imag() * b.real();
}

C smallest_enclosing_disc(vector<P> &ps) {
  const function<C(const P &, const P &, const P &)> c3 = 
    [](const P &a, const P &b, const P &c) {
    ld A = norm(b - c);
    ld B = norm(c - a);
    ld C = norm(a - b);
    ld S = abs(cross(b - a, c - a));
    P p = (A * (B + C - A) * a + B * (C + A - B) * b + C * (A + B - C) * c) /
          (4 * S * S);
    ld r = abs(p - a);
    return make_pair(r, p);
  };
  const function<C(const P &, const P &)> c2 = 
    [](const P &a, const P &b) {
    P c = (a + b) / (ld)2;
    ld r = abs(a - c);
    return make_pair(r, c);
  };
  const function<bool(const P &, const C &)> in_circle = 
    [](const P &a, const C &c) {
    return norm(a - c.pnt) <= c.rad * c.rad;
  };
  shuffle(ps.begin(), ps.end(), rng);
  C c = c2(ps[0], ps[1]);
  for (int i = 2; i < ps.size(); ++i) {
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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<int> r(n), order(n);
  iota(order.begin(), order.end(), 0);
  for(int &ri : r) cin >> ri;
  vector<int> ans;
  vector<ld> mb(m);
  for(ld &mbi : mb) {
    int k;
    cin >> k;
    vector<P> g(k);
    for(P &gi : g) {
      ld x, y;
      cin >> x >> y;
      gi = P(x, y);
    }
    mbi = smallest_enclosing_disc(g).rad;
  }
  sort(order.begin(), order.end(), [&r](int a, int b) {
    return r[a] < r[b];
  });
  sort(mb.begin(), mb.end());
  for(int i = 0, j = 0; i < m; ++i) {
    while(j < n && r[order[j]] < mb[i]) ++j;
    if(j == n) {
      cout << "NG\n";
      return 0;
    }
    ans.push_back(order[j++]);
  }
  for(int i : ans) cout << i + 1 << "\n";
  return 0;
}