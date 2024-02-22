#include <algorithm>
#include <assert.h>
#include <iostream>
#include <math.h>
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
#define FORIT(it, c)                                                           \
  for (__typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)
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

// Pre-compute squares of all possible coordinates
const int MAX_COORD = 10000; // assuming maximum coordinate value is 10000
int squares[MAX_COORD + 1];
void preComputeSquares() {
  for(int i = 0; i <= MAX_COORD; i++) {
    squares[i] = i * i;
  }
}

inline int dist2(const Point &a, const Point &b) {
  return squares[abs(a.x - b.x)] + squares[abs(a.y - b.y)];
}

int an, bn, n;
int r;
Event event[500000];
int PlaneSweep() {
  int ans = 0;
  set<Point> open[2];
  REP(iter, n) {
    Event &e = event[iter];
    Point &p = e.p;
    if (e.in) {
      set<Point>::iterator lower =
          open[(int)p.type ^ 1].lower_bound(Point(0, p.y - 4 * r - 1, 0));
      set<Point>::iterator upper =
          open[(int)p.type ^ 1].upper_bound(Point(0, p.y + 4 * r + 1, 0));
      for (set<Point>::iterator it = lower; it != upper; it++) {
        if (dist2(*it, p) <= 16 * r * r) {
          ans++;
        }
      }
      open[(int)p.type].insert(p);
    } else {
      open[(int)p.type].erase(open[(int)p.type].find(p));
    }
  }
  return ans;
}

int main() {
  preComputeSquares();
  while (scanf("%d %d %d", &an, &bn, &r), an | bn) {
    // rest of the code remains same
  }
}