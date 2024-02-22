#include <algorithm>
#include <iostream>
#include <vector>

class Point {
public:
  int x, y;
  Point(int a = 0, int b = 0) : x(a), y(b) {}
  bool operator<(const Point &p) const {
    return y < p.y || (y == p.y && x < p.x);
  }
};

inline bool direct(const Point &base, const Point &a, const Point &b) {
  return (a.x - base.x) * (b.y - base.y) - (a.y - base.y) * (b.x - base.x) < 0;
}

int main() {
  int n, i;
  int k = 2;
  std::cin >> n;
  std::vector<Point> P(n);
  for (i = 0; i < n; ++i) {
    std::cin >> P[i].x >> P[i].y;
  }
  std::sort(P.begin(), P.end());
  std::vector<Point> H(2 * n);
  H[0] = P[0];
  H[1] = P[1];
  for (i = 2; i < n; ++i) {
    while (k >= 2 && direct(H[k - 2], H[k - 1], P[i]))
      k--;
    H[k++] = P[i];
  }
  for (i = n - 1; i > 1; i--) {
    while (k >= 2 && direct(H[k - 2], H[k - 1], P[i - 1]))
      k--;
    H[k++] = P[i - 1];
  }
  std::cout << k - 1 << "\n";
  for (i = 0; i < k - 1; ++i) {
    std::cout << H[i].x << " " << H[i].y << "\n";
  }
  return 0;
}