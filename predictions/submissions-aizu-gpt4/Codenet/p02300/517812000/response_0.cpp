#include <algorithm>
#include <cstdio>
using namespace std;
class Point {
public:
  int x, y;
  Point(int a = 0, int b = 0) : x(a), y(b) {}
  bool operator<(const Point &p) const {
    return y < p.y || (y == p.y && x < p.x);
  }
};
inline bool direct(Point &base, Point &a, Point &b) {
  return (long long)(a.x - base.x) * (b.y - base.y) - (long long)(a.y - base.y) * (b.x - base.x) < 0;
}
int main() {
  int n;
  scanf("%d", &n);
  Point P[n];
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &P[i].x, &P[i].y);
  }
  sort(P, P + n);
  Point H[2 * n];
  int k = 0;
  for (int i = 0; i < n; ++i) {
    while (k >= 2 && direct(H[k - 2], H[k - 1], P[i])) --k;
    H[k++] = P[i];
  }
  for (int i = n - 2, t = k + 1; i >= 0; --i) {
    while (k >= t && direct(H[k - 2], H[k - 1], P[i])) --k;
    H[k++] = P[i];
  }
  printf("%d\n", k - 1);
  for (int i = 0; i < k - 1; ++i) {
    printf("%d %d\n", H[i].x, H[i].y);
  }
  return 0;
}