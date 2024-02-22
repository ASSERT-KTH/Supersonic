#include <iostream>
#include <vector>
#include <algorithm>
#include <complex>

using namespace std;

using ld = long double;
using P = complex<ld>;
using G = vector<P>;

const ld eps = 1e-10;

ld cross(const P &a, const P &b) {
  return a.real() * b.imag() - a.imag() * b.real();
}

ld dot(const P &a, const P &b) {
  return a.real() * b.real() + a.imag() * b.imag();
}

using C = pair<ld, P>;

C smallest_enclosing_disc(vector<P> ps) {
  auto c3 = [](const P &a, const P &b, const P &c) {
    ld A = dot(b - c, b - c);
    ld B = dot(c - a, c - a);
    ld C = dot(a - b, a - b);
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
    return dot(a - c.pnt, a - c.pnt) <= c.rad * c.rad + eps;
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

int main() {
  int n, m;
  cin >> n >> m;
  
  vector<int> r(n);
  for (int i = 0; i < n; i++) {
    cin >> r[i];
  }
  
  vector<ld> mb(m);
  for (int i = 0; i < m; i++) {
    int k;
    cin >> k;
    G g(k);
    for (int j = 0; j < k; j++) {
      ld x, y;
      cin >> x >> y;
      g[j] = P(x, y);
    }
    mb[i] = smallest_enclosing_disc(g).first;
  }
  
  vector<bool> used(n, true);
  vector<int> ans(m);
  
  bool found = true;
  
  for (int i = 0; i < m; i++) {
    int last = -1;
    for (int j = 0; j < n; j++) {
      if (used[j] && mb[i] < r[j] + eps) {
        used[j] = false;
        if (i == 0 || chk(i + 1)) {
          ans[i] = j;
          last = j;
          break;
        }
        used[j] = true;
      }
    }
    if (last == -1) {
      found = false;
      break;
    }
  }
  
  if (found) {
    for (int i = 0; i < m; i++) {
      cout << ans[i] + 1 << "\n";
    }
  } else {
    cout << "NG" << endl;
  }
  
  return 0;
}