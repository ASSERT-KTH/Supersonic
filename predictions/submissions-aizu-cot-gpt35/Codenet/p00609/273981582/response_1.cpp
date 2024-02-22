#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_set>
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

inline int square(int x) { return x * x; }

inline int dist2(const Point &a, const Point &b) {
  return square(a.x - b.x) + square(a.y - b.y);
}

int PlaneSweep() {
  int ans = 0;
  unordered_set<Point> open[2];
  REP(iter, n) {
    Event &e = event[iter];
    Point &p = e.p;
    if (e.in) {
      auto lower = open[(int)p.type ^ 1].lower_bound(Point(0, p.y - 4 * r - 1, 0));
      auto upper = open[(int)p.type ^ 1].upper_bound(Point(0, p.y + 4 * r + 1, 0));
      for (auto it = lower; it != upper; it++) {
        if (dist2(*it, p) <= 16 * r * r) {
          ans++;
        }
      }
      open[(int)p.type].insert(p);
    } else {
      open[(int)p.type].erase(p);
    }
  }
  return ans;
}

int main() {
  int an, bn, r;
  while (cin >> an >> bn >> r, an | bn) {
    int n = (an + bn) * 2;
    vector<Event> event(n);
    REP(i, an) {
      int x, y;
      cin >> x >> y;
      event[2 * i + 0] = Event(x - 2 * r, Point(x, y, 0), 1);
      event[2 * i + 1] = Event(x + 2 * r, Point(x, y, 0), 0);
    }
    REP(i, bn) {
      int x, y;
      cin >> x >> y;
      event[2 * an + 2 * i + 0] = Event(x - 2 * r, Point(x, y, 1), 1);
      event[2 * an + 2 * i + 1] = Event(x + 2 * r, Point(x, y, 1), 0);
    }
    sort(event.begin(), event.end());
    int ans = PlaneSweep();
    cout << ans << endl;
  }
}
