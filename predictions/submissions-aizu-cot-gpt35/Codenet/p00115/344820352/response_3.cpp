#include <iostream>
#include <cmath>

using namespace std;

class Point3d {
public:
    double x, y, z;
    Point3d(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}
};

class Plane3d {
public:
    Point3d normal_vector;
    double d;
    Plane3d(Point3d normal_vector = Point3d(), double d = 0)
        : normal_vector(normal_vector), d(d) {}
    double distanceP(Point3d p) {
        Point3d a = normal_vector * d;
        return abs((p - a).x * normal_vector.x +
                   (p - a).y * normal_vector.y +
                   (p - a).z * normal_vector.z);
    }
    Point3d nearest_point(Point3d p) {
        Point3d a = normal_vector * d;
        return p - (normal_vector * ((p - a).x * normal_vector.x +
                                     (p - a).y * normal_vector.y +
                                     (p - a).z * normal_vector.z));
    }
    bool intersectS(Point3d p1, Point3d p2) {
        Point3d a = normal_vector * d;
        double res1 = (a - p1).x * normal_vector.x +
                      (a - p1).y * normal_vector.y +
                      (a - p1).z * normal_vector.z;
        double res2 = (a - p2).x * normal_vector.x +
                      (a - p2).y * normal_vector.y +
                      (a - p2).z * normal_vector.z;
        if (res1 > res2)
            swap(res1, res2);
        if ((res1 == 0.0 || res1 < 0) && (res2 == 0.0 || res2 > 0))
            return true;
        return false;
    }
    Point3d crosspointS(Point3d p1, Point3d p2) {
        Point3d a = normal_vector * d;
        double dot_p0a = fabs((p1 - a).x * normal_vector.x +
                              (p1 - a).y * normal_vector.y +
                              (p1 - a).z * normal_vector.z);
        double dot_p1a = fabs((p2 - a).x * normal_vector.x +
                              (p2 - a).y * normal_vector.y +
                              (p2 - a).z * normal_vector.z);
        if (dot_p0a + dot_p1a == 0)
            return p1;
        return p1 + (p2 - p1) * (dot_p0a / (dot_p0a + dot_p1a));
    }
};

bool point_on_the_triangle3d(Point3d tri1, Point3d tri2, Point3d tri3,
                             Point3d p) {
    if ((p - tri1).x * (tri2 - tri1).x +
            (p - tri1).y * (tri2 - tri1).y +
            (p - tri1).z * (tri2 - tri1).z == 0 &&
        (p - tri1).x * (tri3 - tri1).x +
            (p - tri1).y * (tri3 - tri1).y +
            (p - tri1).z * (tri3 - tri1).z == 0)
        return true;
    if ((p - tri2).x * (tri1 - tri2).x +
            (p - tri2).y * (tri1 - tri2).y +
            (p - tri2).z * (tri1 - tri2).z == 0 &&
        (p - tri2).x * (tri3 - tri2).x +
            (p - tri2).y * (tri3 - tri2).y +
            (p - tri2).z * (tri3 - tri2).z == 0)
        return true;
    if ((p - tri3).x * (tri1 - tri3).x +
            (p - tri3).y * (tri1 - tri3).y +
            (p - tri3).z * (tri1 - tri3).z == 0 &&
        (p - tri3).x * (tri2 - tri3).x +