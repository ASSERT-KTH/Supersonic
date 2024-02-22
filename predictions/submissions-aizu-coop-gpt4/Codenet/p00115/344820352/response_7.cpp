#include <iostream>
#include <cmath>
#include <string>

using namespace std;

inline bool equals(double a, double b) {
  const double EPS = 1e-7;
  return fabs(a - b) < EPS;
}

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
    return !equals(x, p.x) ? x < p.x : (!equals(y, p.y) ? y < p.y : z < p.z);
  }
  bool operator==(const Point3d &p) const {
    return equals(x, p.x) && equals(y, p.y) && equals(z, p.z);
  }
};

// ...rest of the code...

inline double norm(const Point3d &p) {
  return p.x * p.x + p.y * p.y + p.z * p.z;
}

inline double abs(const Point3d &p) {
  return sqrt(norm(p));
}

// ...rest of the code...

int main() {
  // ...rest of the code...
  for (++i; i < n; ++i) {
    // ...rest of the code...
  }
  // ...rest of the code...
  return 0;
}