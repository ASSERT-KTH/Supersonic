#include <algorithm>
#include <array>
#include <cstdio>
#include <cmath>
#include <set>
#include <cstdint>

struct Point {
  int x;
  int y;
  int type;
  Point() = default;
  Point(int x, int y, int type) : x(x), y(y), type(type) {}
  bool operator<(const Point& rhs) const {
    return std::tie(y, x) < std::tie(rhs.y, rhs.x);
  }
};

struct Event {
  int x;
  Point p;
  bool in;
  Event() = default;
  Event(int x, Point p, bool in) : x(x), p(p), in(in) {}
  bool operator<(const Event& rhs) const {
    return std::tie(x, in) < std::tie(rhs.x, rhs.in);
  }
};

constexpr int64_t square(int x) {
  return static_cast<int64_t>(x) * x;
}

constexpr int64_t dist2(const Point& a, const Point& b) {
  return square(a.x - b.x) + square(a.y - b.y);
}

int PlaneSweep(const std::array<Event, 500000>& events, int n, int r) {
  int ans = 0;
  std::set<Point> open[2];
  for (int iter = 0; iter < n; iter++) {
    const Event& e = events[iter];
    const Point& p = e.p;
    if (e.in) {
      auto lower = open[p.type ^ 1].lower_bound(Point(0, p.y - 4 * r - 1, 0));
      auto upper = open[p.type ^ 1].upper_bound(Point(0, p.y + 4 * r + 1, 0));
      for (const auto& it : std::range(lower, upper)) {
        if (dist2(it, p) <= 16 * r * r) {
          ans++;
        }
      }
      open[p.type].insert(p);
    } else {
      open[p.type].erase(p);
    }
  }
  return ans;
}

int main() {
  int an, bn, r;
  while (scanf("%d %d %d", &an, &bn, &r) == 3 && (an && bn)) {
    int n = (an + bn) * 2;
    std::array<Event, 500000> events;
    for (int i = 0; i < an; i++) {
      int x, y;
      scanf("%d %d", &x, &y);
      events[2 * i + 0] = Event(x - 2 * r, Point(x, y, 0), true);
      events[2 * i + 1] = Event(x + 2 * r, Point(x, y, 0), false);
    }
    for (int i = 0; i < bn; i++) {
      int x, y;
      scanf("%d %d", &x, &y);
      events[2 * an + 2 * i + 0] = Event(x - 2 * r, Point(x, y, 1), true);
      events[2 * an + 2 * i + 1] = Event(x + 2 * r, Point(x, y, 1), false);
    }
    std::sort(events.begin(), events.begin() + n);
    int ans = PlaneSweep(events, n, r);
    printf("%d\n", ans);
  }
}