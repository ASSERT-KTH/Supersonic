#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
#define EPS 1e-10
#define COUNTER_CLOCKWISE 1
#define CLOCKWISE -1
#define ONLINE_BACK 2
#define ONLINE_FRONT -2
#define ON_SEGMENT 0

struct P {
  double x, y;
  P(double x = 0, double y = 0) : x(x), y(y) {}
  P operator+(P p) { return P(x + p.x, y + p.y); }
  P operator-(P p) { return P(x - p.x, y - p.y); }
  P operator*(P p) { return P(x * p.x, y * p.y); }
  P operator/(P p) { return P(x / p.x, y / p.y); }
  bool operator==(const P &p) const {
    return (fabs(x - p.x) < EPS && fabs(y - p.y) < EPS);
  }
  bool operator<(const P &p) const {
    double xDiff = fabs(x - p.x);
    double yDiff = fabs(y - p.y);
    return x != p.x ? xDiff < EPS : yDiff < EPS;
  }
};

struct Segment {
  P p1, p2;
};

double dot(P a, P b) { return a.x * b.x + a.y * b.y; }
double cross(P a, P b) { return a.x * b.y - a.y * b.x; }
double norm(P p) { return p.x * p.x + p.y * p.y; }
double abs(P p) { return sqrt(norm(p)); }

int ccw(P p, P q, P r) {
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

bool isIntersect(P p1, P p2, P p3, P p4) {
  int ccw1 = ccw(p1, p2, p3);
  int ccw2 = ccw(p1, p2, p4);
  int ccw3 = ccw(p3, p4, p1);
  int ccw4 = ccw(p3, p4, p2);
  return (ccw1 * ccw2 <= 0 && ccw3 * ccw4 <= 0);
}

P crosspoint(P p1, P p2, P p3, P p4) {
  double A = cross(p2 - p1, p4 - p3);
  double B = cross(p2 - p1, p2 - p3);
  P pro = p4 - p3;
  pro.x = pro.x * (B / A);
  pro.y = pro.y * (B / A);
  return p3 + pro;
}

int main() {
  int n, xx, yy, xxx, yyy, field;
  vector<Segment> pos;
  Segment pesh;
  vector<P> exist;
  P xp;
  while (cin >> n && n) {
    field = 1;
    pos.clear();
    pos.reserve(n);
    for (int i = 0; i < n; i++) {
      cin >> xx >> yy >> xxx >> yyy;
      pesh.p1.x = xx;
      pesh.p1.y = yy;
      pesh.p2.x = xxx;
      pesh.p2.y = yyy;
      pos.push_back(pesh);
      int x_counter = 0;
      bool new_x = true;
      exist.clear();
      exist.reserve(pos.size());
      for (int i = 0; i < pos.size() - 1; i++) {
        new_x = true;
        if (isIntersect(pos[i].p1, pos[i].p2, pos[pos.size() - 1].p1,
                        pos[pos.size() - 1].p2)) {
          xp = crosspoint(pos[i].p1, pos[i].p2, pos[pos.size() - 1].p1,
                          pos[pos.size() - 1].p2);
          if (100 - fabs(xp.x) < EPS || 100 - fabs(xp.y) < EPS)
            continue;
          for (const auto &e : exist) {
            if (e == xp) {
              new_x = false;
              break;
            }
          }
          if (new_x) {
            x_counter++;
            exist.push_back(xp);
          }
        }
      }
      field += x_counter + 1;
    }
    cout << field << endl;
  }
  return 0;
}