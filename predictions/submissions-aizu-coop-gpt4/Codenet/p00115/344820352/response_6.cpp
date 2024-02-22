#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < n; i++)
#define rep(i, n) REP(i, 0, n)
#define IINF (INT_MAX)
#define EPS (1e-7)
#define equals(a, b) (fabs((a) - (b)) < EPS)
using namespace std;

// Same as the original code up to this point

// Inlined abs and norm functions
inline double norm(const Point3d &p) {
  return p.x * p.x + p.y * p.y + p.z * p.z;
}

inline double abs(const Point3d &p) {
  return sqrt(norm(p));
}

// Same as the original code up to this point

double Plane3d::distanceP(Point3d p) {
  Point3d a = normal_vector * d;
  return abs(dot(p - a, normal_vector)); // Eliminated temporary variable
}

bool Plane3d::intersectS(Segment3d seg) {
  Point3d a = normal_vector * d;
  // Stored repeated computations in variables
  Point3d diff0 = a - seg.p[0];
  Point3d diff1 = a - seg.p[1];
  double res1 = dot(diff0, normal_vector);
  double res2 = dot(diff1, normal_vector);
  if (res1 > res2)
    swap(res1, res2);
  if ((equals(res1, 0.0) || res1 < 0) && (equals(res2, 0.0) || res2 > 0))
    return true;
  return false;
}

// Same as the original code up to this point

bool point_on_the_triangle3d(Point3d tri1, Point3d tri2, Point3d tri3, Point3d p) {
  if (on_segment3d(Segment3d(tri1, tri2), p))
    return true;
  if (on_segment3d(Segment3d(tri2, tri3), p))
    return true;
  if (on_segment3d(Segment3d(tri3, tri1), p))
    return true;
  Vector3d v1 = tri2 - tri1;
  Vector3d v2 = tri3 - tri2;
  Vector3d v3 = tri1 - tri3;

  // Stored repeated computations in variables
  Vector3d cp1 = cross(v1, p - tri1);
  Vector3d cp2 = cross(v2, p - tri2);
  Vector3d cp3 = cross(v3, p - tri3);

  double d1 = dot(cp1, cp2);
  double d2 = dot(cp1, cp3);
  if ((!equals(d1, 0.0) && d1 > 0) && (!equals(d2, 0.0) && d2 > 0))
    return true;
  return false;
}

// Rest of the code is the same