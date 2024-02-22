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
  Point3d& operator+=(const Point3d &a) {
    x += a.x;
    y += a.y;
    z += a.z;
    return *this;
  }
  Point3d& operator-=(const Point3d &a) {
    x -= a.x;
    y -= a.y;
    z -= a.z;
    return *this;
  }
  Point3d& operator*=(const double &d) {
    x *= d;
    y *= d;
    z *= d;
    return *this;
  }
  Point3d& operator/=(const double &d) {
    x /= d;
    y /= d;
    z /= d;
    return *this;
  }
  bool operator<(const Point3d &p) const {
    return !equals(x, p.x) ? x < p.x : ((!equals(y, p.y)) ? y < p.y : z < p.z);
  }
  bool operator==(const Point3d &p) const {
    return equals(x, p.x) && equals(y, p.y) && equals(z, p.z);
  }
};

// ... Rest of the code remains unchanged ...

bool point_on_the_triangle3d(Segment3d seg1, Segment3d seg2, Segment3d seg3, Point3d p) {
  if (on_segment3d(seg1, p))
    return true;
  if (on_segment3d(seg2, p))
    return true;
  if (on_segment3d(seg3, p))
    return true;
  Vector3d v1 = seg1.p[1] - seg1.p[0];
  Vector3d v2 = seg2.p[1] - seg2.p[0];
  Vector3d v3 = seg3.p[1] - seg3.p[0];
  Vector3d cp1 = cross(v1, p - seg1.p[0]);
  Vector3d cp2 = cross(v2, p - seg2.p[0]);
  Vector3d cp3 = cross(v3, p - seg3.p[0]);
  double d1 = dot(cp1, cp2);
  double d2 = dot(cp1, cp3);
  if ((d1 == 0.0 || d1 > 0) && (d2 == 0.0 || d2 > 0))
    return true;
  return false;
}

// ... Rest of the code remains unchanged ...