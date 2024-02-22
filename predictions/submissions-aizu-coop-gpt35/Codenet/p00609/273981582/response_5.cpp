#include <iostream>
#include <vector>
#include <algorithm>

struct Point {
  int x;
  int y;
  char type;
};

struct Event {
  int x;
  Point p;
  char in;
};

constexpr int square(int x) {
  return x * x;
}

constexpr int dist2(const Point& a, const Point& b) {
  return square(a.x - b.x) + square(a.y - b.y);
}

int PlaneSweep(const std::vector<Event>& events, int n, int r) {
  int ans = 0;
  std::vector<Point> open[2];
  for (const Event& e : events) {
    const Point& p = e.p;
    if (e.in) {
      auto lower = std::lower_bound(open[(int)p.type ^ 1].begin(), open[(int)p.type ^ 1].end(), Point{0, p.y - 4 * r - 1, 0});
      auto upper = std::upper_bound(open[(int)p.type ^ 1].begin(), open[(int)p.type ^ 1].end(), Point{0, p.y + 4 * r + 1, 0});
      for (auto it = lower; it != upper; ++it) {
        if (dist2(*it, p) <= 16 * r * r) {
          ans++;
        }
      }
      open[(int)p.type].push_back(p);
    } else {
      auto it = std::find(open[(int)p.type].begin(), open[(int)p.type].end(), p);
      if (it != open[(int)p.type].end()) {
        open[(int)p.type].erase(it);
      }
    }
  }
  return ans;
}

int main() {
  int an, bn, r;
  while (std::cin >> an >> bn >> r, an | bn) {
    int n = (an + bn) * 2;
    std::vector<Event> events(n);
    for (int i = 0; i < an; ++i) {
      int x, y;
      std::cin >> x >> y;
      events[2 * i + 0] = {x - 2 * r, {x, y, 0}, 1};
      events[2 * i + 1] = {x + 2 * r, {x, y, 0}, 0};
    }
    for (int i = 0; i < bn; ++i) {
      int x, y;
      std::cin >> x >> y;
      events[2 * an + 2 * i + 0] = {x - 2 * r, {x, y, 1}, 1};
      events[2 * an + 2 * i + 1] = {x + 2 * r, {x, y, 1}, 0};
    }
    std::sort(events.begin(), events.end(), [](const Event& a, const Event& b) {
      if (a.x != b.x) {
        return a.x < b.x;
      }
      return a.in > b.in;
    });
    int ans = PlaneSweep(events, n, r);
    std::cout << ans << '\n';
  }
  return 0;
}