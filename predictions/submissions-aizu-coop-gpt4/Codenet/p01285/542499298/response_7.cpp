#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define EPS (1e-6)

// ...rest of the code...

double cross3p(Point p, Point q, Point r) {
  double px_qx = p.x - q.x;
  double py_qy = p.y - q.y;
  return (r.x - q.x) * py_qy - (r.y - q.y) * px_qx;
}

bool Point::operator<(const Point &p) const {
  if (fabs(x - p.x) < EPS)
    return y < p.y;
  return x < p.x;
}

// ...rest of the code...

int main() {
  int n;
  std::ios_base::sync_with_stdio(false);  // disable synchronization between C and C++ standard streams
  while (std::cin >> n, n) {
    std::vector<Line> vec(n);
    rep(i, n) std::cin >> vec[i].p1.x >> vec[i].p1.y >> vec[i].p2.x >> vec[i].p2.y;
    compute(vec);
  }
  return 0;
}