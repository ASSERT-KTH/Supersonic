#include <iostream>
#include <cmath>

using namespace std;

class Point3d {
public:
  double x, y, z;
  
  Point3d(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}
  
  Point3d operator+(const Point3d& a) const {
    return Point3d(x + a.x, y + a.y, z + a.z);
  }
  
  Point3d operator-(const Point3d& a) const {
    return Point3d(x - a.x, y - a.y, z - a.z);
  }
  
  Point3d operator*(const double& d) const {
    return Point3d(x * d, y * d, z * d);
  }
  
  Point3d operator/(const double& d) const {
    return Point3d(x / d, y / d, z / d);
  }
  
  bool operator<(const Point3d& p) const {
    return (x != p.x) ? x < p.x : ((y != p.y) ? y < p.y : z < p.z);
  }
  
  bool operator==(const Point3d& p) const {
    return (x == p.x) && (y == p.y) && (z == p.z);
  }
};

struct Segment3d {
  Point3d p[2];
  
  Segment3d(Point3d p1 = Point3d(), Point3d p2 = Point3d()) {
    p[0] = p1;
    p[1] = p2;
  }
  
  bool operator==(const Segment3d& seg) const {
    return p[0] == seg.p[0] && p[1] == seg.p[1];
  }
};

class Plane3d {
public:
  Point3d normal_vector;
  double d;
  
  Plane3d(Point3d normal_vector = Point3d(), double d = 0)
    : normal_vector(normal_vector), d(d) {}
  
  Plane3d(Point3d a, Point3d b, Point3d c) {
    Point3d v1 = b - a;
    Point3d v2 = c - a;
    Point3d tmp = cross(v1, v2);
    normal_vector = tmp / abs(tmp);
    set_d(a);
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
    return ((res1 <= 0) && (res2 >= 0)) || ((res1 >= 0) && (res2 <= 0));
  }
  
  Point3d crosspointS(Segment3d seg) {
    Point3d a = normal_vector * d;
    double dot_p0a = fabs(dot(seg.p[0] - a, normal_vector));
    double dot_p1a = fabs(dot(seg.p[1] - a, normal_vector));
    return seg.p[0] + (seg.p[1] - seg.p[0]) * (dot_p0a / (dot_p0a + dot_p1a));
  }

private:
  void set_d(Point3d p) {
    d = dot(normal_vector, p);
  }
  
  double dot(const Point3d& a, const Point3d& b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
  }
  
  Point3d cross(const Point3d& a, const Point3d& b) {
    return Point3d(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z,
                   a.x * b.y - a.y * b.x);
  }
  
  inline double abs(const Point3d& p) {
    return sqrt(p.x * p.x + p.y * p.y + p.z * p.z);
  }
};

const string Y = "HIT", N = "MISS";

int main() {
  Point3d tri[3], S, G;
  cin >> S.x >> S.y >> S.z;
  cin >> G.x >> G.y >> G.z;
  for (int i = 0; i < 3; i++) {
    cin >> tri[i].x >> tri[i].y >> tri[i].z;
  }
  Plane3d plane(tri[0], tri[1], tri[2]);
  Segment3d seg(S, G);
  if (!plane.intersectS(seg)) {
    cout << Y << endl;
    return 0;
  }
  Point3d cp = plane.crosspointS(seg);