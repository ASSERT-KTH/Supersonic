#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

class Point {
public:
    double x, y;
    
    Point(double _x = 0, double _y = 0) : x(_x), y(_y) {}
    
    Point operator+(const Point& p) const {
        return Point(x + p.x, y + p.y);
    }
    
    Point operator-(const Point& p) const {
        return Point(x - p.x, y - p.y);
    }
    
    Point operator*(double k) const {
        return Point(x * k, y * k);
    }
    
    Point operator/(double k) const {
        return Point(x / k, y / k);
    }
    
    bool operator==(const Point& p) const {
        return (fabs(x - p.x) < EPS && fabs(y - p.y) < EPS);
    }
    
    double norm() const {
        return x * x + y * y;
    }
    
    double abs() const {
        return sqrt(norm());
    }
};

class Line {
public:
    Point p1, p2;
    
    Line(const Point& _p1, const Point& _p2) : p1(_p1), p2(_p2) {}
};

class Polygon {
public:
    std::vector<Point> points;
    
    size_t size() const {
        return points.size();
    }
    
    void push_back(const Point& p) {
        points.push_back(p);
    }
    
    const Point& operator[](size_t index) const {
        return points[index];
    }
};

double dot(const Point& a, const Point& b) {
    return a.x * b.x + a.y * b.y;
}

double cross(const Point& a, const Point& b) {
    return a.x * b.y - a.y * b.x;
}

double distance_l_p(const Line& l, const Point& p) {
    return fabs(cross(l.p2 - l.p1, p - l.p1)) / (l.p2 - l.p1).abs();
}

int ccw(const Point& p0, const Point& p1, const Point& p2) {
    Point a = p1 - p0;
    Point b = p2 - p0;
    if (cross(a, b) > EPS)
        return 1;
    if (cross(a, b) < -EPS)
        return -1;
    if (dot(a, b) < -EPS)
        return 2;
    if (a.norm() < b.norm())
        return -2;
    return 0;
}

bool intersect(const Point& p1, const Point& p2, const Point& p3, const Point& p4) {
    return (ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 &&
            ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0);
}

bool isSimple(const Polygon& pol) {
    size_t pol_size = pol.size() - 1;
    for (size_t i = 0; i < pol_size; i++) {
        for (size_t j = i + 2; j < pol_size; j++) {
            if (i == j || i == (j - 1 + pol_size) % pol_size ||
                i == (j + 1 + pol_size) % pol_size)
                continue;
            if (intersect(pol[i], pol[i + 1], pol[j], pol[j + 1]))
                return false;
        }
    }
    return true;
}

bool isPointInsidePolygon(const Polygon& side, const Point& p) {
    int c = 0, sideSum = side.size();
    for (size_t i = 0; i < sideSum; i++) {
        if (cross(side[i].p2 - side[i].p1, p - side[i].p1) > 0)
            c++;
    }
    return !(c % sideSum);
}

#define MAX_N 100

bool cmp_x(const Point& p, const Point& q) {
    if (p.x != q.x)
        return p.x < q.x;
    return p.y < q.y;
}

Polygon convex_hull(const Point* ps, int n) {
    std::vector<Point> qs(n * 2);
    std::sort(ps, ps + n, cmp_x);
    int k = 0;
    for (int i = 0; i < n; i++) {
        while (k > 1 && cross((qs[k - 1] - qs[k - 2]), (ps[i] - qs[k - 1])) <= 0)
            k--;
        qs[k++] = ps[i];
    }
    for (int i = n - 2, t = k; i >= 0; i--) {
        while (k > t && cross((qs[k - 1] - qs[k - 2]), (ps[i] - qs[k - 1])) <= 0)
            k--;
        qs[k++] = ps[i];
    }
    qs.resize(k - 1);
    Polygon res;
    res.points = std::move(qs);
    return res;
}

int main() {
    int N;
    while (std::cin >> N && N) {
        Point ps[MAX_N];
        for (int i = 0; i < N; i++) {
            char ch;
            std::cin >> ps[i].x >> ch >> ps[i].y;
        }
        Polygon res = convex_hull(ps, N);
        std::cout << N - res.size() << std::endl;
    }
}