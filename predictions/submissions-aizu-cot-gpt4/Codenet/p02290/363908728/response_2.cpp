#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

struct Point {
  double x, y;
};

struct Line {
  Point p1, p2;
};

double dot(const Point &a, const Point &b) {
  return a.x * b.x + a.y * b.y;
}

double cross(const Point &a, const Point &b) {
  return a.x * b.y - a.y * b.x;
}

Point projection(const Point &a, const Point &b) {
  double t = dot(a, b) / dot(a, a);
  return {a.x * t, a.y * t};
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout << std::fixed << std::setprecision(15);

  Line L;
  std::cin >> L.p1.x >> L.p1.y >> L.p2.x >> L.p2.y;
  
  int Q;
  std::cin >> Q;

  while (Q--) {
    Point p, w;
    std::cin >> p.x >> p.y;
    Point a = {L.p2.x - L.p1.x, L.p2.y - L.p1.y};
    Point b = {p.x - L.p1.x, p.y - L.p1.y};
    Point proj = projection(a, b);
    w = {L.p1.x + proj.x, L.p1.y + proj.y};
    std::cout << w.x << " " << w.y << "\n";
  }

  return 0;
}