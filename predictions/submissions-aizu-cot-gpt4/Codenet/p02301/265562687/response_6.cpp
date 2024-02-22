#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>
#include <iomanip>

constexpr double EPS = 1e-10;
constexpr double PI = 3.141592653589793238;
constexpr int COUNTER_CLOCKWISE = 1;
constexpr int CLOCKWISE = -1;
constexpr int ONLINE_BACK = 2;
constexpr int ONLINE_FRONT = -2;
constexpr int ON_SEGMENT = 0;

struct Point {
  double x, y;
  Point() {}
  Point(double x, double y) : x(x), y(y) {}
  Point operator+(const Point &p) { return {x + p.x, y + p.y}; }
  Point operator-(const Point &p) { return {x - p.x, y - p.y}; }
  Point operator*(double k) { return {x * k, y * k}; }
  Point operator/(double k) { return {x / k, y / k}; }
  double norm() const { return x * x + y * y; }
  double abs() const { return std::sqrt(norm()); }
  bool operator<(const Point &p) const { return x != p.x ? x < p.x : y < p.y; }
  bool operator==(const Point &p) const {
    return std::fabs(x - p.x) < EPS && std::fabs(y - p.y) < EPS;
  }
};

std::istream &operator>>(std::istream &is, Point &p) {
  is >> p.x >> p.y;
  return is;
}

std::ostream &operator<<(std::ostream &os, Point p) {
  os << std::fixed << std::setprecision(12) << p.x << " " << p.y;
  return os;
}

// ... rest of the code

int main() {
  int n;
  std::cin >> n;
  Polygon p(n);
  for (int i = 0; i < n; ++i)
    std::cin >> p[i];
  printf("%.12f\n", diameter(p));
  return 0;
}