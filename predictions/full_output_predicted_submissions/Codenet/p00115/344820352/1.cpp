#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < n; i++)
#define rep(i, n) REP(i, 0, n)
#define IINF (INT_MAX)
#define EPS (1e-7)
#define equals(a, b) (fabs((a) - (b)) < EPS)
using namespace std;
class Point3d {
public:
  int x, y, z;
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
struct Segment3d {
  Point3d p[2];
  Segment3d(Point3d p1 = Point3d(), Point3d p2 = Point3d()) {
    p[0] = p1, p[1] = p2;
  }
  bool operator==(const Segment3d &seg) const {
  