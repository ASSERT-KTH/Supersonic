#include <iostream>
#include <iomanip>
#include <array>
#include <unordered_map>
#include <cmath>
#include <cassert>

#define REP(i, s, n) for (int i = s; i < n; i++)
#define rep(i, n) REP(i, 0, n)

constexpr double EPS = 1e-6;
constexpr double M_PI = 3.14159265358979323846;

class Point {
public:
  double x, y;
  Point(double x = 0, double y = 0) : x(x), y(y) {}
  Point operator+(const Point& p) const { return Point(x + p.x, y + p.y); }
  Point operator-(const Point& p) const { return Point(x - p.x, y - p.y); }
  Point operator*(double a) const { return Point(a * x, a * y); }
  Point operator/(double a) const { return Point(x / a, y / a); }
  Point operator*(const Point& a) const { return Point(x * a.x - y * a.y, x * a.y + y * a.x); }
  bool operator<(const Point& p) const { return (x != p.x) ? x < p.x : (y < p.y); }