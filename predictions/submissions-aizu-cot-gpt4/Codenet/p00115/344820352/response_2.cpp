#include <iostream>
#include <cmath>
#include <algorithm>

#define REP(i, s, n) for (int i = s; i < n; i++)
#define rep(i, n) REP(i, 0, n)
#define IINF (INT_MAX)
#define EPS (1e-7)
#define equals(a, b) (fabs((a) - (b)) < EPS)

using namespace std;

// Classes and functions remain the same, just showing the changes.

double dot(const Point3d &a, const Point3d &b) {
  return a.x * b.x + a.y * b.y + a.z * b.z;
}

Vector3d cross(const Point3d &a, const Point3d &b) {
  return Vector3d(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z,
                  a.x * b.y - a.y * b.x);
}

// ... Other functions ...

bool point_on_the_triangle3d(const Point3d& tri1, const Point3d& tri2, const Point3d& tri3,
                             const Point3d& p) {
  // ... Same code ...
}

Point3d crosspointTS(const Point3d& tri1, const Point3d& tri2, const Point3d& tri3, const Segment3d& seg) {
  Vector3d normal_vector = cross(tri2 - tri1, tri3 - tri1);
  normal_vector = normal_vector / abs(normal_vector);
  double dist1 = dot(seg.p[1] - seg.p[0], normal_vector);
  double dist2 = dot(tri1 - seg.p[0], normal_vector);
  double t = dist2 / dist1;
  Point3d e = (seg.p[1] - seg.p[0]) / abs(seg.p[1] - seg.p[0]);
  return seg.p[0] + e * t;
}

// ... Main function ...