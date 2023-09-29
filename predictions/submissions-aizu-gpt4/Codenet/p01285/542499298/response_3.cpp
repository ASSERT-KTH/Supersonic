#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cassert>
#define REP(i, s, n) for (int i = s; i < n; i++)
#define rep(i, n) REP(i, 0, n)
#define EPS 1e-10
#define COUNTER_CLOCKWISE 1
#define CLOCKWISE -1
#define ONLINE_BACK 2
#define ONLINE_FRONT -2
#define ON_SEGMENT 0
using namespace std;

struct Point {
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}
    Point operator+(Point p) { return Point(x + p.x, y + p.y); }
    Point operator-(Point p) { return Point(x - p.x, y - p.y); }
    Point operator*(double a) { return Point(a * x, a * y); }
    Point operator/(double a) { return Point(x / a, y / a); }
    bool operator<(const Point &p) const {
        return fabs(x - p.x) < EPS ? y < p.y : x < p.x;
    }
    bool operator==(const Point &p) const {
        return fabs(x - p.x) < EPS && fabs(y - p.y) < EPS;
    }
};

struct Segment {
    Point p1, p2;
    Segment(Point p1 = Point(), Point p2 = Point()) : p1(p1), p2(p2) {}
};

typedef Point Vector;
typedef Segment Line;
typedef vector<Point> Polygon;

double norm(Point a) { return a.x * a.x + a.y * a.y; }
double abs(Point a) { return sqrt(norm(a)); }
double cross(Point a, Point b) { return a.x * b.y - a.y * b.x; }
double dot(Point a, Point b) { return a.x * b.x + a.y * b.y; }

int ccw(Point p0, Point p1, Point p2) {
    Point a = p1 - p0;
    Point b = p2 - p0;
    if (cross(a, b) > EPS) return COUNTER_CLOCKWISE;
    if (cross(a, b) < -EPS) return CLOCKWISE;
    if (dot(a, b) < -EPS) return ONLINE_BACK;
    if (norm(a) < norm(b)) return ONLINE_FRONT;
    return ON_SEGMENT;
}

bool intersectSS(Line s, Line t) {
    return ccw(s.p1, s.p2, t.p1) * ccw(s.p1, s.p2, t.p2) <= 0 && ccw(t.p1, t.p2, s.p1) * ccw(t.p1, t.p2, s.p2) <= 0;
}

Point crosspoint(Line l, Line m) {
    double A = cross(l.p2 - l.p1, m.p2 - m.p1);
    double B = cross(l.p2 - l.p1, l.p2 - m.p1);
    if (abs(A) < EPS && abs(B) < EPS) return m.p1;
    return m.p1 + (m.p2 - m.p1) * (B / A);
}

int main() {
    int n;
    while (cin >> n, n) {
        vector<Line> L(n);
        for (int i = 0; i < n; i++) cin >> L[i].p1.x >> L[i].p1.y >> L[i].p2.x >> L[i].p2.y;
        vector<Point> P;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (intersectSS(L[i], L[j])) {
                    P.push_back(crosspoint(L[i], L[j]));
                }
            }
        }
        sort(P.begin(), P.end());
        P.erase(unique(P.begin(), P.end()), P.end());
        for (Point &p : P) {
            bool f = true;
            for (Line &l : L) {
                double d1 = abs(l.p1 - l.p2), d2 = abs(l.p1 - p) + abs(l.p2 - p);
                if (abs(d1 - d2) > EPS) { f = false; break; }
            }
            if (f) { printf("%.10f %.10f\n", p.x, p.y); return 0; }
        }
        puts("None");
    }
    return 0;
}