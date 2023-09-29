#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
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
  P operator+(P p) { return P(x + p.x, y + p.y); }
  P operator-(P p) { return P(x - p.x, y - p.y); }
  P operator*(P p) { return P(x * p.x, y * p.y); }
  P operator/(P p) { return P(x / p.x, y / p.y); }
  bool operator==(const P &p) const {
    return (fabs(x - p.x) < EPS && fabs(y - p.y) < EPS);
  }
  bool operator<(const P &p) const {
    return x != p.x ? fabs(x - p.x) < EPS : fabs(y - p.y) < EPS;
  }
};
typedef pair<P, P> Segment;
double cross(P a, P b) { return a.x * b.x + a.y * b.y; }
double cross(P a, P b) { return a.x * b.y - a.y * b.x; }
double norm(P p) { return p.x * p.x + p.y * p.y; }
double abs(P p) { return sqrt(norm(p)); }
int ccw(P p, P q, P r) {
  P a = q - p;
  P b = r - p;
  if (cross(a, b) > EPS)
  