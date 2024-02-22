#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>

#define EPS (1e-10)

using namespace std;

struct Point {
  double x, y;
  Point() {}
  Point(double x, double y) : x(x), y(y) {}
};

bool operator<(const Point &p1, const Point &p2) {
  return p1.x != p2.x ? p1.x < p2.x : p1.y < p2.y;
}

istream &operator>>(istream &is, Point &p) {
  is >> p.x >> p.y;
  return is;
}

ostream &operator<<(ostream &os, const Point &p) {
  os << fixed << setprecision(12) << p.x << " " << p.y;
  return os;
}

double cross(const Point &a, const Point &b) {
  return a.x * b.y - a.y * b.x;
}

double distance(const Point &p1, const Point &p2) {
  return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

double diameter(const vector<Point> &p) {
  int n = p.size();
  if (n == 2)
    return distance(p[0], p[1]);
  
  int i = 0, j = 0;
  for (int k = 0; k < n; k++) {
    if (p[i] < p[k])
      i = k;
    if (!(p[j] < p[k]))
      j = k;
  }
  
  double res = 0;
  int si = i, sj = j;
  