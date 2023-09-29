#include <iostream>
#include <cmath>

class Point3d {
public:
  double x, y, z;
  Point3d(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}
  Point3d operator+(const Point3d &a) const { return Point3d(x + a.x, y + a.y, z + a.z); }
  Point3d operator-(const Point3d &a) const { return Point3d(x - a.x, y - a.y, z - a.z); }
  Point3d operator*(const double &d) const { return Point3d(x * d, y * d, z * d); }
  Point3d operator/(const double &d) const { return Point3d(x / d, y / d, z / d); }
};

double dot(const Point3d &a, const Point3d &b) { return a.x * b.x + a.y * b.y + a.z * b.z; }
Point3d cross(const Point3d &a, const Point3d &b) { return Point3d(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x); }
double abs(const Point3d &p) { return sqrt(dot(p, p)); }

class Plane3d {
public:
  Point3d normal_vector;
  double d;
  Plane3d(Point3d a, Point3d b, Point3d c) {
    normal_vector = cross(b - a, c - a) / abs(cross(b - a, c - a));
    d = dot(normal_vector, a);
  }
  bool intersectS(const Point3d &p0, const Point3d &p1) const {
    double res1 = dot(normal_vector * d - p0, normal_vector);
    double res2 = dot(normal_vector * d - p1, normal_vector);
    return (res1 <= 0 && 0 <= res2) || (res2 <= 0 && 0 <= res1);
  }
  Point3d crosspointS(const Point3d &p0, const Point3d &p1) const {
    return p0 + (p1 - p0) * (dot(normal_vector * d - p0, normal_vector) / dot(p1 - p0, normal_vector));
  }
};

bool point_on_the_triangle3d(const Point3d &tri1, const Point3d &tri2, const Point3d &tri3, const Point3d &p) {
  Point3d cp[3] = {cross(tri2 - tri1, p - tri1), cross(tri3 - tri2, p - tri2), cross(tri1 - tri3, p - tri3)};
  double d1 = dot(cp[0], cp[1]);
  double d2 = dot(cp[0], cp[2]);
  return (d1 >= 0 && d2 >= 0);
}

int main() {
  Point3d tri[3], S, G;
  std::cin >> S.x >> S.y >> S.z >> G.x >> G.y >> G.z;
  for(int i = 0; i < 3; ++i) std::cin >> tri[i].x >> tri[i].y >> tri[i].z;
  Plane3d plane(tri[0], tri[1], tri[2]);
  if (plane.intersectS(S, G)) {
    Point3d cp = plane.crosspointS(S, G);
    std::cout << (point_on_the_triangle3d(tri[0], tri[1], tri[2], cp) ? "MISS" : "HIT") << std::endl;
  } else {
    std::cout << "HIT" << std::endl;
  }
  return 0;
}