#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

struct Point {
  int x;
  int y;
  char type;
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
  bool operator<(const Event &rhs) const {
    if (x != rhs.x) {
      return x < rhs.x;
    }
    return in > rhs.in;
  }
};

inline int dist2(const Point &a, const Point &b) {
  return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int an, bn, n;
int r;
Event event[500000];

int PlaneSweep() {
  int ans = 0;
  vector<Point> open[2];
  for (int iter = 0; iter < n; iter++) {
    Event &e = event[iter];
    Point &p = e.p;
    if (e.in) {
      auto lower = lower_bound(open[(int)p.type ^ 1].begin(), open[(int)p.type ^ 1].end(), Point(0, p.y - 4 * r - 1, 0));
      auto upper = upper_bound(open[(int)p.type ^ 1].begin(), open[(int)p.type ^ 1].end(), Point(0, p.y + 4 * r + 1, 0));
      for (auto it = lower; it != upper; it++) {
        if (dist2(*it, p) <= 16 * r * r) {
          ans++;
        }
      }
      open[(int)p.type].push_back(p);
    } else {
      for (auto it = open[(int)p.type].begin(); it != open[(int)p.type].end(); it++) {
        if (it->x == p.x && it->y == p.y) {
          open[(int)p.type].erase(it);
          break;
        }
      }
    }
  }
  return ans;
}

int main() {
  while (scanf("%d %d %d", &an, &bn, &r), an | bn) {
    n = (an + bn) * 2;
    for (int i = 0; i < an; i++) {
      int x, y;
      scanf("%d %d", &x, &y);
      event[2 * i + 0] = {x - 2 * r, {x, y, 0}, 1};
      event[2 * i + 1] = {x + 2 * r, {x, y, 0}, 0};
    }
    for (int i = 0; i < bn; i++) {
      int x, y;
      scanf("%d %d", &x, &y);
      event[2 * an + 2 * i + 0] = {x - 2 * r, {x, y, 1}, 1};
      event[2 * an + 2 * i + 1] = {x + 2 * r, {x, y, 1}, 0};
    }
    sort(event, event + n);
    int ans = PlaneSweep();
    printf("%d\n", ans);
  }
}