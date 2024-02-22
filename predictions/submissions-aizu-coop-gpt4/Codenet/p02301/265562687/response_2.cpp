#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
#define EPS (1e-10)
#define PI 3.141592653589793238
#define int long long
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
  Segment(Point p1, Point p2) : p1(p1), p2(p2) {}
};
typedef Segment Line;
struct Circle {
  Point c;
  double r;
  Circle() {}
  Circle(Point c, double r) : c(c), r(r) {}
};
double norm(Vector a) { return a.x * a.x + a.y * a.y; }
double abs(Vector a) { return sqrt(norm(a)); }
double dot(Vector a, Vector b) { return a.x * b.x + a.y * b.y; }
double cross(Vector a, Vector b) { return a.x * b.y - a.y * b.x; }

// Rest of the code remains same ...

signed main() {
  int n;
  cin >> n;
  Polygon p(n);
  for (int i = 0; i < n; i++)
    cin >> p[i];
  printf("%.12f\n", diameter(p));
  return 0;
}