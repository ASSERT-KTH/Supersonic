#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < n; i++)
#define rep(i, n) REP(i, 0, n)
#define IINF (INT_MAX)
#define EPS (1e-7)
#define equals(a, b) (fabs((a) - (b)) < EPS)
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
    return !equals(x, p.x) ? x < p.x : ((!equals(y, p.y)) ? y < p.y : z < p.z);
  }
  bool operator==(const Point3d &p) const {
    return equals(x, p.x) && equals(y, p.y) && equals(z, p.z);
  }
};
struct Segment3d {
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
ostream &operator<<(ostream &os, const Point3d &p) {
  os << "(" << p.x << "," << p.y << "," << p.z << ")";
}
ostream &operator<<(ostream &os, const Segment3d &seg) {
  os << "(" << seg.p[0] << "," << seg.p[1] << ")";
}
double dot(const Point3d &a, const Point3d &b) {
  return a.x * b.x + a.y * b.y + a.z * b.z;
}
Vector3d cross(const Point3d &a, const Point3d &b) {
  return Vector3d(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z,
                  a.x * b.y - a.y * b.x);
}
inline double norm(const Point3d &p) {
  return p.x * p.x + p.y * p.y + p.z * p.z;
}
inline double abs(const Point3d &p) { return sqrt(norm(p)); }
inline double toRad(double theta) { return theta * M_PI / 180.0; }
bool on_line3d(Line3d line, Point3d p) {
  return equals(abs(cross(p - line.p[0], line.p[1] - line.p[0])), 0);
}
bool on_segment3d(Segment3d seg, Point3d p) {
  if (!on_line3d(seg, p))
    return false;
  double dist[3] = {abs(seg.p[1] - seg.p[0]), abs(p - seg.p[0]),
                    abs(p - seg.p[1])};
  return on_line3d(seg, p) && equals(dist[0], dist[1] + dist[2]);
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
inline Point3d rotateX(Point3d p, double rad) {
  return Point3d(p.x, p.y * cos(rad) - p.z * sin(rad),
                 p.y * sin(rad) + p.z * cos(rad));
}
inline Point3d rotateY(Point3d p, double rad) {
  return Point3d(p.x * cos(rad) + p.z * sin(rad), p.y,
                 -p.x * sin(rad) + p.z * cos(rad));
}
inline Point3d rotateZ(Point3d p, double rad) {
  return Point3d(p.x * cos(rad) - p.y * sin(rad),
                 p.x * sin(rad) + p.y * cos(rad), p.z);
}
inline Point3d rotateEuler(Point3d p, double alpha, double beta, double gamma) {
  return Point3d(
      (cos(alpha) * cos(beta) * cos(gamma) - sin(alpha) * sin(gamma)) * p.x +
          (-cos(alpha) * cos(beta) * sin(gamma) - sin(alpha) * cos(gamma)) *
              p.y +
          (cos(alpha) * sin(beta)) * p.z,
      (sin(alpha) * cos(beta) * cos(gamma) + cos(alpha) * sin(gamma)) * p.x +
          (-sin(alpha) * cos(beta) * sin(gamma) + cos(alpha) * cos(gamma)) *
              p.y +
          (sin(alpha) * sin(beta)) * p.z,
      (-sin(beta) * cos(gamma)) * p.x + (sin(beta) * sin(gamma)) * p.y +
          (cos(beta)) * p.z);
}
inline Point3d rotateRollPitchYaw(Point3d p, double roll, double pitch,
                                  double yaw) {
  return Point3d(
      (cos(roll) * cos(pitch)) * p.x +
          (cos(roll) * sin(pitch) * sin(yaw) - sin(roll) * cos(yaw))