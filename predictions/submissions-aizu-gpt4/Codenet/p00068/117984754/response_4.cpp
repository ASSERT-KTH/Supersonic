#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

typedef struct Point {
    double x, y;
} Point;

typedef struct Line {
    Point p1, p2;
} Line;

static const double EPS = 1e-10;

inline double cross(const Point &a, const Point &b) {
    return a.x * b.y - a.y * b.x;
}

inline double dot(const Point &a, const Point &b) {
    return a.x * b.x + a.y * b.y;
}

inline bool cmp_x(const Point &p, const Point &q) {
    if (p.x != q.x)
        return p.x < q.x;
    return p.y < q.y;
}

vector<Point> convex_hull(vector<Point> ps) {
    int n = ps.size(), k = 0;
    sort(ps.begin(), ps.end(), cmp_x);
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

int main() {
    int N;
    while (cin >> N && N) {
        vector<Point> ps(N);
        for (auto &p : ps) {
            char ch;
            cin >> p.x >> ch >> p.y;
        }
        vector<Point> res = convex_hull(ps);
        cout << N - res.size() << endl;
    }
}