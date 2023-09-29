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
inline bool direct(Point &base, Point &a, Point &b) {
  return (a.x - base.x) * (b.y - base.y) - (a.y - base.y) * (b.x - base.x) < 0;
}
int main() {
  int n, i;
  int k = 2;
  Point *P;
  Point *H;
  scanf("%d", &n);
  P = new Point[n];
  for (i = 1; i <= n; ++i) {
    scanf("%d%d", &P[i - 1].x, &P[i - 1].y);
  }
  sort(P, P + n);
  H = new Point[2 * n];
  H[0] = P[0];
  H[1] = P[1];
  for (i = 0; i < n - 2; ++i) {
    while (k >= 2 && direct(H[k - 2], H[k - 1], P[i + 2]))
      k--;
    H[k++] = P[i + 2];
  }
  H[k++] = P[n - 2];
  for (i = n; i > 2; i--) {
    while (k >= 2 &&direct(H[k - 2], H[k - 1], P[i - 3]))
      k--;
    H[k++] = P[i - 3];
  }
  printf("%d\n", k - 1);
  for (i =