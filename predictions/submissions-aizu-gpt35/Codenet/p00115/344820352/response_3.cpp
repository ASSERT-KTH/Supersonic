#include <bits/stdc++.h>
using namespace std;

#define REP(i, s, n) for (int i = s; i < n; i++)
#define rep(i, n) REP(i, 0, n)

const double EPS = 1e-7;

struct Point3d {
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
    if (x != p.x) return x < p.x;
    if (y != p.y) return y < p.y;
    return z < p.z;
  }
  bool operator==(const Point3d &p) const {
    return abs(x - p.x) < EPS && abs(y - p.y) < EPS && abs(z - p.z) < EPS;
  }
};

struct Segment3d {
  Point3d p[2];
  Segment3d(Point3d p1 = Point3d(), Point3d p2 = Point3d()) : p{p1, p2} {}
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

bool on_line3d(Line3d line, Point3d p) {
  return abs(cross(p - line.p[0], line.p[1] - line.p[0])) < EPS;
}

bool on_segment3d(Segment3d seg, Point3d p) {
  if (!on_line3d(seg, p)) return false;
  double dist[3] = {abs(seg.p[1] - seg.p[0]), abs(p - seg.p[0]), abs(p - seg.p[1])};
  return abs(dist[0] - dist[1] - dist[2]) < EPS;
}

bool point_on_the_triangle3d(Point3d tri1, Point3d tri2, Point3d tri3, Point3d p) {
  if (on_segment3d(Segment3d(tri1, tri2), p)) return true;
  if (on_segment3d(Segment3d(tri2, tri3), p)) return true;
  if (on_segment3d(Segment3d(tri3, tri1), p)) return true;
  Vector3d v1 = tri2 - tri1;
  Vector3d v2 = tri3 - tri2;
  Vector3d v3 = tri1 - tri3;
  Vector3d cp[3] = {cross(v1, p - tri1), cross(v2, p - tri2), cross(v3, p - tri3)};
  double d1 = dot(cp[0], cp[1]);
  double d2 = dot(cp[0], cp[2]);
  return (abs(d1) > EPS && d1 > 0) && (abs(d2) > EPS && d2 > 0);
}

inline Point3d rotateX(Point3d p, double rad) {
  return Point3d(p.x, p.y * cos(rad) - p.z * sin(rad), p.y * sin(rad) + p.z * cos(rad));
}

inline Point3d rotateY(Point3d p, double rad) {
  return Point3d(p.x * cos(rad) + p.z * sin(rad), p.y, -p.x * sin(rad) + p.z * cos(rad));
}

inline Point3d rotateZ(Point3d p, double rad) {
  return Point3d(p.x * cos(rad) - p.y * sin(rad), p.x * sin(rad) + p.y * cos(rad), p.z);
}

inline Point3d rotateEuler(Point3d p, double alpha, double beta, double gamma) {
  return Point3d(
      (cos(alpha) * cos(beta) * cos(gamma) - sin(alpha) * sin(gamma)) * p.x +
          (-cos(alpha) * cos(beta) * sin(gamma) - sin(alpha) * cos(gamma)) * p.y +
          (cos(alpha) * sin(beta)) * p.z,
      (sin(alpha) * cos(beta) * cos(gamma) + cos(alpha) * sin(gamma)) * p.x +
          (-sin(alpha) * cos(beta) * sin(gamma) + cos(alpha) * cos(gamma)) * p.y +
          (sin(alpha) * sin(beta)) * p.z,
      (-sin(beta) * cos(gamma)) * p.x + (sin(beta) * sin(gamma)) * p.y +
          (cos(beta)) * p.z);
}

inline Point3d rotateRollPitchYaw(Point3d p, double roll, double pitch, double yaw) {
  return Point3d(
      (cos(roll) * cos(pitch)) * p.x +
          (cos(roll) * sin(pitch) * sin(yaw) - sin(roll) * cos(yaw)) * p.y +
          (cos(roll) * sin(pitch) * cos(yaw) + sin(roll) * sin(yaw)) * p.z,
      (sin(roll) * cos(pitch)) * p.x +
          (sin(roll) * sin(pitch) * sin(yaw) + cos(roll) * cos(yaw)) * p.y +
          (sin(roll) * sin(pitch) * cos(yaw) - cos(roll) * sin(yaw)) * p.z,
      -sin(pitch) * p.x + cos(pitch) * sin(yaw) * p.y + cos(pitch) * cos(yaw) * p.z);
}

class Plane3d {
public:
 