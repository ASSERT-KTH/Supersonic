#include <bits/stdc++.h>
using namespace std;

struct Point {
    double x, y;
    Point() {}
    Point(double x, double y) : x(x), y(y) {}
    Point operator+(Point p) { return Point(x + p.x, y + p.y); }
    Point operator-(Point p) { return Point(x - p.x, y - p.y); }
    Point operator*(double k) { return Point(x * k, y * k); }
    Point operator/(double k) { return Point(x / k, y / k); }
    double norm() { return x * x + y * y; }
    double abs() { return sqrt(norm()); }
    bool operator<(const Point &p) const { return x != p.x ? x < p.x : y < p.y; }
};

double cross(Point a, Point b) { return a.x * b.y - a.y * b.x; }

vector<Point> convex_hull(vector<Point> ps) {
    int n = ps.size(), k = 0;
    sort(ps.begin(), ps.end());
    vector<Point> qs(n * 2);
    for (int i = 0; i < n; i++) {
        while (k > 1 && cross(qs[k - 1] - qs[k - 2], ps[i] - qs[k - 1]) <= 0)
            k--;
        qs[k++] = ps[i];
    }
    for (int i = n - 2, t = k; i >= 0; i--) {
        while (k > t && cross(qs[k - 1] - qs[k - 2], ps[i] - qs[k - 1]) <= 0)
            k--;
        qs[k++] = ps[i];
    }
    qs.resize(k - 1);
    return qs;
}

double diameter(vector<Point> s) {
    vector<Point> p = convex_hull(s);
    int n = p.size();
    if (n == 2)
        return (p[0] - p[1]).abs();
    int i = 0, j = 0;
    for (int k = 0; k < n; k++) {
        if (p[i] < p[k])
            i = k;
        if (!(p[j] < p[k]))
            j = k;
    }
    double res = 0;
    int si = i, sj = j;
    while (i != sj || j != si) {
        res = max(res, (p[i] - p[j]).abs());
        if (cross(p[(i + 1) % n] - p[i], p[(j + 1) % n] - p[j]) < 0.0) {
            i = (i + 1) % n;
        } else {
            j = (j + 1) % n;
        }
    }
    return res;
}

int main() {
    int n;
    scanf("%d", &n);
    vector<Point> p(n);
    for (int i = 0; i < n; i++)
        scanf("%lf %lf", &p[i].x, &p[i].y);
    printf("%.12f\n", diameter(p));
    return 0;
}