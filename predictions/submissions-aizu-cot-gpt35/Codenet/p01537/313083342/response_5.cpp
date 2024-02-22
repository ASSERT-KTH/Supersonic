#include <iostream>
#include <vector>
#include <complex>
#include <algorithm>
using namespace std;
using ld = long double;
using P = complex<ld>;
using G = vector<P>;
const ld eps = 1e-10;

struct C {
  ld rad;
  P pnt;
};

ld cross(const P &a, const P &b) {
  return a.real() * b.imag() - a.imag() * b.real();
}

ld dot(const P &a, const P &b) {
  return a.real() * b.real() + a.imag() * b.imag();
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
    return C{r, p};
  };

  auto c2 = [](const P &a, const P &b) {
    P c = (a + b) / (ld)2;
    ld r = abs(a - c);
    return C{r, c};
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

bool chk(int s, const vector<ld>& a, const vector<int>& b, int last) {
  for (int i = s; i < a.size(); ++i) {
    bool found = false;
    int low = last + 1, high = b.size() - 1;
    while (low <= high) {
      int mid = (low + high) / 2;
      if (a[i] < b[mid] + eps) {
        last = mid;
        found = true;
        break;
      } else {
        low = mid + 1;
      }
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
  vector<int> r(n);
  for (int i = 0; i < n; ++i) {
    cin >> r[i];
  }
  vector<ld> mb(m);
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
  vector<bool> used(n, false);
  bool f = true;
  int last = -1;
  for (int i = 0; i < m; ++i) {
    bool found = false;
    for (int j = 0; j < n; ++j) {
      if (used[j])
        continue;
      if (!(mb[i] < r[j] + eps))
        continue;
      used[j] = true;
      if (chk(i + 1, mb, r, last)) {
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
    for (int i = 0; i < m; ++i) {
      cout << ans[i] + 1 << "\n";
    }
  } else {
    cout << "NG" << endl;
  }
}