#include <iostream>
#include <vector>
#include <set>

#define EPS 1e-10

struct Point {
  double x, y;
  Point(double x = 0, double y = 0) : x(x), y(y) {}
  Point operator+(const Point& p) const { return Point(x + p.x, y + p.y); }
  Point operator-(const Point& p) const { return Point(x - p.x, y - p.y); }
  bool operator==(const Point& p) const { return (x == p.x && y == p.y); }
  bool operator<(const Point& p) const { return x < p.x || (x == p.x && y < p.y); }
};

typedef std::pair<Point, Point> Segment;

double cross(const Point& a, const Point& b) { return a.x * b.y - a.y * b.x; }

bool isIntersect(const Point& p1, const Point& p2, const Point& p3, const Point& p4) {
  return cross(p2 - p1, p3 - p1) * cross(p2 - p1, p4 - p1) < -EPS &&
         cross(p4 - p3, p1 - p3) * cross(p4 - p3, p2 - p3) < -EPS;
}

Point crosspoint(const Point& p1, const Point& p2, const Point& p3, const Point& p4) {
  double A = cross(p2 - p1, p4 - p3);
  Point pro = cross(p2 - p1, p2 - p3);
  pro.x *= (pro.x / A);
  pro.y *= (pro.y / A);
  return p3 + pro;
}

int main() {
  int n;
  while (std::cin >> n && n) {
    int field = 1;
    std::vector<Segment> segments;
    for (int i = 0; i < n; i++) {
      int x1, y1, x2, y2;
      std::cin >> x1 >> y1 >> x2 >> y2;
      segments.push_back({Point(x1, y1), Point(x2, y2)});
      int x_counter = 0;
      std::set<Point> existingPoints;
      for (int j = 0; j < i; j++) {
        if (isIntersect(segments[j].first, segments[j].second, segments[i].first, segments[i].second)) {
          Point xp = crosspoint(segments[j].first, segments[j].second, segments[i].first, segments[i].second);
          if (100 - std::abs(xp.x) < EPS || 100 - std::abs(xp.y) < EPS)
            continue;
          if (existingPoints.count(xp) == 0) {
            x_counter++;
            existingPoints.insert(xp);
          }
        }
      }
      field += x_counter + 1;
    }
    std::cout << field << std::endl;
  }
  return 0;
}