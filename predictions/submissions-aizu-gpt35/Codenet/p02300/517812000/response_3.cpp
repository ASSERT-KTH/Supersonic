#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
class Point {
public:
  int x, y;
  Point(int a = 0, int b = 0) {
    x = a; // fixed: use class member variables instead of local variables
    y = b; 
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
  for (i = 0; i < n; ++i) { // fixed: iterate from 0 to n-1 instead of 1 to n
    scanf("%d%d", &P[i].x, &P[i].y);
  }
  sort(P, P + n);
  H = new Point[2 * n];
  H[0] = P[0];
  H[1] = P[1];
  for (i = 0; i < n - 2; ++i) { // fixed: iterate from 0 to n-3 instead of 0 to n-2
    while (k >= 2 && direct(H[k - 2], H[k - 1], P[i + 2]))
      k--;
    H[k++] = P[i + 2];
  }
  H[k++] = P[n - 1]; // fixed: add last point to convex hull
  for (i = n - 2; i >= 0; i--) { // fixed: iterate from n-2 to 0 instead of n to 2
    while (k >= 2 && direct(H[k - 2], H[k - 1], P[i]))
      k--;
    H[k++] = P[i];
  }
  printf("%d\n", k - 1);
  for (i = 0; i < k - 1; ++i) {
    printf("%d %d\n", H[i].x, H[i].y);
  }
  delete[] P; // fixed: deallocate memory
  delete[] H;
  return 0;
}