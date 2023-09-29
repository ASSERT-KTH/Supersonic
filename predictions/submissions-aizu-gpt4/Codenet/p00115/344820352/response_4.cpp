#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

class Point3d {
public:
  double x, y, z;
  Point3d(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}
  Point3d operator+(const Point3d &a) const { return Point3d(x + a.x, y + a.y, z + a.z); }
  Point3d operator-(const Point3d &a) const { return Point3d(x - a.x, y - a.y, z - a.z); }
  double operator*(const Point3d &a) const { return x * a.x + y * a.y + z * a.z; }
  Point3d operator*(const double &d) const { return Point3d(x * d, y * d, z * d); }
  Point3d operator/(const double &d) const { return Point3d(x / d, y / d, z / d); }
  bool operator==(const Point3d &a) const { return x == a.x && y == a.y && z == a.z; }
  double abs() const { return sqrt(*this * *this); }
};

Point3d cross(const Point3d &a, const Point3d &b) {
  return Point3d(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
}

class Plane3d {
public:
  Point3d normal_vector;
  double d;
  Plane3d(const Point3d &a, const Point3d &b, const Point3d &c) {
    normal_vector = cross(b - a, c - a) / cross(b - a, c - a).abs();
    d = normal_vector * a;
  }
  double distanceP(const Point3d &p) const {
    return abs(dot(p - normal_vector * d, normal_vector));
  }
  bool intersectS(const Point3d &a, const Point3d &b) const {
    double res1 = dot(normal_vector * d - a, normal_vector);
    double res2 = dot(normal_vector * d - b, normal_vector);
    if (res1 > res2) swap(res1, res2);
    return (res1 <= 0 && 0 <= res2);
  }
  Point3d crosspointS(const Point3d &a, const Point3d &b) const {
    return a + (b - a) * (d - normal_vector * a) / (normal_vector * (b - a));
  }
};

bool point_on_the_triangle3d(const Point3d &tri1, const Point3d &tri2, const Point3d &tri3, const Point3d &p) {
  double area = cross(tri2 - tri1, tri3 - tri1).abs();
  double area1 = cross(p - tri1, tri2 - p).abs();
  double area2 = cross(p - tri2, tri3 - p).abs();
  double area3 = cross(p - tri3, tri1 - p).abs();
  return area == area1 + area2 + area3;
}

int main() {
  Point3d S, G, tri[3];
  cin >> S.x >> S.y >> S.z;
  cin >> G.x >> G.y >> G.z;
  for (int i = 0; i < 3; i++) cin >> tri[i].x >> tri[i].y >> tri[i].z;
  Plane3d plane(tri[0], tri[1], tri[2]);
  if (!plane.intersectS(S, G)) {
    cout << "MISS" << endl;
    return 0;
  }
  Point3d cp = plane.crosspointS(S, G);
  cout << (point_on_the_triangle3d(tri[0], tri[1], tri[2], cp) ? "HIT" : "MISS") << endl;
  return 0;
}