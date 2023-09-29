#include <iostream>
#include <cmath>
#include <array>

constexpr double EPS = 1e-7;

struct Point3d {
  double x, y, z;
  
  inline Point3d operator-(const Point3d &p) const {
    return {x - p.x, y - p.y, z - p.z};
  }
  inline Point3d operator*(double d) const {
    return {x * d, y * d, z * d};
  }
};

struct Plane3d {
  Point3d normal_vector;
  double d;
  
  Plane3d(const Point3d& a, const Point3d& b, const Point3d& c) {
    Point3d v1 = b - a;
    Point3d v2 = c - a;
    normal_vector = cross(v1, v2);
    double norm = std::sqrt(dot(normal_vector, normal_vector));
    normal_vector = normal_vector * (1.0 / norm);
    d = dot(normal_vector, a);
  }

  inline bool intersectS(const Point3d& p1, const Point3d& p2) const {
    double res1 = dot(p1 - normal_vector * d, normal_vector);
    double res2 = dot(p2 - normal_vector * d, normal_vector);
    return res1 * res2 <= 0;
  }

  inline Point3d crosspointS(const Point3d& p1, const Point3d& p2) const {
    double t = dot(normal_vector * d - p1, normal_vector) / dot(p2 - p1, normal_vector);
    return {p1.x + (p2.x - p1.x) * t, p1.y + (p2.y - p1.y) * t, p1.z + (p2.z - p1.z) * t};
  }

private:
  inline static Point3d cross(const Point3d& a, const Point3d& b) {
    return {a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x};
  }
  
  inline static double dot(const Point3d& a, const Point3d& b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
  }
};

bool point_on_the_triangle3d(const Point3d& p, const std::array<Point3d, 3>& tri) {
  Point3d cp[3] = {cross(tri[1] - tri[0], p - tri[0]), cross(tri[2] - tri[1], p - tri[1]), cross(tri[0] - tri[2], p - tri[2])};
  double d1 = dot(cp[0], cp[1]);
  double d2 = dot(cp[0], cp[2]);
  return d1 > -EPS && d2 > -EPS;
}

inline static Point3d cross(const Point3d& a, const Point3d& b) {
  return {a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x};
}

inline static double dot(const Point3d& a, const Point3d& b) {
  return a.x * b.x + a.y * b.y + a.z * b.z;
}

int main() {
  Point3d S, G;
  std::array<Point3d, 3> tri;
  std::cin >> S.x >> S.y >> S.z >> G.x >> G.y >> G.z;
  for(int i = 0; i < 3; ++i)
    std::cin >> tri[i].x >> tri[i].y >> tri[i].z;

  Plane3d plane(tri[0], tri[1], tri[2]);
  if (!plane.intersectS(S, G)) {
    std::cout << "HIT\n";
    return 0;
  }

  Point3d cp = plane.crosspointS(S, G);
  std::cout << (point_on_the_triangle3d(cp, tri) ? "MISS\n" : "HIT\n");
  return 0;
}