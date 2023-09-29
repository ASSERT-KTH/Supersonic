#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cassert>
#include <cstdio>

#define EPS (1e-9)
#define COUNTER_CLOCKWISE 1
#define CLOCKWISE -1
#define ONLINE_BACK 2
#define ONLINE_FRONT -2
#define ON_SEGMENT 0

class Point {
public:
  double x, y;
  Point(double x = 0, double y = 0) : x(x), y(y) {}
  Point operator+(const Point& p) const { return Point(x + p.x, y + p.y); }
  Point operator-(const Point& p) const { return Point(x - p.x, y - p.y); }
  Point operator*(double a) const { return Point(a * x, a * y); }
  Point operator/(double a) const { return Point(x / a, y / a); }
  bool operator<(const Point& p) const { return x != p.x ? x < p.x : y < p.y; }
  bool operator==(const Point& p) const { return fabs(x - p.x) < EPS && fabs(y - p.y) < EPS; }
};

struct Segment {
  Point p1, p2;
  int index;
  Segment(const Point& p1 = Point(), const Point& p2 = Point(), int index = -1)
      : p1(p1), p2(p2), index(index) {}
  bool operator<(const Segment& s) const {
    return (p2 == s.p2) ? p1 < s.p1 : p2 < s.p2;
  }
};

inline double dot(const Point& a, const Point& b) { return a.x * b.x + a.y * b.y; }
inline double cross(const Point& a, const Point& b) { return a.x * b.y - a.y * b.x; }
inline double norm(const Point& a) { return a.x * a.x + a.y * a.y; }
inline double abs(const Point& a) { return std::sqrt(norm(a)); }

int ccw(const Point& p0, const Point& p1, const Point& p2) {
  const Point a = p1 - p0;
  const Point b = p2 - p0;
  if (cross(a, b) > EPS) return COUNTER_CLOCKWISE;
  if (cross(a, b) < -EPS) return CLOCKWISE;
  if (dot(a, b) < -EPS) return ONLINE_BACK;
  if (norm(a) < norm(b)) return ONLINE_FRONT;
  return ON_SEGMENT;
}

bool intersectSS(const Segment& s, const Segment& t) {
  return ccw(s.p1, s.p2, t.p1) * ccw(s.p1, s.p2, t.p2) <= 0 &&
         ccw(t.p1, t.p2, s.p1) * ccw(t.p1, t.p2, s.p2) <= 0;
}

Point crosspoint(const Segment& l, const Segment& m) {
  double A = cross(l.p2 - l.p1, m.p2 - m.p1);
  double B = cross(l.p2 - l.p1, l.p2 - m.p1);
  if (fabs(A) < EPS && fabs(B) < EPS) {
    std::vector<Point> vec = {l.p1, l.p2, m.p1, m.p2};
    sort(vec.begin(), vec.end());
    assert(vec[1] == vec[2]);
    return vec[1];
  }
  if (fabs(A) < EPS) assert(false);
  return m.p1 + (m.p2 - m.p1) * (B / A);
}

void compute(std::vector<Segment>& vec) {
  if (vec.size() <= 2) {
    std::cout << "Many\n";
    return;
  }

  std::vector<Point> cp;
  for (int i = 0; i < vec.size(); ++i)
    for (int j = i + 1; j < vec.size(); ++j)
      if (intersectSS(vec[i], vec[j]))
        cp.push_back(crosspoint(vec[i], vec[j]));

  for (auto& p : cp) {
    bool ok = true;
    for (auto& s : vec)
      ok &= fabs(abs(s.p1 - p) + abs(s.p2 - p) - abs(s.p1 - s.p2)) < EPS;
    if (ok) {
      printf("%.10f %.10f\n", p.x, p.y);
      return;
    }
  }

  std::cout << "None\n";
}

int main() {
  int n;
  while (std::cin >> n, n) {
    std::vector<Segment> vec(n);
    for (int i = 0; i < n; ++i)
      std::cin >> vec[i].p1.x >> vec[i].p1.y >> vec[i].p2.x >> vec[i].p2.y;
    compute(vec);
  }
  return 0;
}