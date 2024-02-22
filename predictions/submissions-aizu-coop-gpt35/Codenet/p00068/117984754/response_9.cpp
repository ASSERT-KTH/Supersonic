#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

class P {
public:
  double x, y;
  P(double _x = 0, double _y = 0) : x(_x), y(_y) {}
};

struct L {
  P p1, p2;
};

double cross(P a, P b) {
  return a.x * b.y - a.y * b.x;
}

bool intersect(P p1, P p2, P p3, P p4) {
  return (cross(p1 - p2, p3 - p4) <= 0 && cross(p3 - p4, p1 - p2) <= 0);
}

bool isSimple(std::vector<P>& pol) {
  size_t pol_size = pol.size() - 1;
  for (size_t i = 0; i < pol_size; i++) {
    for (size_t j = i + 2; j < pol_size; j++) {
      if (intersect(pol[i], pol[i + 1], pol[j], pol[j + 1]))
        return false;
    }
  }
  return true;
}

bool isPointInsidePolygon(std::vector<L>& side, P p) {
  int c = 0, sideSum = side.size();
  for (size_t i = 0; i < sideSum; i++) {
    if (cross(side[i].p2 - side[i].p1, p - side[i].p1) > 0)
      c++;
  }
  return !(c % sideSum);
}

bool cmp_x(const P& p, const P& q) {
  if (p.x != q.x)
    return p.x < q.x;
  return p.y < q.y;
}

std::vector<P> convex_hull(P* ps, int n) {
  std::sort(ps, ps + n, cmp_x);
  int k = 0;
  std::vector<P> qs(n * 2);
  for (int i = 0; i < n; i++) {
    while (k > 1 && cross((qs[k - 1] - qs[k - 2]), (ps[i] - qs[k - 1])) <= 0)
      k--;
    qs[k++] = ps[i];
  }
  for (int i = n - 2, t = k; i >= 0; i--) {
    while (k > t && cross((qs[k - 1] - qs[k - 2]), (ps[i] - qs[k - 1])) <= 0)
      k--;
    qs[k++] = ps[i];
  }
  qs.resize(k - 1);
  return qs;
}

int main() {
  int N;
  while (std::cin >> N && N) {
    std::vector<P> ps(N);
    for (int i = 0; i < N; i++) {
      char ch;
      std::cin >> ps[i].x >> ch >> ps[i].y;
    }
    std::vector<P> res = convex_hull(&ps[0], N);
    std::cout << N - res.size() << std::endl;
  }
  return 0;
}