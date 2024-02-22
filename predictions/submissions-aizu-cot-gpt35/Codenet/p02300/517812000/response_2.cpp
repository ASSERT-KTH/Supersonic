#include <cstdio>
#include <vector>
using namespace std;

class Point {
public:
  int x, y;
};

inline bool direct(Point &base, Point &a, Point &b) {
  return (a.x - base.x) * (b.y - base.y) - (a.y - base.y) * (b.x - base.x) < 0;
}

int main() {
  int n, i;
  int k = 2;
  Point P[100000];
  Point H[200000];

  scanf("%d", &n);
  for (i = 0; i < n; ++i) {
    scanf("%d%d", &P[i].x, &P[i].y);
  }

  Point minPoint = P[0];
  Point maxPoint = P[0];
  for (i = 1; i < n; ++i) {
    if (P[i].x < minPoint.x || (P[i].x == minPoint.x && P[i].y < minPoint.y)) {
      minPoint = P[i];
    }
    if (P[i].x > maxPoint.x || (P[i].x == maxPoint.x && P[i].y > maxPoint.y)) {
      maxPoint = P[i];
    }
  }

  H[0] = minPoint;
  H[1] = maxPoint;

  for (i = 0; i < n; ++i) {
    if (direct(H[k - 2], H[k - 1], P[i])) {
      while (k >= 2 && direct(H[k - 2], H[k - 1], P[i])) {
        k--;
      }
      H[k++] = P[i];
    }
  }

  for (i = n - 2; i >= 0; --i) {
    if (direct(H[k - 2], H[k - 1], P[i])) {
      while (k >= 2 && direct(H[k - 2], H[k - 1], P[i])) {
        k--;
      }
      H[k++] = P[i];
    }
  }

  printf("%d\n", k - 1);
  for (i = 0; i < k - 1; ++i) {
    printf("%d %d\n", H[i].x, H[i].y);
  }

  return 0;
}