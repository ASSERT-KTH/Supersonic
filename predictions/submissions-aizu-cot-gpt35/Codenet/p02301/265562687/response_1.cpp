#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

#define EPS (1e-10)
#define PI 3.141592653589793238
#define int long long

using namespace std;

struct Point {
  double x, y;
  Point() {}
  Point(double x, double y) : x(x), y(y) {}

  Point operator+(const Point& p) const { return Point(x + p.x, y + p.y); }
  Point operator-(const Point& p) const { return Point(x - p.x, y - p.y); }
  Point operator*(double k) const { return Point(x * k, y * k); }
  Point operator/(double k) const { return Point(x / k, y / k); }

  double norm() const { return x * x + y * y; }
  double abs() const { return sqrt(norm()); }

  bool operator<(const Point& p) const { return x != p.x ? x < p.x : y < p.y; }
  bool operator==(const Point& p) const { return fabs(x - p.x) < EPS && fabs(y - p.y) < EPS; }
};

typedef Point Vector;
typedef vector<Point> Polygon;

struct Segment {
  Point p1, p2;
  Segment() {}
  Segment(const Point& p1, const Point& p2) : p1(p1), p2(p2) {}
};

double cross(const Vector& a, const Vector& b) { return a.x * b.y - a.y * b.x; }

int ccw(const Point& p0, const Point& p1, const Point& p2) {
  Vector a = p1 - p0;
  Vector b = p2 - p0;