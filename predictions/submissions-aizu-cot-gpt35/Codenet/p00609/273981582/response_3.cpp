#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

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

int dist2(const Point &a, const Point &b) {
  int dx = a.x - b.x;
  int dy = a.y - b.y;
  return dx * dx + dy * dy;
}

int PlaneSweep() {
  int ans = 0;
  std::vector<Point> open[2];
  for (const Event& e : event) {
    Point &p = e.p;
    if (e.in) {
      for (const Point& other : open[(int)p.type ^ 1]) {
        if (dist2(other, p) <= 16 * r * r) {
          ans++;
        }
      }
      open[(int)p.type].push_back(p);
    } else {
      open[(int)p.type].erase(std::find(open[(int)p.type].begin(), open[(int)p.type].end(), p));
    }
  }
  return ans;
}

int main() {
  int an, bn, r;
  while (std::cin >> an >> bn >> r, an | bn) {
    int n = (an + bn) * 2;
    std::vector<Event> event(n);
    for (int i = 0; i < an; i++) {
      int x, y;
      std::cin >> x >> y;
      event[2 * i] = Event(x - 2 * r, Point(x, y, 0), 1);
      event[2 * i + 1] = Event(x + 2 * r, Point(x, y, 0), 0);
    }
    for (int i = 0; i < bn; i++) {
      int x, y;
      std::cin >> x >> y;
      event[2 * an + 2 * i] = Event(x - 2 * r, Point(x, y, 1), 1);
      event[2 * an + 2 * i + 1] = Event(x + 2 * r, Point(x, y, 1), 0);
    }
    std::sort(event.begin(), event.end());
    int ans = PlaneSweep();
    std::cout << ans << std::endl;
  }
}