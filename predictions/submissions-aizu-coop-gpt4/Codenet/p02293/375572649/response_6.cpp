#include <iostream>
#include <cmath>

struct Point {
    double x;
    double y;
};

double crossProduct(Point a, Point b) {
    return a.x * b.y - a.y * b.x;
}

int main() {
    int n;
    std::cin >> n;
    while (n--) {
        Point a, b, c, d;
        std::cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;
        b.x -= a.x; b.y -= a.y;
        d.x -= c.x; d.y -= c.y;
        double cross = crossProduct(b, d);
        double dot = b.x * d.x + b.y * d.y;
        std::cout << (cross == 0 ? (dot == 0 ? 1 : 2) : 0) << '\n';
    }
    return 0;
}