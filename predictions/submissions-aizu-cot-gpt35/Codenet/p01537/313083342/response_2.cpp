#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <complex>

using ld = long double;
using P = std::complex<ld>;

struct C {
  ld rad;
  P pnt;
};

C smallest_enclosing_disc(const std::vector<P>& ps) {
  auto c2 = [](const P& a, const P& b) {
    P c = (a + b) / (ld)2;
    ld r = std::abs(a - c);
    return C{r, c};
  };
  
  auto in_circle = [](const P& a, const C& c) {
    return std::norm(a - c.pnt) <= c.rad * c.rad + std::numeric_limits<ld>::epsilon();
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
              ld A = std::norm(ps[j] - ps[k]);
              ld B = std::norm(ps[k] - ps[i]);
              ld C = std::norm(ps[i] - ps[j]);
              ld S = std::abs(std::cross(ps[j] - ps[i], ps[k] - ps[i]));
              P p = (A * (B + C - A) * ps[i] + B * (C + A - B) * ps[j] + C * (A + B - C) * ps[k]) / (4 * S * S);
              ld r = std::abs(p - ps[i]);
              c = C{r, p};
            }
          }
        }
      }
    }
  }
  
  return c;
}

bool chk(const std::vector<int>& b, const std::vector<ld>& a) {
  int n = b.size();
  int m = a.size();
  
  std::vector<int> sorted_b = b;
  std::sort(sorted_b.begin(), sorted_b.end());
  int last = -1;
  
  for (int i = 0; i < m; ++i) {
    bool found = false;
    for (int j = last + 1; j < n; ++j) {
      if (a[i] < sorted_b[j] + std::numeric_limits<ld>::epsilon()) {
        found = true;
        last = j;
        break;
      }
    }
    if (!found) {
      return false;
    }
  }
  
  return true;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  
  std::vector<int> r(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> r[i];
  }
  
  std::vector<ld> mb(m);
  for (int i = 0; i < m; ++i) {
    int k;
    std::cin >> k;
    
    std::vector<P> g(k);
    for (int j = 0; j < k; ++j) {
      ld x, y;
      std::cin >> x >> y;
      g[j] = P(x, y);
    }
    
    mb[i] = smallest_enclosing_disc(g).rad;
  }
  
  std::vector<bool> used(n, false);
  std::vector<int> ans;
  
  bool f = true;
  int i = 0;
  int j = 0;
  
  while (i < m) {
    bool found = false;
    
    while (j < n) {
      if (used[j] || !(mb[i] < r[j] + std::numeric_limits<ld>::epsilon())) {
        ++j;
        continue;
      }
      
      used[j] = true;
      
      if (chk(r, std::vector<ld>(mb.begin() + i + 1, mb.end()))) {
        ans.push_back(j);
        found = true;
        break;
      }
      
      used[j] = false;
      ++j;
    }
    
    if (!found) {
      f = false;
      break;
    }
    
    ++i;
  }
  
  if (f) {
    for (int i = 0; i < m; ++i) {
      std::cout << ans[i] + 1 << "\n";
    }
  } else {
    std::cout << "NG" << std::endl;
  }
  
  return 0;
}