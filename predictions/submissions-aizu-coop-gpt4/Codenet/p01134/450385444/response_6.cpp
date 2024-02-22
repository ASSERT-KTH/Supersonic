#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <iostream>
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
typedef pair<double, double> P;
typedef pair<P, P> Segment;
double dot(P a, P b) { return a.first * b.first + a.second * b.second; }
double cross(P a, P b) { return a.first * b.second - a.second * b.first; }
double norm(P p) { return p.first * p.first + p.second * p.second; }
double abs(P p) { return sqrt(norm(p)); }
int ccw(P p, P q, P r) {
  P a = {q.first - p.first, q.second - p.second};
  P b = {r.first - p.first, r.second - p.second};
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
  return (ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 &&
          ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0);
}
P crosspoint(P p1, P p2, P p3, P p4) {
  double A = cross({p2.first - p1.first, p2.second - p1.second},
                   {p4.first - p3.first, p4.second - p3.second});
  double B = cross({p2.first - p1.first, p2.second - p1.second},
                   {p2.first - p3.first, p2.second - p3.second});
  return {p3.first + (p4.first - p3.first) * (B / A),
          p3.second + (p4.second - p3.second) * (B / A)};
}
int main() {
  int n, field;
  vector<Segment> pos;
  Segment pesh;
  set<P> exist;
  P xp;
  while (cin >> n && n) {
    field = 1;
    pos.clear();
    exist.clear();
    for (int i = 0; i < n; i++) {
      cin >> pesh.F.first >> pesh.F.second >> pesh.S.first >> pesh.S.second;
      pos.push_back(pesh);
      int x_counter = 0;
      for (int i = 0; i < pos.size() - 1; i++) {
        if (isIntersect(pos[i].F, pos[i].S, pos[pos.size() - 1].F,
                        pos[pos.size() - 1].S)) {
          xp = crosspoint(pos[i].F, pos[i].S, pos[pos.size() - 1].F,
                          pos[pos.size() - 1].S);
          if (100 - fabs(xp.first) < EPS || 100 - fabs(xp.second) < EPS)
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