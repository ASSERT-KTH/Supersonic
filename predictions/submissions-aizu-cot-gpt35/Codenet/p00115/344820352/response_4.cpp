#include <iostream>
#include <cmath>

class Point3d {
public:
  double x, y, z;
  
  Point3d(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}
  
  Point3d operator+(const Point3d& a) {
    return Point3d(x + a.x, y + a.y, z + a.z);
  }
  
  Point3d operator-(const Point3d& a) {
    return Point3d(x - a.x, y - a.y, z - a.z);
  }
  
  Point3d operator*(const double& d) {
    return Point3d(x * d, y * d, z * d);
  }
  
  Point3d operator/(const double& d) {
    return Point3d(x / d, y / d, z / d);
  }
  
  bool operator<(const Point3d& p) const {
    return (x != p.x) ? x < p.x : ((y != p.y) ? y < p.y : z < p.z);
  }
  
  bool operator==(const Point3d& p) const {
    return (x == p.x) && (y == p.y) && (z == p.z);
  }
};

class Segment3d {
public:
  Point3d p[2];
  
  Segment3d(Point3d p1 = Point3d(), Point3d p2 = Point3d()) {
    p[0] = p1;
    p[1] = p2;
  }
  
  bool operator==(const Segment3d& seg) const {
    return (p[0] == seg.p[0]) && (p[1] == seg.p[1]);
  }
};

class Plane3d {
public:
  Point3d normal_vector;
  double d;
  
  Plane3d(Point3d normal_vector = Point3d(), double d = 0)
    : normal_vector(normal_vector), d(d) {}
  
  Plane3d(Point3d a, Point3d b, Point3d c) {
    normal_vector = cross(b - a, c - a);
    normal_vector = normal_vector / abs(normal_vector);
    set_d(a);
  }
  
  void set_d(Point3d p) {
    d = dot(normal_vector, p);
  }
  
  double distanceP(Point3d p) {
    Point3d a = normal_vector * d;
    return abs(dot(p - a, normal_vector));
  }
  
  Point3d nearest_point(Point3d p) {
    Point3d a = normal_vector * d;
    return p - (normal_vector * dot(p - a, normal_vector));
  }
  
  bool intersectS(Segment3d seg) {
    Point3d a = normal_vector * d;
    double res1 = dot(a - seg.p[0], normal_vector);
    double res2 = dot(a - seg.p[1], normal_vector);
    return (res1 * res2 < 0);
  }
  
  Point3d crosspointS(Segment3d seg) {
    Point3d a = normal_vector * d;
    double dot_p0a = fabs(dot(seg.p[0] - a, normal_vector));