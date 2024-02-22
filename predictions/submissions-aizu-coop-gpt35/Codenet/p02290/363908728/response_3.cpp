#include <iostream>
#include <vector>

struct Point {
  double x, y;
};

struct Line {
  Point p1, p2;
};

void projection(const Line& L, const Point& p, Point& w) {
  double t = ((p.x - L.p1.x) * (L.p2.x - L.p1.x) + (p.y - L.p1.y) * (L.p2.y - L.p1.y)) /
             ((L.p2.x - L.p1.x) * (L.p2.x - L.p1.x) + (L.p2.y - L.p1.y) * (L.p2.y - L.p1.y));
  w.x = L.p1.x + t * (L.p2.x - L.p1.x);
  w.y = L.p1.y + t * (L.p2.y - L.p1.y);
}

int main() {
  Line L;
  std::cin >> L.p1.x >> L.p1.y >> L.p2.x >> L.p2.y;
  
  int Q;
  std::cin >> Q;
  
  while (Q--) {
    Point p, w;
    std::cin >> p.x >> p.y;
    projection(L, p, w);
    std::cout << w.x << " " << w.y << std::endl;
  }
  
  return 0;
}