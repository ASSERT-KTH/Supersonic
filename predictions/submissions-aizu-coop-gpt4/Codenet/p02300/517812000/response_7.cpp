#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Point {
public:
    int x, y;
    Point(int a = 0, int b = 0) : x(a), y(b) {};
    bool operator<(const Point &p) const {
        return y != p.y ? y < p.y : x < p.x;
    }
};

inline bool direct(Point &base, Point &a, Point &b) {
    int dx1 = a.x - base.x, dy1 = a.y - base.y;
    int dx2 = b.x - base.x, dy2 = b.y - base.y;
    return dx1 * dy2 < dx2 * dy1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<Point> P(n), H(2 * n);
    for (int i = 0; i < n; ++i) {
        cin >> P[i].x >> P[i].y;
    }
    sort(P.begin(), P.end());

    int k = 2;
    H[0] = P[0];
    H[1] = P[1];
    for (int i = 2; i < n; ++i) {
        while (k >= 2 && direct(H[k - 2], H[k - 1], P[i]))
            k--;
        H[k++] = P[i];
    }
    for (int i = n - 1; i >= 0; --i) {
        while (k >= 2 && direct(H[k - 2], H[k - 1], P[i]))
            k--;
        H[k++] = P[i];
    }
    cout << k - 1 << "\n";
    for (int i = 0; i < k - 1; ++i) {
        cout << H[i].x << " " << H[i].y << "\n";
    }
    return 0;
}