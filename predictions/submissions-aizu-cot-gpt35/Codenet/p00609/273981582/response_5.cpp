#include <algorithm>
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <unordered_set>

using namespace std;

using ll = long long;
static const double EPS = 1e-9;
static const double PI = acos(-1.0);

struct Point {
  int x;
  int y;
  char type;

  Point() {}
  Point(int x, int y, int type) : x(x), y(y), type(type) {}
  
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

  Event() {}
  Event(int x, Point p, int in) : x(x), p(p), in(in) {}
  
  bool operator<(const Event &rhs) const {
    if (x != rhs.x) {
      return x < rhs.x;
    }
    return in > rhs.in;
  }
};

inline int square(int x) {
  return x * x;
}

inline int dist2(const Point &a, const Point &b) {
  return square(a.x - b.x) + square(a.y - b.y);
}

size_t an, bn, n;
int r;
Event event[500000];

int PlaneSweep() {
  int ans = 0;
  unordered_set<Point> open[2];

  for (size_t iter = 0; iter < n; ++iter) {
    Event &e = event[iter];
    Point &p = e.p;

    if (e.in) {
      auto lower = open[(size_t)p.type ^ 1].lower_bound(Point(0, p.y - 4 * r - 1, 0));
      auto upper = open[(size_t)p.type ^ 1].upper_bound(Point(0, p.y + 4 * r + 1, 0));

      for (auto it = lower; it != upper; ++it) {
        if (dist2(*it, p) <= 16 * r * r) {
          ++ans;
        }
      }

      open[(size_t)p.type].insert(p);
    } else {
      open[(size_t)p.type].erase(open[(size_t)p.type].find(p));
    }
  }

  return ans;
}

int main() {
  while (scanf("%zu %zu %d", &an, &bn, &r), an | bn) {
    n = (an + bn) * 2;

    for (size_t i = 0; i < an; ++i) {
      int x, y;
      scanf("%d %d", &x, &y);
      event[2 * i + 0] = Event(x - 2 * r, Point(x, y, 0), 1);
      event[2 * i + 1] = Event(x + 2 * r, Point(x, y, 0), 0);
    }

    for (size_t i = 0; i < bn; ++i) {
      int x, y;
      scanf("%d %d", &x, &y);
      event[2 * an + 2 * i + 0] = Event(x - 2 * r, Point(x, y, 1), 1);
      event[2 * an + 2 * i + 1] = Event(x + 2 * r, Point(x, y, 1), 0);
    }

    sort(event, event + n);
    int ans = PlaneSweep();
    printf("%d\n", ans);
  }
}