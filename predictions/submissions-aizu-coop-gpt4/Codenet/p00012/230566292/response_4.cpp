#include <iostream>
#include <vector>
using namespace std;

struct Point {
    double x, y;
};

struct Triangle {
    Point a, b, c;
};

enum CCWiseState {
    ONLINE_FRONT = -2,
    CLOCKWISE,
    ON_SEGMENT,
    COUNTER_CLOCKWISE,
    ONLINE_BACK,
};

double cross_prod(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

double dot_prod(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.x - a.x) + (b.y - a.y) * (c.y - a.y);
}

CCWiseState ccwise(Point a, Point b, Point c) {
    if (cross_prod(a, b, c) > 0) return COUNTER_CLOCKWISE;
    if (cross_prod(a, b, c) < 0) return CLOCKWISE;
    if (dot_prod(a, b, c) < 0) return ONLINE_BACK;
    if (dot_prod(a, b, c) > 0) return ONLINE_FRONT;
    return ON_SEGMENT;
}

bool check_position(Triangle t, Point p) {
    CCWiseState tmp1 = ccwise(t.a, p, t.b);
    CCWiseState tmp2 = ccwise(t.b, p, t.c);
    CCWiseState tmp3 = ccwise(t.c, p, t.a);
    return tmp1 == tmp2 && tmp2 == tmp3;
}

int main() {
    Triangle triangle;
    Point p;
    vector<string> results;
    while (cin >> triangle.a.x >> triangle.a.y) {
        cin >> triangle.b.x >> triangle.b.y;
        cin >> triangle.c.x >> triangle.c.y;
        cin >> p.x >> p.y;
        results.push_back(check_position(triangle, p) ? "YES" : "NO");
    }
    for (const auto &res : results) {
        cout << res << endl;
    }
    return 0;
}