#include <algorithm>
#include <assert.h>
#include <iostream>
#include <math.h>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
typedef long long ll;
static const double EPS = 1e-9;
static const double PI = acos(-1.0);

#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, n) for (int i = (s); i < (int)(n); i++)
#define FOREQ(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define FORIT(it, c) for (__typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)
#define MEMSET(v, h) memset((v), h, sizeof(v))

struct Point {
  int x;
  int y;
  char type;
  Point() { ; }
  Point(double x, double y, int type) : x(x), y(y), type(type) { ; }
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

unordered_map<pair<Point, Point>, int> dist2_map; // to store results of dist2() function

inline int square(int x) { return x * x; }

// modified dist2() function
inline int dist2(const Point &a, const Point &b) {
  if (dist2_map.count({a, b}) == 0) {
    dist2_map[{a, b}] = square(a.x - b.x) + square(a.y - b.y);
  }
  return dist2_map[{a, b}];
}

int an, bn, n;
int r;
Event event[500000];

// modified PlaneSweep() function
int PlaneSweep() {
  int ans = 0;
  set<Point> openSet[2];
  unordered_map<Point, set<Point>::iterator> openMap[2]; // additional unordered_map
  REP(iter, n) {
    Event &e = event[iter];
    Point &p = e.p;
    if (e.in) {
      set<Point>::iterator lower =
          openSet[(int)p.type ^ 1].lower_bound(Point(0, p.y - 4 * r - 1, 0));
      set<Point>::iterator upper =
          openSet[(int)p.type ^ 1].upper_bound(Point(0, p.y + 4 * r + 1, 0));
      for (set<Point>::iterator it = lower; it != upper; it++) {
        if (dist2(*it, p) <= 16 * r * r) {
          ans++;
        }
      }
      auto insertResult = openSet[(int)p.type].insert(p);
      openMap[(int)p.type][p] = insertResult.first;
    } else {
      openSet[(int)p.type].erase(openMap[(int)p.type][p]);
      openMap[(int)p.type].erase(p);
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
      event[2 * i + 0] = Event(x - 2 * r, Point(x, y, 0), 1);
      event[2 * i + 1] = Event(x + 2 * r, Point(x, y, 0), 0);
    }
    REP(i, bn) {
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