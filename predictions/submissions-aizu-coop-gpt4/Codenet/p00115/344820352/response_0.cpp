#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < n; i++)
#define rep(i, n) REP(i, 0, n)
#define IINF (INT_MAX)
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
    return x != p.x ? x < p.x : (y != p.y ? y < p.y : z < p.z);
  }
  bool operator==(const Point3d &p) const {
    return x == p.x && y == p.y && z == p.z;
  }
};

inline double dot(const Point3d &a, const Point3d &b) {
  return a.x * b.x + a.y * b.y + a.z * b.z;
}

inline Point3d cross(const Point3d &a, const Point3d &b) {
  return Point3d(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
}

inline double norm(const Point3d &p) {
  return p.x * p.x + p.y * p.y + p.z * p.z;
}

inline double abs(const Point3d &p) { return sqrt(norm(p)); }

// Removed unnecessary functions and optimized the remaining code
int main() {
  Point3d tri[3], S, G;
  cin >> S.x >> S.y >> S.z;
  cin >> G.x >> G.y >> G.z;
  rep(i, 3) cin >> tri[i].x >> tri[i].y >> tri[i].z;

  Point3d normal_vector = cross(tri[1] - tri[0], tri[2] - tri[0]);
  normal_vector = normal_vector / abs(normal_vector);
  Point3d a = dot(normal_vector, tri[0]) * normal_vector;
  double dot_p0a = fabs(dot(S - a, normal_vector));
  double dot_p1a = fabs(dot(G - a, normal_vector));

  Point3d cp = S + (G - S) * (dot_p0a / (dot_p0a + dot_p1a));
  double d1 = dot(cross(tri[1] - tri[0], cp - tri[0]), cross(tri[2] - tri[1], cp - tri[1]));
  double d2 = dot(cross(tri[1] - tri[0], cp - tri[0]), cross(tri[0] - tri[2], cp - tri[2]));

  const string Y = "HIT", N = "MISS";
  cout << ((d1 > 0 && d2 > 0) ? N : Y) << endl;

  return 0;
}