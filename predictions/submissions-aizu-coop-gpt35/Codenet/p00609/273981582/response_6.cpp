#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

struct Point {
  int x;
  int y;
  char type;

  Point() { ; }

  Point(int x, int y, int type) : x(x), y(y), type(type) { ; }

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

  Event() { ; }

  Event(int x, Point p, bool in) : x(x), p(p), in(in) { ; }

  bool operator<(const Event& rhs) const {
    if (x != rhs.x) {
      return x < rhs.x;
    }
    return in > rhs.in;
  }
};

int dist2(const Point& a, const Point& b) {
  return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int PlaneSweep() {
  int ans = 0;
  vector<Point> open[2];
  for (int iter = 0; iter < n; iter++) {
    Event& e = event[iter];
    Point& p = e.p;
    if (e.in) {
      int type = p.type ^ 1;
      int lowerIndex = -1, upperIndex = -1;
      for (int i = 0; i < open[type].size(); i++) {
        if (open[type][i].y >= p.y - 4 * r - 1) {
          lowerIndex = i;
          break;
        }
      }
      for (int i = open[type].size() - 1; i >= 0; i--) {
        if (open[type][i].y <= p.y + 4 * r + 1) {
          upperIndex = i;
          break;
        }
      }
      for (int i = lowerIndex; i <= upperIndex; i++) {
        if (dist2(open[type][i], p) <= 16 * r * r) {
          ans++;
        }
      }
      open[p.type].push_back(p);
    } else {
      vector<Point>& vec = open[p.type];
      for (int i = 0; i < vec.size(); i++) {
        if (vec[i].x == p.x && vec[i].y == p.y) {
          vec.erase(vec.begin() + i);
          break;
        }
      }
    }
  }
  return ans;
}

int main() {
  int an, bn, r;
  while (scanf("%d %d %d", &an, &bn, &r) && (an || bn)) {
    int n = (an + bn) * 2;
    vector<Event> event(n);
    for (int i = 0; i < an; i++) {
      int x, y;
      scanf("%d %d", &x, &y);
      event[2 * i + 0] = Event(x - 2 * r, Point(x, y, 0), true);
      event[2 * i + 1] = Event(x + 2 * r, Point(x, y, 0), false);
    }
    for (int i = 0; i < bn; i++) {
      int x, y;
      scanf("%d %d", &x, &y);
      event[2 * an + 2 * i + 0] = Event(x - 2 * r, Point(x, y, 1), true);
      event[2 * an + 2 * i + 1] = Event(x + 2 * r, Point(x, y, 1), false);
    }
    sort(event.begin(), event.end());
    int ans = PlaneSweep();
    printf("%d\n", ans);
  }
  return 0;
}