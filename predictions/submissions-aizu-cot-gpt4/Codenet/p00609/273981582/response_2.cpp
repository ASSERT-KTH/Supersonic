#include <algorithm>
#include <assert.h>
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
typedef long long ll;
static const double EPS = 1e-9;
static const double PI = acos(-1.0);
#define REP(i, n) for (int i = 0; i < n; ++i)
#define FOR(i, s, n) for (int i = s; i < n; ++i)
#define FOREQ(i, s, n) for (int i = s; i <= n; ++i)
#define FORIT(it, c) for (auto it = c.begin(); it != c.end(); ++it)
struct Point {
  int x, y;
  char type;
};
struct Event {
  int x;
  Point p;
  char in;
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
  vector<Point> open[2];
  REP(iter, n) {
    Event &e = event[iter];
    Point &p = e.p;
    if (e.in) {
      auto lower = lower_bound(open[p.type ^ 1].begin(), open[p.type ^ 1].end(), Point{0, p.y - 4 * r - 1, 0});
      auto upper = upper_bound(open[p.type ^ 1].begin(), open[p.type ^ 1].end(), Point{0, p.y + 4 * r + 1, 0});
      for (auto it = lower; it != upper; ++it) {
        if (dist2(*it, p) <= 16 * r * r) {
          ans++;
        }
      }
      open[p.type].push_back(p);
      sort(open[p.type].begin(), open[p.type].end());
    } else {
      auto it = find(open[p.type].begin(), open[p.type].end(), p);
      if (it != open[p.type].end()) open[p.type].erase(it);
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
      event[2 * i] = {x - 2 * r, {x, y, 0}, 1};
      event[2 * i + 1] = {x + 2 * r, {x, y, 0}, 0};
    }
    REP(i, bn) {
      int x, y;
      scanf("%d %d", &x, &y);
      event[2 * an + 2 * i] = {x - 2 * r, {x, y, 1}, 1};
      event[2 * an + 2 * i + 1] = {x + 2 * r, {x, y, 1}, 0};
    }
    sort(event, event + n);
    int ans = PlaneSweep();
    printf("%d\n", ans);
  }
}