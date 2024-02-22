#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>

#define EPS (1e-10)
#define equals(a, b) (fabs((a) - (b)) < EPS)
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
  bool operator==(const Point& p) const {
    return fabs(x - p.x) < EPS && fabs(y - p.y) < EPS;
  }
};

istream& operator>>(istream& is, Point& p) {
  is >> p.x >> p.y;
  return is;
}

ostream& operator<<(ostream& os, const Point& p) {
  os << fixed << setprecision(12) << p.x << " " << p.y;
  return os;
}

typedef vector<Point> Polygon;

double cross(const Point& a, const Point& b) {
  return a.x * b.y - a.y * b.x;
}

bool isOrthogonal(const Point& a1, const Point& a2, const Point& b1, const Point& b2) {
  return equals(cross(a1 - a2, b1 - b2), 0.0);
}
