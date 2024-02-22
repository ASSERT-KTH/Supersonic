#include <algorithm>
#include <stack>
#include <cstdio>
using namespace std;

class Point {
public:
  int x, y;
  Point(int a = 0, int b = 0) : x(a), y(b) {}
  bool operator<(const Point &p) const { return y < p.y || (y == p.y && x < p.x); }
};

inline bool direct(Point &base, Point &a, Point &b) {
  return (long long)(a.x - base.x) * (b.y - base.y) - (long long)(a.y - base.y) * (b.x - base.x) < 0;
}

int main() {
  int n;
  scanf("%d", &n);
  vector<Point> P(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &P[i].x, &P[i].y);
  }
  sort(P.begin(), P.end());

  stack<Point> H;
  H.push(P[0]);
  H.push(P[1]);

  for (int i = 2; i < n; ++i) {
    while (H.size() >= 2) {
      Point top = H.top(); H.pop();
      Point next_top = H.top();
      if (direct(next_top, top, P[i]))
        H.push(top);
      else
        continue;
    }
    H.push(P[i]);
  }

  printf("%zu\n", H.size());
  while (!H.empty()) {
    printf("%d %d\n", H.top().x, H.top().y);
    H.pop();
  }

  return 0;
}