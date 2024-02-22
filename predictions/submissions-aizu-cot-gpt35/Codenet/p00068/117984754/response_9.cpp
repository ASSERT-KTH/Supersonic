#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct Point {
    double x, y;
    Point(double _x = 0, double _y = 0) : x(_x), y(_y) {}
};

bool cmp_x(const Point &p, const Point &q) {
    if (p.x != q.x)
        return p.x < q.x;
    return p.y < q.y;
}

vector<Point> convex_hull(vector<Point> &points) {
    int n = points.size();
    sort(points.begin(), points.end(), cmp_x);
    int k = 0;
    vector<Point> hull(2 * n);
    for (int i = 0; i < n; i++) {
        while (k > 1 && (hull[k - 1].x - hull[k - 2].x) * (points[i].y - hull[k - 1].y) - (hull[k - 1].y - hull[k - 2].y) * (points[i].x - hull[k - 1].x) <= 0)
            k--;
        hull[k++] = points[i];
    }
    for (int i = n - 2, t = k; i >= 0; i--) {
        while (k > t && (hull[k - 1].x - hull[k - 2].x) * (points[i].y - hull[k - 1].y) - (hull[k - 1].y - hull[k - 2].y) * (points[i].x - hull[k - 1].x) <= 0)
            k--;
        hull[k++] = points[i];
    }
    hull.resize(k - 1);
    return hull;
}

int main() {
    int N;
    while (cin >> N && N) {
        vector<Point> points(N);
        for (int i = 0; i < N; i++) {
            char ch;
            cin >> points[i].x >> ch >> points[i].y;
        }
        vector<Point> hull = convex_hull(points);
        cout << N - hull.size() << endl;
    }
    return 0;
}