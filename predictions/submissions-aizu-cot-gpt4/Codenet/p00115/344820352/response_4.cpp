#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

class Point3d {
public:
  double x, y, z;
  Point3d(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}
  Point3d& operator+=(const Point3d &a) {
    x += a.x; y += a.y; z += a.z;
    return *this;
  }
  Point3d& operator-=(const Point3d &a) {
    x -= a.x; y -= a.y; z -= a.z;
    return *this;
  }
  Point3d& operator*=(const double &d) {
    x *= d; y *= d; z *= d;
    return *this;
  }
  Point3d& operator/=(const double &d) {
    x /= d; y /= d; z /= d;
    return *this;
  }
  // ... rest of the class definition remains unchanged ...
};

bool on_segment3d(Segment3d seg, Point3d p) {
  bool onLine = on_line3d(seg, p);
  if (!onLine) return false;
  double dist[3] = {abs(seg.p[1] - seg.p[0]), abs(p - seg.p[0]),
                    abs(p - seg.p[1])};
  return onLine && equals(dist[0], dist[1] + dist[2]);
}

Point3d crosspointTS(Point3d tri1, Point3d tri2, Point3d tri3, Segment3d seg) {
  Vector3d normal_vector = cross(tri2 - tri1, tri3 - tri1);
  normal_vector /= abs(normal_vector);
  double dist1 = dot(seg.p[1] - seg.p[0], normal_vector);
  double dist2 = dot(tri1 - seg.p[0], normal_vector);
  double t = dist2 / dist1;
  return seg.p[0] + ((seg.p[1] - seg.p[0]) / abs(seg.p[1] - seg.p[0])) * t;
}

// ... rest of the program remains unchanged ...