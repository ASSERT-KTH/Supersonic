#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
#include <set>

#define EPS 1e-10
#define F first
#define S second
#define COUNTER_CLOCKWISE 1
#define CLOCKWISE -1
#define ONLINE_BACK 2
#define ONLINE_FRONT -2
#define ON_SEGMENT 0

using namespace std;

struct P {
  double x, y;
  P(double x = 0, double y = 0) : x(x), y(y) {}
  P operator+(const P &p) const { return P(x + p.x, y + p.y); }
  P operator-(const P &p) const { return P(x - p.x, y - p.y); }
  bool operator<(const P &p) const {
    return x != p.x ? x < p.x : y < p.y;
  }
};

typedef pair<P, P> Segment;

double cross(const P &a, const P &b) { return a.x * b.y - a.y * b.x; }
double norm(const P &p) { return p.x * p.x + p.y * p.y; }
double dot(const P &a, const P &b) { return a.x * b.x + a.y * b.y; }

int ccw(const P &p, const P &q, const P &r) {
  P a = q - p;
  P b = r - p;
  if (cross(a, b) > EPS)
    return COUNTER_CLOCKWISE;
  if (cross(a, b) < -EPS)
    return CLOCKWISE;
  if (dot(a, b) < -EPS)
    return ONLINE_BACK;
  if (norm(a) < norm(b))
    return ONLINE_FRONT;
  return ON_SEGMENT;
}

bool isIntersect(const P &p1, const P &p2, const P &p3, const P &p4) {
  return (ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 &&
          ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0);
}

P crosspoint(const P &p1, const P &p2, const P &p3, const P &p4) {
  double A = cross(p2 - p1, p4 - p3);
  double B = cross(p2 - p1, p2 - p3) / A;
  return P(p3.x + (p4.x - p3.x) * B, p3.y + (p4.y - p3.y) * B);
}

int main() {
  int n;
  vector<Segment> pos;
  Segment pesh;

  while (cin >> n && n) {
    int field = 1;
    pos.clear();
    for (int i = 0; i < n; i++) {
      cin >> pesh.F.x >> pesh.F.y >> pesh.S.x >> pesh.S.y;
      pos.push_back(pesh);
      set<P> exist;
      int x_counter = 0;
      for (int j = 0; j < pos.size() - 1; j++) {
        if (isIntersect(pos[j].F, pos[j].S, pos[pos.size() - 1].F,
                        pos[pos.size() - 1].S)) {
          P xp = crosspoint(pos[j].F, pos[j].S, pos[pos.size() - 1].F,
                          pos[pos.size() - 1].S);
          if (100 - fabs(xp.x) < EPS || 100 - fabs(xp.y) < EPS)
            continue;
          if (exist.insert(xp).second) {
            x_counter++;
          }
        }
      }
      field += x_counter + 1;
    }
    cout << field << endl;
  }
  return 0;
}