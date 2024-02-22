#include <cstdio>
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
  std::vector<Point> P;
  std::vector<Point> H;

  scanf("%d", &n);
  P.resize(n);
  for (i = 0; i < n; ++i) {
    scanf("%d%d", &P[i].x, &P[i].y);
  }
  std::sort(P.begin(), P.end());

  H.reserve(2 * n);
  H.push_back(P[0]);
  H.push_back(P[1]);
  for (i = 0; i < n - 2; ++i) {
    while (k >= 2 && direct(H[k - 2], H[k - 1], P[i + 2]))
      k--;
    H.push_back(P[i + 2]);
    k++;
  }
  H.push_back(P[n - 2]);
  for (i = n; i > 2; --i) {
    while (k >= 2 && direct(H[k - 2], H[k - 1], P[i - 3]))
      k--;
    H.push_back(P[i - 3]);
    k++;
  }

  printf("%d\n", k - 1);
  for (i = 0; i < k - 1; ++i) {
    printf("%d %d\n", H[i].x, H[i].y);
  }
  
  return 0;
}