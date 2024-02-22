#include <iostream>
#include <vector>
#include <algorithm>
#include <complex>
#include <cmath>

using ld = long double;
using P = std::complex<ld>;
using G = std::vector<P>;
const ld eps = 1e-10;

struct C {
  ld rad;
  P pnt;
};

C smallest_enclosing_disc(std::vector<P>& ps) {
  auto c3 = [](const P &a, const P &b, const P &c) {
    ld A = std::norm(b - c);
    ld B = std::norm(c - a);
    ld C = std::norm(a - b);
    ld S = std::abs((b - a) * std::conj(c - a));
    P p = (A * (B + C - A) * a + B * (C + A - B) * b + C * (A + B - C) * c) /
          (4 * S * S);
    ld r = std::abs(p - a);
    return C{r, p};
  };

  auto c2 = [](const P &a, const P &b) {
    P c = (a + b) / (ld)2;
    ld r = std::abs(a - c);
    return C{r, c};
  };

  auto in_circle = [](const P &a, const C &c) {
    return std::norm(a - c.pnt) <= c.rad * c.rad + eps;
  };

  int n = ps.size();
  std::random_shuffle(ps.begin(), ps.end());
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

bool chk(int s, const std::vector<ld>& a, const std::vector<int>& b) {
  int n = b.size();
  int m = a.size();

  int last = -1;
  for (int i = 0; i < m; ++i) {
    bool found = false;
    for (int j = last + 1; j < n; ++j) {
      if (a[i] < b[j] + eps) {
        found = true;
        last = j;
        break;
      }
    }
    if (!found)
      return false;
  }
  return true;
}

int main() {
  std::vector<int> ans;
  int n, m;
  std::cin >> n >> m;
  std::vector<int> r(n);
  for (int i = 0; i < n; ++i)
    std::cin >> r[i];

  std::vector<ld> mb(m);
  for (int i = 0; i < m; ++i) {
    int k;
    std::cin >> k;
    G g(k);
    for (int j = 0; j < k; ++j) {
      ld x, y;
      std::cin >> x >> y;
      g[j] = P(x, y);
    }
    mb[i] = smallest_enclosing_disc(g).rad;
  }

  std::vector<bool> used(n, false);
  bool f = true;
  for (int i = 0; i < m; ++i) {
    bool found = false;
    for (int j = 0; j < n; ++j) {
      if (used[j])
        continue;
      if (!(mb[i] < r[j] + eps))
        continue;
      used[j] = true;
      if (chk(i + 1, mb, r)) {
        ans.push_back(j);
        found = true;
        break;
      }
      used[j] = false;
    }
    if (!found) {
      f = false;
      break;
    }
  }

  if (f) {
    for (int i = 0; i < m; ++i)
      std::cout << ans[i] + 1 << "\n";
  } else {
    std::cout << "NG" << std::endl;
  }

  return 0;
}