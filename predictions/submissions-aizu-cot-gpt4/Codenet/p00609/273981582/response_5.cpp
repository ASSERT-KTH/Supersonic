#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <set>
#include <array>
using namespace std;

using ll = long long;
constexpr double EPS = 1e-9;
constexpr double PI = acos(-1.0);

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i, s, n) for (int i = (s); i < (int)(n); ++i)
#define FOREQ(i, s, n) for (int i = (s); i <= (int)(n); ++i)
#define FORIT(it, c) for (auto it = (c).begin(); it != (c).end(); ++it)
#define MEMSET(v, h) memset((v), h, sizeof(v))

struct Point {
  int x;
  int y;
  char type;
  Point() = default;
  Point(double x, double y, int type) : x(x), y(y), type(type) { }
  bool operator<(const Point &rhs) const {
    return y != rhs.y ? y < rhs.y : x < rhs.x;
  }
};

struct Event {
  int x;
  Point p;
  char in;
  Event() = default;
  Event(int x, Point p, int in) : x(x), p(p), in(in) { }
  bool operator<(const Event &rhs) const {
    return x != rhs.x ? x < rhs.x : in > rhs.in;
  }
};

inline int square(int x) { return x * x; }

inline int dist2(const Point &a, const Point &b) {
  return square(a.x - b.x) + square(a.y - b.y);
}

int an, bn, n;
int r;
array<Event, 500000> event;

int PlaneSweep() {
  int ans = 0;
  std::set<Point> open[2];
  REP(iter, n) {
    Event &e = event[iter];
    Point &p = e.p;
    if (e.in) {
      auto lower = open[static_cast<int>(p.type) ^ 1].lower_bound(Point(0, p.y - 4 * r - 1, 0));
      auto upper = open[static_cast<int>(p.type) ^ 1].upper_bound(Point(0, p.y + 4 * r + 1, 0));
      for (auto it = lower; it != upper; ++it) {
        if (dist2(*it, p) <= 16 * r * r) {
          ++ans;
        }
      }
      open[static_cast<int>(p.type)].insert(p);
    } else {
      open[static_cast<int>(p.type)].erase(open[static_cast<int>(p.type)].find(p));
    }
  }
  return ans;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  while (std::scanf("%d %d %d", &an, &bn, &r), an | bn) {
    n = (an + bn) * 2;
    REP(i, an) {
      int x, y;
      std::scanf("%d %d", &x, &y);
      event[2 * i + 0] = Event(x - 2 * r, Point(x, y, 0), 1);
      event[2 * i + 1] = Event(x + 2 * r, Point(x, y, 0), 0);
    }
    REP(i, bn) {
      int x, y;
      std::scanf("%d %d", &x, &y);
      event[2 * an + 2 * i + 0] = Event(x - 2 * r, Point(x, y, 1), 1);
      event[2 * an + 2 * i + 1] = Event(x + 2 * r, Point(x, y, 1), 0);
    }
    std::sort(event.begin(), event.begin() + n);
    int ans = PlaneSweep();
    std::printf("%d\n", ans);
  }
  return 0;
}