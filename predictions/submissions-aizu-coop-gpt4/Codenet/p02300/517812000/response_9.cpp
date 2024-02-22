#include <algorithm>
#include <cstdio>
#include <utility>
using namespace std;
typedef pair<int, int> Point;
#define x first
#define y second

inline bool direct(Point &base, Point &a, Point &b) {
  int dx = a.x - base.x;
  int dy = a.y - base.y;
  return dx * (b.y - base.y) - dy * (b.x - base.x) < 0;
}

int main() {
  int n, i;
  int k = 2;
  scanf("%d", &n);
  Point P[n];
  for (i = 0; i < n; ++i) {
    scanf("%d%d", &P[i].x, &P[i].y);
  }
  sort(P, P + n);
  Point H[2 * n];
  H[0] = P[0];
  H[1] = P[1];
  for (i = 2; i < n; ++i) {
    while (k >= 2 && direct(H[k - 2], H[k - 1], P[i]))
      k--;
    H[k++] = P[i];
  }
  for (i = n - 1; i >= 0; --i) {
    while (k >= 2 && direct(H[k - 2], H[k - 1], P[i]))
      k--;
    H[k++] = P[i];
  }
  printf("%d\n", k - 1);
  for (i = 0; i < k - 1; ++i) {
    printf("%d %d\n", H[i].x, H[i].y);
  }
  return 0;
}