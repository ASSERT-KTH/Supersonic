#include <iostream>
#include <cmath>
#include <string>
#define EPS (1e-7)

struct Point3d {
  double x, y, z;
  Point3d(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}
  Point3d operator+(const Point3d &p) const { return Point3d(x + p.x, y + p.y, z + p.z); }
  Point3d operator-(const Point3d &p) const { return Point3d(x - p.x, y - p.y, z - p.z); }
  Point3d operator*(double d) const { return Point3d(x * d, y * d, z * d); }
};

inline double dot(const Point3d &a, const Point3d &b) {
  return a.x * b.x + a.y * b.y + a.z * b.z;
}

inline double abs(const Point3d &p) { 
    return sqrt(dot(p, p)); 
}

inline double cross(const Point3d &a, const Point3d &b) {
  return abs(Point3d(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x));
}

struct Segment3d {
  Point3d p[2];
  Segment3d(Point3d p1 = Point3d(), Point3d p2 = Point3d()) {
    p[0] = p1, p[1] = p2;
  }
};

struct Plane3d {
  Point3d normal_vector;
  double d;
  Plane3d(Point3d a, Point3d b, Point3d c) {
    Point3d v1 = b - a;
    Point3d v2 = c - a;
    normal_vector = Point3d(v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x * v2.z, v1.x * v2.y - v1.y * v2.x);
    d = dot(normal_vector, a);
  }
  bool intersectS(Segment3d seg) {
    double res1 = dot(normal_vector, seg.p[0]) - d;
    double res2 = dot(normal_vector, seg.p[1]) - d;
    return res1 * res2 <= 0;
  }
  Point3d crosspointS(Segment3d seg) {
    double t = (d - dot(normal_vector, seg.p[0])) / dot(normal_vector, seg.p[1] - seg.p[0]);
    return seg.p[0] + (seg.p[1] - seg.p[0]) * t;
  }
};

bool point_on_the_triangle3d(Point3d tri1, Point3d tri2, Point3d tri3, Point3d p) {
  double area1 = cross(tri2 - tri1, p - tri1);
  double area2 = cross(tri3 - tri2, p - tri2);
  double area3 = cross(tri1 - tri3, p - tri3);
  return area1 >= 0 && area2 >= 0 && area3 >= 0;
}

int main() {
  Point3d tri[3], S, G;
  std::cin >> S.x >> S.y >> S.z;
  std::cin >> G.x >> G.y >> G.z;
  for(int i = 0; i < 3; ++i) std::cin >> tri[i].x >> tri[i].y >> tri[i].z;
  Plane3d plane(tri[0], tri[1], tri[2]);
  Segment3d seg(S, G);
  if (!plane.intersectS(seg)) {
    std::cout << "MISS\n";
    return 0;
  }
  Point3d cp = plane.crosspointS(seg);
  std::cout << (point_on_the_triangle3d(tri[0], tri[1], tri[2], cp) ? "HIT\n" : "MISS\n");
  return 0;
}