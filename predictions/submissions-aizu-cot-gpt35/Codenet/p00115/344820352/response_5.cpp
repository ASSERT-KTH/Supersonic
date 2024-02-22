#include <iostream>
#include <cmath>

class Point3d {
public:
  double x, y, z;
  Point3d(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}
  Point3d& operator+(const Point3d &a) {
    x += a.x;
    y += a.y;
    z += a.z;
    return *this;
  }
  Point3d& operator-(const Point3d &a) {
    x -= a.x;
    y -= a.y;
    z -= a.z;
    return *this;
  }
  Point3d& operator*(const double &d) {
    x *= d;
    y *= d;
    z *= d;
    return *this;
  }
  Point3d& operator/(const double &d) {
    x /= d;
    y /= d;
    z /= d;
    return *this;
  }
};

class Segment3d {
public:
  Point3d p[2];
  Segment3d(const Point3d &p1 = Point3d(), const Point3d &p2 = Point3d()) {
    p[0] = p1;
    p[1] = p2;
  }
};

class Plane3d {
public:
  Point3d normal_vector;
  double d;
  Plane3d(const Point3d &normal_vector = Point3d(), double d = 0)
      : normal_vector(normal_vector), d(d) {}
  Plane3d(const Point3d &a, const Point3d &b, const Point3d &c) {
    Point3d v1 = b - a;
    Point3d v2 = c - a;
    Point3d tmp = cross(v1, v2);
    normal_vector = tmp / abs(tmp);
    set_d(a);
  }
  void set_d(const Point3d &p) {
    d = dot(normal_vector, p);
  }
  double distanceP(const Point3d &p) {
    Point3d a = normal_vector * d;
    return abs(dot(p - a, normal_vector));
  }
  Point3d nearest_point(const Point3d &p) {
    Point3d a = normal_vector * d;
    return p - (normal_vector * dot(p - a, normal_vector));
  }
  bool intersectS(const Segment3d &seg) {
    Point3d a = normal_vector * d;
    double res1 = dot(a - seg.p[0], normal_vector);
    double res2 = dot(a - seg.p[1], normal_vector);
    if (res1 > res2)
      std::swap(res1, res2);
    if ((equals(res1, 0.0) || res1 < 0) && (equals(res2, 0.0) || res2 > 0))
      return true;
    return false;
  }
  Point3d crosspointS(const Segment3d &seg) {
    Point3d a = normal_vector * d;
    double dot_p0a = std::fabs(dot(seg.p[0] - a, normal_vector));
    double dot_p1a = std::fabs(dot(seg.p[1] - a, normal_vector));
    if (equals(dot_p0a + dot_p1a, 0))
      return seg.p[0];
    return seg.p[0] + (seg.p[1] - seg.p[0]) * (dot_p0a / (dot_p0a + dot_p1a));
  }
};

bool on_line3d(const Segment3d &line, const Point3d &p) {
  return equals(abs(cross(p - line.p[0], line.p[1] - line.p[0])), 0);
}

bool on_segment3d(const Segment3d &seg, const Point3d &p) {
  if (!on_line3d(seg, p))
    return false;
  double dist[3] = {abs(seg.p[1] - seg.p[0]), abs(p - seg.p[0]), abs(p - seg.p[1])};
  return equals(dist[0], dist[1] + dist[2]);
}

bool point_on_the_triangle3d(const Point3d &tri1, const Point3d &tri2, const Point3d &tri3,
                             const Point3d &p) {