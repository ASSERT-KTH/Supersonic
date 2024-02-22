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
    return (x != p.x) ? x < p.x : ((y != p.y) ? y < p.y : z < p.z);
  }
  bool operator==(const Point3d &p) const {
    return fabs(x - p.x) < 1e-7 && fabs(y - p.y) < 1e-7 && fabs(z - p.z) < 1e-7;
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
  return Point3d(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z,
                 a.x * b.y - a.y * b.x);
}

inline double norm(const Point3d &p) {
  return p.x * p.x + p.y * p.y + p.z * p.z;
}

inline double abs(const Point3d &p) { return sqrt(norm(p)); }

inline double toRad(double theta) { return theta * M_PI / 180.0; }

bool on_line3d(Segment3d line, Point3d p) {
  return fabs(abs(cross(p - line.p[0], line.p[1] - line.p[0]))) < 1e-7;
}

bool on_segment3d(Segment3d seg, Point3d p) {
  if (!on_line3d(seg, p))
    return false;
  double dist[3] = {abs(seg.p[1] - seg.p[0]), abs(p - seg.p[0]),
                    abs(p - seg.p[1])};
  return fabs(dist[0] - (dist[1] + dist[2])) < 1e-7;
}

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