#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Point {
    double x, y;
    Point(double _x = 0, double _y = 0) : x(_x), y(_y) {}
};

inline bool compare(const Point &p, const Point &q) {
    return p.x != q.x ? p.x < q.x : p.y < q.y;
}

int cross(const Point &O, const Point &A, const Point &B) {
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

vector<Point> convexHull(vector<Point> P) {
    int n = P.size(), k = 0;
    vector<Point> H(2 * n);
    sort(P.begin(), P.end(), compare);
    for(int i = 0; i < n; ++i) {
        while(k >= 2 && cross(H[k - 2], H[k - 1], P[i]) <= 0) k--;
        H[k++] = P[i];
    }
    for(int i = n - 2, t = k + 1; i >= 0; --i) {
        while(k >= t && cross(H[k - 2], H[k - 1], P[i]) <= 0) k--;
        H[k++] = P[i];
    }
    H.resize(k - 1);
    return H;
}

int main() {
    int N;
    while (cin >> N && N) {
        vector<Point> points(N);
        for(int i = 0; i < N; ++i) {
            char ch;
            cin >> points[i].x >> ch >> points[i].y;
        }
        vector<Point> res = convexHull(points);
        cout << N - res.size() << endl;
    }
    return 0;
}