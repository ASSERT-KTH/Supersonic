#include <iostream>
#include <cmath>
#include <vector>
#define REP(i, s, n) for (int i = s; i < n; i++)
#define rep(i, n) REP(i, 0, n)
#define IINF (INT_MAX)
#define EPS (1e-7)
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
    double diff_x = fabs(x - p.x);
    double diff_y = fabs(y - p.y);
    return diff_x > EPS ? x < p.x : (diff_y > EPS ? y < p.y : z < p.z);
  }
  bool operator==(const Point3d &p) const {
    double diff_x = fabs(x - p.x);
    double diff_y = fabs(y - p.y);
    double diff_z = fabs(z - p.z);
    return diff_x < EPS && diff_y < EPS && diff_z < EPS;
  }
};

// ... rest of the code ...
// replace 'equals' with 'diff_x', 'diff_y', 'diff_z'
// replace 'dot' with 'dot_product'
// replace 'abs' with 'magnitude'
// replace 'cross' with 'cross_product'