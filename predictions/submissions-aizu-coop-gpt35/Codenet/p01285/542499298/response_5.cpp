#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <cassert>
using namespace std;

const double EPS = 1e-6;

class Point {
public:
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}

    bool operator<(const Point& p) const {
        return x < p.x - EPS || (fabs(x - p.x) < EPS && y < p.y - EPS);
    }

    bool operator==(const Point& p) const {
        return fabs(x - p.x) < EPS && fabs(y - p.y) < EPS;
    }
};

struct Segment {
    Point p1, p2;
    int index;

    Segment(Point p1 = Point(), Point p2 = Point(), int index = -1)
        : p1(p1), p2(p2), index(index) {}

    bool operator<(const Segment& s) const {
        return p2 < s.p2 - EPS || (fabs(p2.x - s.p2.x) < EPS && p1 < s.p1 - EPS);
    }

    bool operator==(const Segment& s) const {
        return (s.p1 == p1 && s.p2 == p2) || (s.p1 == p2 && s.p2 == p1);
    }
};

typedef set<Point> PointSet;
typedef set<Segment> SegmentSet;

double cross(const Point& a, const Point& b) {
    return a.x * b.y - a.y * b.x;
}

bool intersectSS(const Segment& s, const Segment& t) {