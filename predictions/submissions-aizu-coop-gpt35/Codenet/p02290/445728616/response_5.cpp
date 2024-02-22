#include <iostream>
#include <cmath>

struct Point {
    float x, y;
};

Point project(Point a, Point b, Point c) {
    b.x -= a.x;
    b.y -= a.y;
    c.x -= a.x;
    c.y -= a.y;

    float dot = b.x * b.x + b.y * b.y;
    float t = (c.x * b.x + c.y * b.y) / dot;

    Point p;
    p.x = a.x + b.x * t;
    p.y = a.y + b.y * t;

    return p;
}

int main() {
    float ax, ay, bx, by;
    int n;
    std::cin >> ax >> ay >> bx >> by >> n;

    while (n--) {
        float cx, cy;
        std::cin >> cx >> cy;

        Point p = project({ax, ay}, {bx, by}, {cx, cy});
        printf("%.8f %.8f\n", p.x, p.y);
    }

    return 0;
}