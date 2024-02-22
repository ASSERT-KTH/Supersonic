#include <iostream>
#include <cmath>

struct Point3d {
  double x, y, z;
};

struct Line3d {
  Point3d p1, p2;
};

struct Plane3d {
  Point3d normal_vector;
  double d;
};

const double EPS = 1e-7;

bool equals(double a, double b) {
  return fabs(a - b) < EPS;
}

double dot(const Point3d& a, const Point3d& b) {
  return a.x * b.x + a.y * b.y + a.z * b.z;
}

Point3d cross(const Point3d& a, const Point3d& b) {
  return {a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x};
}

double norm(const Point3d& p) {
  return p.x * p.x + p.y * p.y + p.z * p.z;
}

double abs(const Point3d& p) {
  return sqrt(norm(p));
}

bool on_line3d(const Line3d& line, const Point3d& p) {
  return equals(abs(cross({p.x - line.p1.x, p.y - line.p1.y, p.z - line.p1.z}, {line.p2.x - line.p1.x, line.p2.y - line.p1.y, line.p2.z - line.p1.z})), 0);
}

bool point_on_the_triangle3d(const Point3d& tri1, const Point3d& tri2, const Point3d& tri3, const Point3d& p) {
  if (on_line3d({tri1, tri2}, p)) return true;
  if (on_line3d({tri2, tri3}, p)) return true;
  if (on_line3d({tri3, tri1}, p)) return true;
  
  Point3d v1 = {tri2.x - tri1.x, tri2.y - tri1.y, tri2.z - tri1.z};
  Point3d v2 = {tri3.x - tri2.x, tri3.y - tri2.y, tri3.z - tri2.z};
  Point3d v3 = {tri1.x - tri3.x, tri1.y - tri3.y, tri1.z - tri3.z};
  
  Point3d cp[3] = {
    cross(v1, {p.x - tri1.x, p.y - tri1.y, p.z - tri1.z}),
    cross(v2, {p.x - tri2.x, p.y - tri2.y, p.z - tri2.z}),
    cross(v3, {p.x - tri3.x, p.y - tri3.y, p.z - tri3.z})
  };
  
  double d1 = dot(cp[0], cp[1]);
  double d2 = dot(cp[0], cp[2]);
  
  if ((!equals(d1, 0.0) && d1 > 0) && (!equals(d2, 0.0) && d2 > 0))
    return true;
  
  return false;
}

bool intersectS(const Plane3d& plane, const Line3d& seg) {
  Point3d a = {plane.normal_vector.x * plane.d, plane.normal_vector.y * plane.d, plane.normal_vector.z * plane.d};
  double res1 = dot({a.x - seg.p1.x, a.y - seg.p1.y, a.z - seg.p1.z}, plane.normal_vector);
  double res2 = dot({a.x - seg.p2.x, a.y - seg.p2.y, a.z - seg.p2.z}, plane.normal_vector);
  
  if (res1 > res2) std::swap(res1, res2);
  