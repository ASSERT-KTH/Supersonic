#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Point {
    double x, y;
};

struct Line {
    Point p1, p2;
};

Point operator-(const Point& a, const Point& b) {
    return {a.x - b.x, a.y - b.y};
}

Point operator+(const Point& a, const Point& b) {
    return {a.x + b.x, a.y + b.y};
}

Point operator*(const Point& a, double b) {
    return {a.x * b, a.y * b};
}

double dot(const Point& a, const Point& b) {
    return a.x * b.x + a.y * b.y;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(15);

    Line L;
    cin >> L.p1.x >> L.p1.y >> L.p2.x >> L.p2.y;

    Point lineVec = L.p2 - L.p1;

    int Q;
    cin >> Q;
    while (Q--) {
        Point p;
        cin >> p.x >> p.y;

        double t = dot(p - L.p1, lineVec) / dot(lineVec, lineVec);
        Point w = L.p1 + lineVec * t;

        cout << w.x << " " << w.y << "\n";
    }

    return 0;
}