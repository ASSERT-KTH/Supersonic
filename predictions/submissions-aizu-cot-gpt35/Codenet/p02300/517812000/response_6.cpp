#include <cstdio>
#include <vector>
using namespace std;

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
  int n;
  scanf("%d", &n);

  vector<Point> P(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &P[i].x, &P[i].y);
  }

  sort(P.begin(), P.end());

  vector<Point> H;
  H.emplace_back(P[0]);
  H.emplace_back(P[1]);

  for (int i = 2; i < n; ++i) {
    while (H.size() >= 2 && direct(H[H.size() - 2], H[H.size() - 1], P[i])) {
      H.pop_back();
    }
    H.emplace_back(P[i]);
  }

  for (int i = n - 2; i > 0; --i) {
    while (H.size() >= 2 && direct(H[H.size() - 2], H[H.size() - 1], P[i - 1])) {
      H.pop_back();
    }
    H.emplace_back(P[i - 1]);
  }

  printf("%lu\n", H.size());
  for (const auto &point : H) {
    printf("%d %d\n", point.x, point.y);
  }

  return 0;
}