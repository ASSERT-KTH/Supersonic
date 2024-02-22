#include <iostream>
#include <vector>
#include <complex>
#include <algorithm>
#include <set>

using namespace std;

using ld = long double;
using P = complex<ld>;
using G = vector<P>;
const ld eps = 1e-10;

struct C {
  ld rad;
  P pnt;
};

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
    return norm(a - c.pnt) <= c.rad * c.rad + eps;
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

bool chk(const vector<ld>& a, const set<ld>& b, int i, int j) {
  int last = -1;
  for (int k = i; k < a.size(); ++k) {
    bool found = false;
    auto it = b.lower_bound(a[k]);
    if (it != b.end() && *it < a[k] + eps) {
      found = true;
      last = distance(b.begin(), it);
    }
    if (!found)
      return false;
  }
  return true;
}

int main() {
  vector<int> ans;
  int n, m;
  cin >> n >> m;
  vector<ld> r(n), mb(m);
  for (int i = 0; i < n; ++i)
    cin >> r[i];
  for (int i = 0; i < m; ++i) {
    int k;
    cin >> k;
    G g(k);
    for (int j = 0; j < k; ++j) {
      ld x, y;
      cin >> x >> y;
      g[j] = P(x, y);
    }
    mb[i] = smallest_enclosing_disc(g).rad;
  }
  set<ld> b(r.begin(), r.end());
  bool f = true;
  for (int i = 0; i < m; ++i) {
    bool found = false;
    for (int j = 0; j < n; ++j) {
      if (b.count(r[j]) == 0)
        continue;
      if (!(mb[i] < r[j] + eps))
        continue;
      b.erase(r[j]);
      if (chk(mb, b, i + 1, j)) {
        ans.push_back(j);
        found = true;
        break;
      }
      b.insert(r[j]);
    }
    if (!found) {
      f = false;
      break;
    }
  }
  if (f) {
    for (int i = 0; i < m; ++i)
      cout << ans[i] + 1 << "\n";
  } else {
    cout << "NG" << endl;
  }
}