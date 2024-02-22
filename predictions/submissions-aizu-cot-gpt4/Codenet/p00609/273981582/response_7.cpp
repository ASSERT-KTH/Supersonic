#include <algorithm>
#include <assert.h>
#include <iostream>
#include <math.h>
#include <set>
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
typedef long long ll;
static const double EPS = 1e-9;
static const double PI = acos(-1.0);
#define REP(i, n) for (int i = 0; i < int(n); ++i)
#define FOR(i, s, n) for (int i = s; i < int(n); ++i)
#define FOREQ(i, s, n) for (int i = s; i <= int(n); ++i)
#define FORIT(it, c)                                                           \
  for (auto it = (c).begin(); it != (c).end(); ++it)
#define MEMSET(v, h) memset((v), h, sizeof(v))
struct Point {
  int x;
  int y;
  char type;
  Point() { ; }
  Point(int x, int y, int type) : x(x), y(y), type(type) { ; }
  bool operator<(const Point &rhs) const {
    if (y != rhs.y) {
      return y < rhs.y;
    }
    return x < rhs.x;
  }
};
struct Event {
  int x;
  Point p;
  char in;
  Event() { ; }
  Event(int x, Point p, int in) : x(x), p(p), in(in) { ; }
  bool operator<(const Event &rhs) const {
    if (x != rhs.x) {
      return x < rhs.x;
    }
    return in > rhs.in;
  }
};
inline int square(int x) { return x * x; }
inline int dist2(const Point &a, const Point &b) {
  return square(a.x - b.x) + square(a.y - b.y);
}
int an, bn, n;
int r;
Event event[500000];
int PlaneSweep() {
  int ans = 0;
  set<Point> open[2];
  REP(iter, n) {
    Event &e = event[iter];
    Point &p = e.p;
    if (e.in) {
      auto lower = open[p.type ^ 1].lower_bound(Point(0, p.y - 4 * r - 1, 0));
      auto upper = open[p.type ^ 1].upper_bound(Point(0, p.y + 4 * r + 1, 0));
      for (auto it = lower; it != upper; ++it) {
        if (dist2(*it, p) <= 16 * r * r) {
          ans++;
        }
      }
      open[p.type].insert(p);
    } else {
      open[p.type].erase(open[p.type].find(p));
    }
  }
  return ans;
}
int main() {
  std::ios_base::sync_with_stdio(false);
  while (scanf("%d %d %d", &an, &bn, &r), an | bn) {
    n = (an + bn) * 2;
    REP(i, an) {
      int x, y;
      scanf("%d %d", &x, &y);
      event[2 * i] = Event(x - 2 * r, Point(x, y, 0), 1);
      event[2 * i + 1] = Event(x + 2 * r, Point(x, y, 0), 0);
    }
    REP(i, bn) {
      int x, y;
      scanf("%d %d", &x, &y);
      event[2 * an + 2 * i] = Event(x - 2 * r, Point(x, y, 1), 1);
      event[2 * an + 2 * i + 1] = Event(x + 2 * r, Point(x, y, 1), 0);
    }
    sort(event, event + n);
    int ans = PlaneSweep();
    printf("%d\n", ans);
  }
}