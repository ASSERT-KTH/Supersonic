#include <iostream>
#include <cmath>

using namespace std;

class Point3d {
public:
  double x, y, z;
  Point3d(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}
  Point3d operator+(const Point3d &a) {
    return Point3d(x + a.x, y + a.y, z + a.z);
  }
  Point3d operator-(const Point3d &a) {
    return Point3d(x - a.x, y - a.y, z - a.z);
  }
  Point3d operator*(const double &d) { return Point3d(x * d, y * d, z * d); }
  Point3d operator/(const double &d) { return Point3d(x / d, y / d, z / d); }
  bool operator<(const Point3d &p) const {
    return x < p.x || (x == p.x && (y < p.y || (y == p.y && z < p.z)));
  }
  bool operator==(const Point3d &p) const {
    return x == p.x && y == p.y && z == p.z;
  }
};

class Segment3d {
public:
  Point3d p[2];
  Segment3d(Point3d p1 = Point3d(), Point3d p2 = Point3d()) {
    p[0] = p1, p[1] = p2;
  }
  bool operator==(const Segment3d &seg) const {
    return p[0] == seg.p[0] && p[1] == seg.p[1];
  }
};

class Plane3d {
public:
  Point3d normal_vector;
  double d;
  Plane3d(Point3d normal_vector = Point3d(), double d = 0)
      : normal_vector(normal_vector), d(d) {}
  Plane3d(Point3d a, Point3d b, Point3d c) {
    Point3d v1 = b - a;
    Point3d v2 = c - a;
    Point3d tmp = cross(v1, v2);
    normal_vector = tmp / abs(tmp);
    set_d(a);
  }
  void set_d(Point3d p) { d = dot(normal_vector, p); }
  Point3d nearest_point(Point3d p) {
    return p - (normal_vector * dot(p - (normal_vector * d), normal_vector));
  }
  bool intersectS(Segment3d seg) {
    double res1 = dot(seg.p[0] - (normal_vector * d), normal_vector);
    double res2 = dot(seg.p[1] - (normal_vector * d), normal_vector);
    if (res1 > res2)
      swap(res1, res2);
    return (res1 <= 0 && res2 >= 0);
  }
  Point3d crosspointS(Segment3d seg) {
    double dot_p0a = fabs(dot(seg.p[0] - (normal_vector * d), normal_vector));
    double dot_p1a = fabs(dot(seg.p[1] - (normal_vector * d), normal_vector));
    if (fabs(dot_p0a + dot_p1a) < 1e-7)
      return seg.p[0];
    return seg.p[0] + (seg.p[1] - seg.p[0]) * (dot_p0a / (dot_p0a + dot_p1a));
  }
};

Point3d cross(const Point3d &a, const Point3d &b) {
  return Point3d(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z,
                 a.x * b.y - a.y * b.x);
}

double dot(const Point3d &a, const Point3d &b) {
  return a.x * b.x + a.y * b.y + a.z * b.z;
}

double abs(const Point3d &p) { return sqrt(dot(p, p)); }

bool point_on_the_triangle3d(Point3d tri1, Point3d tri2, Point3d tri3,
                             Point3d p) {
  if (on_segment3d(Segment3d(tri1, tri2), p))
    return true;
  if (on_segment3d(Segment3d(tri2, tri3), p))
    return true;
  if (on_segment3d(Segment3d(tri3, tri1), p))
    return true;
  Point3d v1 = tri2 - tri1;
  Point3d v2 = tri3 - tri2;
  Point3d v3 = tri1 - tri3;
  Point3d cp[3] = {cross(v1, p - tri1), cross(v2, p - tri2),
                    cross(v3, p - tri3)};
  double d1 = dot(cp[0], cp[1]);
  double d2 = dot(cp[0], cp[2]);