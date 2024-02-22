#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

constexpr float EPS = 1e-10;
constexpr float PI = 3.141592653589793238;

struct Point {
  float x, y;
  Point() {}
  Point(float x, float y) : x(x), y(y) {}
};

std::istream &operator>>(std::istream &is, Point &p) {
  is >> p.x >> p.y;
  return is;
}

std::ostream &operator<<(std::ostream &os, const Point &p) {
  os << std::fixed << std::setprecision(12) << p.x << " " << p.y;
  return os;
}

float norm(const Point& p) {
  return p.x * p.x + p.y * p.y;
}

float cross(const Point& a, const Point& b) {
  return a.x * b.y - a.y * b.x;
}

float distance(const Point& p1, const Point& p2) {
  return std::sqrt(norm(Point(p1.x - p2.x, p1.y - p2.y)));
}

float diameter(const std::vector<Point>& polygon) {
  int n = polygon.size();
  if (n < 3)
    return 0.0;

  float res = 0.0;
  int i = 0, j = 0;
  for (int k = 0; k < n; k++) {
    if (polygon[i].x < polygon[k].x || (polygon[i].x == polygon[k].x && polygon[i].y < polygon[k].y))
      i = k;
    if (polygon[j].x > polygon[k].x || (polygon[j].x == polygon[k].x && polygon[j].y > polygon[k].y))
      j = k;
  }

  while (i != j) {