#include <algorithm>
#include <assert.h>
#include <stdio.h>
#include <set>
#include <array>
using namespace std;
typedef long long ll;
static const double EPS = 1e-9;
static const double PI = acos(-1.0);
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, n) for (int i = (s); i < (int)(n); i++)
#define FOREQ(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define FORIT(it, c) for (auto it = (c).begin(); it != (c).end(); it++)
struct Point {
  int x;
  int y;
  char type;
  Point() { ; }
  Point(double x, double y, int type) : x(x), y(y), type(type) { ; }
  bool operator<(const Point &rhs) const {
    if (y != rhs.y) {
      return y < rhs.y;
    }
    return x < rhs.x;
  }
};
inline int square(int x) { return x * x; }
inline int dist2(const Point &a, const Point &b) {
  return square(a.x - b.x) + square(a.y - b.y);
}
int an, bn, n;
int r;
array<pair<int, Point>, 500000> event;
int PlaneSweep() {
  int ans = 0;
  array<set<Point>, 2> open;
  REP(iter, n) {
    auto &e = event[iter];
    Point &p = e.second;
    if (e.first) {
      auto lower = open[p.type ^ 1].lower_bound(Point(0, p.y - 4 * r - 1, 0));
      auto upper = open[p.type ^ 1].upper_bound(Point(0, p.y + 4 * r + 1, 0));
      for (auto it = lower; it != upper; it++) {
        if (dist2(*it, p) <= 16 * r * r) {
          ans++;
        }
      }
      open[p.type].emplace(p);
    } else {
      open[p.type].erase(p);
    }
  }
  return ans;
}
int main() {
  while (scanf("%d %d %d", &an, &bn, &r), an | bn) {
    n = (an + bn) * 2;
    REP(i, an) {
      int x, y;
      scanf("%d %d", &x, &y);
      event[2 * i + 0] = make_pair(x - 2 * r, Point(x, y, 0));
      event[2 * i + 1] = make_pair(x + 2 * r, Point(x, y, 0));
    }
    REP(i, bn) {
      int x, y;
      scanf("%d %d", &x, &y);
      event[2 * an + 2 * i + 0] = make_pair(x - 2 * r, Point(x, y, 1));
      event[2 * an + 2 * i + 1] = make_pair(x + 2 * r, Point(x, y, 1));
    }
    sort(event.begin(), event.begin() + n);
    int ans = PlaneSweep();
    printf("%d\n", ans);
  }
}