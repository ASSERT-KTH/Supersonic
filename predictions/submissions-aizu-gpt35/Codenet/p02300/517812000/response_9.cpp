#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
class Point {
public:
  int x, y;
  Point(int a = 0, int b = 0) {
    int x = a;
    int y = b;
  };
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
  scanf("%d", &n);
  vector<Point> P(n);
  for (i = 0; i < n; ++i) {
    scanf("%d%d", &P[i].x, &P[i].y);
  }
  sort(P.begin(), P.end());
  vector<Point> H(2 * n);
  H[0] = P[0];
  H[1] = P[1];
  for (i = 2; i < n; ++i) {
    while (k >= 2 && direct(H[k - 2], H[k - 1], P[i]))
      k--;
    H[k++] = P[i];
  }
  int t = k;
  for (i = n - 2; i >= 0; --i) {
    while (k > t && direct(H[k - 2], H[k - 1], P[i]))
      k--;
    H[k++] = P[i];
  }
  printf("%d\n", k - 1);
  for (i = 0; i < k - 1; ++i) {
    printf("%d %d\n", H[i].x, H[i].y);
  }
  return 0;
}