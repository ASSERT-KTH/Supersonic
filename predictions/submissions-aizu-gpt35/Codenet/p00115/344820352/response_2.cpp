#include <iostream>
#include <cmath>
using namespace std;

class Point3d {
public:
  double x, y, z;
  Point3d(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}
  Point3d operator+(const Point3d &a) const {
    return Point3d(x + a.x, y + a.y, z + a.z);
  }
  Point3d operator-(const Point3d &a) const {
    return Point3d(x - a.x, y - a.y, z - a.z);
  }
  Point3d operator*(const double &d) const { return Point3d(x * d, y * d, z * d); }
  Point3d operator/(const double &d) const { return Point3d(x / d, y / d, z / d); }
  bool operator<(const Point3d &p) const {
    return x != p.x ? x < p.x : (y != p.y ? y < p.y : z < p.z);
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

typedef Point3d Vector3d;
typedef Segment3d Line3d;

double dot(const Point3d &a, const Point3d &b) {
  return a.x * b.x + a.y * b.y + a.z * b.z;
}

Vector3d cross(const Point3d &a, const Point3d &b) {
  return Vector3d(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z,
                  a.x * b.y - a.y * b.x);
}

double norm(const Point3d &p) {
  return p.x * p.x + p.y * p.y + p.z * p.z;
}

double abs(const Point3d &p) { return sqrt(norm(p)); }

bool equals(double a, double b) { return fabs(a - b) < 1e-7; }

bool on_line3d(Line3d line, Point3d p) {
  return equals(abs(cross(p - line.p[0], line.p[1] - line.p[0])), 0);
}

bool on_segment3d(Segment3d seg, Point3d p) {
  if (!on_line3d(seg, p))
    return false;
  double dist[3] = {abs(seg.p[1] - seg.p[0]), abs(p - seg.p[0]),
                    abs(p - seg.p[1])};
  return equals(dist[0], dist[1] + dist[2]);
}

bool point_on_the_triangle3d(Point3d tri1, Point3d tri2, Point3d tri3,
                             Point3d p) {
  if (on_segment3d(Segment3d(tri1, tri2), p))
    return true;
  if (on_segment3d(Segment3d(tri2, tri3), p))
    return true;
  if (on_segment3d(Segment3d(tri3, tri1), p))
    return true;
  Vector3d v1 = tri2 - tri1;
  Vector3d v2 = tri3 - tri2;
  Vector3d v3 = tri1 - tri3;
  Vector3d cp[3] = {cross(v1, p - tri1), cross(v2, p - tri2),
                    cross(v3, p - tri3)};
  double d1 = dot(cp[0], cp[1]);
  double d2 = dot(cp[0], cp[2]);
  if ((!equals(d1, 0.0) && d1 > 0) && (!equals(d2, 0.0) && d2 > 0))
    return true;
  return false;
}

bool intersectS(const Segment3d &seg, const Point3d &a,
                const Point3d &normal_vector, const double &d) {
  double res1 = dot(a - seg.p[0], normal_vector);
  double res2 = dot(a - seg.p[1], normal_vector);
  if (res1 > res2)
    swap(res1, res2);
  if ((equals(res1, 0.0) || res1 < 0) && (equals(res2, 0.0) || res2 > 0))
    return true;
  return false;
}

Point3d crosspointS(const Segment3d &seg, const Point3d &a,
                    const Point3d &normal_vector, const double &d) {
  double dot_p0a = fabs(dot(seg.p[0] - a, normal_vector));
  double dot_p1a = fabs(dot(seg.p[1] - a, normal_vector));
  if (equals(dot_p0a + dot_p1a, 0))
    return seg.p[0];
  return seg.p[0] + (seg.p[1] - seg.p[0]) * (dot_p0a / (dot_p0a + dot_p1a));
}

bool point_on_the_triangle3d_optimized(const Point3d &tri1,
                                       const Point3d &tri2,
                                       const Point3d &tri3, const Point3d &p,
                                       const Point3d &normal_vector,
                                       const double &d) {
  if (on_segment3d(Segment3d(tri1, tri2), p))
    return true;
  if (on_segment3d(Segment3d(tri2, tri3), p))
    return true;
  if (on_segment3d(Segment3d(tri3, tri1), p))
    return true;

  Vector3d v1 = tri2 - tri1;
  Vector3d v2 = tri3 - tri2;
  Vector3d v3 = tri1 - tri3;

  Vector3d cp[3] = {cross(v1, p - tri1), cross(v2, p - tri2),
                    cross(v3, p - tri3)};
  double d1 = dot(cp[0], cp[1]);
  double d2 = dot(cp[0], cp[2]);
  if ((d1 > 0) ^ (d2 > 0))
    return false;

  return intersectS(Segment3d(tri1, tri2), p, normal_vector, d) ||
         intersectS(Segment3d(tri2, tri3), p, normal_vector, d) ||
         intersectS(Segment3d(tri3, tri1), p