#include <cmath>
#include <iostream>
#include <string>
#define REP(i, s, n) for (int i = s; i < n; i++)
#define rep(i, n) REP(i, 0, n)
#define IINF (INT_MAX)
#define EPS (1e-9)
#define equals(a, b) (fabs((a) - (b)) < EPS)

struct Point3d {
  double x, y, z;
  Point3d(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}
  Point3d operator+(const Point3d &a) const {
    return Point3d(x + a.x, y + a.y, z + a.z);
  }
  Point3d operator-(const Point3d &a) const {
    return Point3d(x - a.x, y - a.y, z - a.z);
  }
  Point3d operator*(double d) const { return Point3d(x * d, y * d, z * d); }
  Point3d operator/(double d) const { return Point3d(x / d, y / d, z / d); }
  bool operator<(const Point3d &p) const {
    return !equals(x, p.x) ? x < p.x : ((!equals(y, p.y)) ? y < p.y : z < p.z);
  }
  bool operator==(const Point3d &p) const {
    return equals(x, p.x) && equals(y, p.y) && equals(z, p.z);
  }
};

using Vector3d = Point3d;

struct Segment3d {
  Point3d p[2];
  Segment3d(Point3d p1 = Point3d(), Point3d p2 = Point3d()) {
    p[0] = p1, p[1] = p2;
  }
};

inline double norm(const Point3d &p) { return p.x * p.x + p.y * p.y + p.z * p.z; }
inline double abs(const Point3d &p) { return sqrt(norm(p)); }
inline double dot(const Point3d &a, const Point3d &b) { return a.x * b.x + a.y * b.y + a.z * b.z; }
inline Vector3d cross(const Point3d &a, const Point3d &b) { return Vector3d(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x); }

bool point_on_the_segment3d(Segment3d seg, Point3d p) {
  double dist[3] = {abs(seg.p[1] - seg.p[0]), abs(p - seg.p[0]), abs(p - seg.p[1])};
  return equals(dist[0], dist[1] + dist[2]);
}

bool point_on_the_triangle3d(Point3d tri1, Point3d tri2, Point3d tri3, Point3d p) {
  Vector3d v1 = tri2 - tri1;
  Vector3d v2 = tri3 - tri2;
  Vector3d v3 = tri1 - tri3;
  Vector3d cp[3] = {cross(v1, p - tri1), cross(v2, p - tri2), cross(v3, p - tri3)};
  double d1 = dot(cp[0], cp[1]);
  double d2 = dot(cp[0], cp[2]);
  if (d1 >= 0 && d2 >= 0) return true;
  return point_on_the_segment3d(Segment3d(tri1, tri2), p) || point_on_the_segment3d(Segment3d(tri2, tri3), p) || point_on_the_segment3d(Segment3d(tri3, tri1), p);
}

class Plane3d {
public:
  Point3d normal_vector;
  double d;
  Plane3d(Point3d normal_vector = Point3d(), double d = 0)
      : normal_vector(normal_vector), d(d) {}
  Plane3d(Vector3d a, Vector3d b, Vector3d c) {
    Vector3d v1 = b - a;
    Vector3d v2 = c - a;
    Vector3d tmp = cross(v1, v2);
    normal_vector = tmp / abs(tmp);
    set_d(a);
  }
  void set_d(Point3d p) { d = dot(normal_vector, p); }
  Point3d crosspointS(Segment3d seg) {
    Point3d a = normal_vector * d;
    double dot_p0a = fabs(dot(seg.p[0] - a, normal_vector));
    double dot_p1a = fabs(dot(seg.p[1] - a, normal_vector));
    return seg.p[0] + (seg.p[1] - seg.p[0]) * (dot_p0a / (dot_p0a + dot_p1a));
  }
};

int main() {
  Point3d tri[3], S, G;
  std::cin >> S.x >> S.y >> S.z >> G.x >> G.y >> G.z;
  for (auto &i : tri) std::cin >> i.x >> i.y >> i.z;
  Plane3d plane(tri[0], tri[1], tri[2]);
  Segment3d seg(S, G);
  Point3d cp = plane.crosspointS(seg);
  std::cout << (point_on_the_triangle3d(tri[0], tri[1], tri[2], cp) ? "MISS" : "HIT") << std::endl;
  return 0;
}