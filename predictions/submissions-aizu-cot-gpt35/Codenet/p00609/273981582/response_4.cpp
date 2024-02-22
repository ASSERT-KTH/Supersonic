#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

struct Point {
  int x;
  int y;
  char type;
  Point() = default;
  Point(int x, int y, char type) : x(x), y(y), type(type) {}
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
  Event() = default;
  Event(int x, const Point &p, char in) : x(x), p(p), in(in) {}
  bool operator<(const Event &rhs) const {
    if (x != rhs.x) {
      return x < rhs.x;
    }
    return in > rhs.in;
  }
};

int dist2(const Point &a, const Point &b) {
  return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int PlaneSweep() {
  int ans = 0;
  set<Point> open[2];
  for (const Event &e : event) {
    const Point &p = e.p;
    if (e.in) {
      const auto lower = open[p.type ^ 1].lower_bound(Point(0, p.y - 4 * r - 1, 0));
      const auto upper = open[p.type ^ 1].upper_bound(Point(0, p.y + 4 * r + 1, 0));
      for (auto it = lower; it != upper; ++it) {
        if (dist2(*it, p) <= 16 * r * r) {
          ans++;
        }
      }
      open[p.type].emplace(p);
    } else {
      open[p.type].erase(open[p.type].find(p));
    }
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  
  int an, bn, r;
  while (cin >> an >> bn >> r, an | bn) {
    const int n = (an + bn) * 2;
    vector<Event> event(n);
    for (int i = 0; i < an; ++i) {
      int x, y;
      cin >> x >> y;
      event[2 * i + 0] = Event(x - 2 * r, Point(x, y, 0), 1);
      event[2 * i + 1] = Event(x + 2 * r, Point(x, y, 0), 0);
    }
    for (int i = 0; i < bn; ++i) {
      int x, y;
      cin >> x >> y;
      event[2 * an + 2 * i + 0] = Event(x - 2 * r, Point(x, y, 1), 1);
      event[2 * an + 2 * i + 1] = Event(x + 2 * r, Point(x, y, 1), 0);
    }
    stable_sort(event.begin(), event.end());
    int ans = PlaneSweep();
    cout << ans << '\n';
  }

  return 0;
}