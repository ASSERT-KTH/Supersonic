#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Point {
  int x;
  int y;
  bool type;

  bool operator<(const Point& rhs) const {
    if (y != rhs.y) {
      return y < rhs.y;
    }
    return x < rhs.x;
  }
};

struct Event {
  int x;
  Point p;
  bool in;

  bool operator<(const Event& rhs) const {
    if (x != rhs.x) {
      return x < rhs.x;
    }
    return in > rhs.in;
  }
};

inline int dist2(const Point& a, const Point& b) {
  return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int PlaneSweep(const vector<Event>& events) {
  int ans = 0;
  vector<Point> open[2];

  for (const Event& e : events) {
    const Point& p = e.p;

    if (e.in) {
      auto lower = lower_bound(open[1 - p.type].begin(), open[1 - p.type].end(), Point(0, p.y - 4 * r - 1, 0));
      auto upper = upper_bound(open[1 - p.type].begin(), open[1 - p.type].end(), Point(0, p.y + 4 * r + 1, 0));

      for (auto it = lower; it != upper; it++) {
        if (dist2(*it, p) <= 16 * r * r) {
          ans++;
        }
      }

      open[p.type].push_back(p);
    } else {
      auto it = find(open[p.type].begin(), open[p.type].end(), p);
      open[p.type].erase(it);
    }
  }

  return ans;
}

int main() {
  int an, bn, r;

  while (cin >> an >> bn >> r, an | bn) {
    vector<Event> events((an + bn) * 2);

    for (int i = 0; i < an; i++) {
      int x, y;
      cin >> x >> y;
      events[2 * i + 0] = Event(x - 2 * r, Point(x, y, false), true);
      events[2 * i + 1] = Event(x + 2 * r, Point(x, y, false), false);
    }

    for (int i = 0; i < bn; i++) {
      int x, y;
      cin >> x >> y;
      events[2 * an + 2 * i + 0] = Event(x - 2 * r, Point(x, y, true), true);
      events[2 * an + 2 * i + 1] = Event(x + 2 * r, Point(x, y, true), false);
    }

    sort(events.begin(), events.end());

    int ans = PlaneSweep(events);
    cout << ans << endl;
  }

  return 0;
}