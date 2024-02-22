#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

class Point {
public:
  int x, y;

  Point(int a = 0, int b = 0) : x(a), y(b) {};

  bool operator<(const Point &p) const {
    return y < p.y || (y == p.y && x < p.x);
  }
};

inline bool direct(Point &base, Point &a, Point &b) {
  return (a.x - base.x) * (b.y - base.y) - (a.y - base.y) * (b.x - base.x) < 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  
  int n;
  int k = 2;
  Point *P;
  Point *H;
  
  scanf("%d", &n);
  P = new Point[n];
  
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d", &P[i - 1].x, &P[i - 1].y);
  }
  
  sort(P, P + n);
  H = new Point[2 * n];
  H[0] = P[0];
  H[1] = P[1];
  
  for (int i = 0; i < n - 2; ++i) {
    while (k >= 2 && direct(H[k - 2], H[k - 1], P[i + 2]))
      k--;
    H[k++] = P[i + 2];
  }
  
  H[k++] = P[n - 2];
  
  for (int i = n; i > 2; i--) {
    while (k >= 2 && direct(H[k - 2], H[k - 1], P[i - 3]))
      k--;
    H[k++] = P[i - 3];
  }
  
  printf("%d\n", k - 1);
  
  for (int i = 0; i < k - 1; ++i) {
    printf("%d %d\n", H[i].x, H[i].y);
  }

  delete[] P;
  delete[] H;
  
  return 0;
}