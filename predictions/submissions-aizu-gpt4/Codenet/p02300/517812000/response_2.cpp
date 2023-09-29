#include <algorithm>
#include <cstdio>
using namespace std;

struct Point {
  int x, y;

  bool operator<(const Point &p) const {
    return y < p.y || (y == p.y && x < p.x);
  }
};

inline bool direct(const Point &base, const Point &a, const Point &b) {
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
  for (int phase = 0; phase < 2; ++phase) {
    int start = k;
    for (int i = 0; i < n; ++i) {
      while (k > start + 1 && direct(H[k - 2], H[k - 1], P[i]))
        k--;
      H[k++] = P[i];
    }
    k--;
    reverse(P, P + n);
  }
  
  printf("%d\n", k);
  for (int i = 0; i < k; ++i) {
    printf("%d %d\n", H[i].x, H[i].y);
  }
  
  return 0;
}