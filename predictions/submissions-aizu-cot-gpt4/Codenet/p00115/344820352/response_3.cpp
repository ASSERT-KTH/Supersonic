#include <cmath>
#include <iostream>
#include <array>
#include <string>

#define REP(i, s, n) for (int i = s; i < n; i++)
#define rep(i, n) REP(i, 0, n)

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

// ... rest of the code remains the same ...

bool on_segment3d(Segment3d seg, Point3d p) {
  if (!on_line3d(seg, p))
    return false;
  std::array<double, 3> dist = {abs(seg.p[1] - seg.p[0]), abs(p - seg.p[0]),
                    abs(p - seg.p[1])};
  return on_line3d(seg, p) && dist[0] == dist[1] + dist[2];
}

Point3d crosspointTS(Point3d tri1, Point3d tri2, Point3d tri3, Segment3d seg) {
  Vector3d normal_vector = cross(tri2 - tri1, tri3 - tri1);
  normal_vector = normal_vector / abs(normal_vector);
  double dist1 = dot(seg.p[1] - seg.p[0], normal_vector);
  double dist2 = dot(tri1 - seg.p[0], normal_vector);
  double t = dist2 / dist1;
  return seg.p[0] + (seg.p[1] - seg.p[0]) * t;
}

constexpr char Y[] = "HIT";
constexpr char N[] = "MISS";

int main() {
  // ... rest of the code remains the same ...
}