#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>

#define EPS (1e-7)

using namespace std;

class Point3d {
public:
  double x, y, z;
  Point3d(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}
  Point3d operator+(const Point3d &a) const { return Point3d(x + a.x, y + a.y, z + a.z); }
  Point3d operator-(const Point3d &a) const { return Point3d(x - a.x, y - a.y, z - a.z); }
  Point3d operator*(const double &d) const { return Point3d(x * d, y * d, z * d); }
  Point3d operator/(const double &d) const { return Point3d(x / d, y / d, z / d); }
};

using Vector3d = Point3d;

double dot(const Point3d &a, const Point3d &b) { return a.x * b.x + a.y * b.y + a.z * b.z; }

Vector3d cross(const Point3d &a, const Point3d &b) {
  return Vector3d(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
}

double abs(const Point3d &p) { return sqrt(p.x * p.x + p.y * p.y + p.z * p.z); }

class Plane3d {
public:
  Point3d normal_vector;
  double d;
  Plane3d(Vector3d a, Vector3d b, Vector3d c) {
    Vector3d tmp = cross(b - a, c - a);
    normal_vector = tmp / abs(tmp);
    set_d(a);
  }
  void set_d(Point3d p) { d = dot(normal_vector, p); }
  bool intersectS(Point3d p1, Point3d p2) const {
    double res1 = dot(normal_vector * d - p1, normal_vector);
    double res2 = dot(normal_vector * d - p2, normal_vector);
    if (res1 > res2) swap(res1, res2);
    return (res1 < EPS || abs(res1) < EPS) && (res2 > -EPS || abs(res2) < EPS);
  }
  Point3d crosspointS(Point3d p1, Point3d p2) const {
    return p1 + (p2 - p1) * (abs(dot(normal_vector * d - p1, normal_vector)) / abs(dot(p2 - p1, normal_vector)));
  }
};

bool point_on_the_triangle3d(Point3d tri1, Point3d tri2, Point3d tri3, Point3d p) {
  Vector3d cp[3] = {cross(tri2 - tri1, p - tri1), cross(tri3 - tri2, p - tri2), cross(tri1 - tri3, p - tri3)};
  double d1 = dot(cp[0], cp[1]);
  double d2 = dot(cp[0], cp[2]);
  return (d1 > -EPS || abs(d1) < EPS) && (d2 > -EPS || abs(d2) < EPS);
}

int main() {
  Point3d tri[3], S, G;
  cin >> S.x >> S.y >> S.z;
  cin >> G.x >> G.y >> G.z;
  for(auto& t : tri) cin >> t.x >> t.y >> t.z;
  Plane3d plane(tri[0], tri[1], tri[2]);
  if (!plane.intersectS(S, G)) {
    cout << "HIT" << endl;
  }
  else {
    Point3d cp = plane.crosspointS(S, G);
    cout << (point_on_the_triangle3d(tri[0], tri[1], tri[2], cp) ? "MISS" : "HIT") << endl;
  }
  return 0;
}