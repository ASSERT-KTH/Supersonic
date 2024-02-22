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

// More code here...

double dot(const Point3d &a, const Point3d &b) {
  return a.x * b.x + a.y * b.y + a.z * b.z;
}

// More code here...

bool on_line3d(const Line3d &line, const Point3d &p) {
  return equals(abs(cross(p - line.p[0], line.p[1] - line.p[0])), 0);
}

// More code here...

int main() {
  Point3d tri[3], S, G;
  cin >> S.x >> S.y >> S.z;
  cin >> G.x >> G.y >> G.z;
  rep(i, 3) cin >> tri[i].x >> tri[i].y >> tri[i].z;
  Plane3d plane(tri[0], tri[1], tri[2]);
  Segment3d seg(S, G);
  if (!plane.intersectS(seg)) {
    cout << Y << "\n";
    return 0;
  }
  Point3d cp = plane.crosspointS(seg);
  cout << (point_on_the_triangle3d(tri[0], tri[1], tri[2], cp) ? N : Y) << "\n";
  return 0;
}