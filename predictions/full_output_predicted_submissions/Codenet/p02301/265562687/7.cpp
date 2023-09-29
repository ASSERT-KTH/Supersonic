#include <bits/stdc++.h>
#define EPS (1e-10)
#define equals(a, b) (fabs((a) - (b)) < EPS)
#define PI 3.141592653589793238
using namespace std;
static const int COUNTER_CLOCKWISE = 1;
static const int CLOCKWISE = -1;
static const int ONLINE_BACK = 2;
static const int ONLINE_FRONT = -2;
static const int ON_SEGMENT = 0;
struct Point {
  double x, y;
  Point() {}
  Point(double x, double y) : x(x), y(y) {}
  Point operator+(Point p) { return Point(x + p.x, y + p.y); }
  Point operator-(Point p) { return Point(x - p.x, y - p.y); }
  Point operator*(double k) { return Point(x * k, y * k); }
  Point operator/(double k) { return Point(x / k, y / k); }
  double norm() { return x * x + y * y; }
  double abs() { return sqrt(norm()); }
  bool operator<(const Point &p) const { return x != p.x ? x < p.x : y < p.y; }
  bool operator==(const Point &p) const {
    return fabs(x - p.x) < EPS && fabs(y - p.y) < EPS;
  }
};
istream &operator>>(istream &is, Point &p) {
  is >> p.x >> p.y;
  return is;
}
ostream &operator<<(ostream &os, Point p) {
  os << fixed << setprecision(12) << p.x << " " << p.y;
  return os;
}
typedef Point Vector;
typedef vector<Point> Polygon;
struct Segment {
  Point p1, p2;
  Segment() {}
  Segment(Point p1, Point p2) : p1(p1), p2(p1), p2