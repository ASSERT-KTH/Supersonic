#include <iostream>
#include <cmath>

#define EPSILON (1e-7)

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
    return !equals(x, p.x) ? x < p.x : ((!equals(y, p.y)) ? y < p.y : z < p.z);
  }
  bool operator==(const Point3d &p) const {
    return equals(x, p.x) && equals(y, p.y) && equals(z, p.z);
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
  double distanceP(Point3d p) {
    Point3d a = normal_vector * d;
    return abs(dot(p - a, normal_vector));
  }
  Point3d nearest_point(Point3d p) {
    Point3d a = normal_vector * d;
    return p - (normal_vector * dot(p - a, normal_vector));
  }
  bool intersectS(Segment3d seg) {
    Point3d a = normal_vector * d;
    double res1 = dot(a - seg.p[0], normal_vector);
    double res2 = dot(a - seg.p[1], normal_vector);
    if (res1 > res2)
      swap(res1, res2);
    if ((equals(res1, 0.0) || res1 < 0) && (equals(res2, 0.0) || res2 > 0))
      return true;
    return false;
  }
  Point3d crosspointS(Segment3d seg) {
    Point3d a = normal_vector * d;
    double dot_p0a = fabs(dot(seg.p[0] - a, normal_vector));
    double dot_p1a = fabs(dot(seg.p[1] - a, normal_vector));
    if (equals(dot_p0a + dot_p1a, 0))
      return seg.p[0];
    return seg.p[0] + (seg.p[1] - seg.p[0]) * (dot_p0a / (dot_p0a + dot_p1a));
  }
};

ostream &operator<<(ostream &os, const Point3d &p) {
  os << "(" << p.x << "," << p.y << "," << p.z << ")";
  return os;
}

ostream &operator<<(ostream &os, const Segment3d &seg) {
  os << "(" << seg.p[0] << "," << seg.p[1] << ")";
  return os;
}

double dot(const Point3d &a, const Point3d &b) {
  return a.x * b.x + a.y * b.y + a.z * b.z;
}

Point3d cross(const Point3d &a, const Point3d &b) {
  return Point3d(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
}

inline double norm(const Point3d &p) {
  return p.x * p.x + p.y * p.y + p.z * p.z;
}

inline double abs(const Point3d &p) { return sqrt(norm(p)); }

inline double toRad(double theta) { return theta * M_PI / 180.0; }

bool on_line3d(Segment3d line, Point3d p) {
  return equals(abs(cross(p - line.p[0], line.p[1] - line.p[0])), 0);
}

bool on_segment3d(Segment3d seg, Point3d p) {
  double dist[3] = {abs(seg.p[1] - seg.p[0]), abs(p - seg.p[0]), abs(p - seg.p[1])};
  return on_line3d(seg, p) && equals(dist[0], dist[1] + dist[2]);
}

bool point_on_the_triangle3d(Point3d tri1, Point3d tri2, Point3d tri3, Point3d p) {
  if (on_segment3d(Segment3d(tri1, tri2), p))
    return true;