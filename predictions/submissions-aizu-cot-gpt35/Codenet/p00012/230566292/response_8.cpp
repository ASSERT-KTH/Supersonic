#include <complex>
#include <iostream>
#include <vector>

static const double EPS = 1e-12;
static const double INF = 1e24;

using Point = std::complex<double>;
using Plane = std::vector<Point>;

double cross_prod(const Point& a, const Point& b) {
    return std::imag(std::conj(a) * b);
}

double dot_prod(const Point& a, const Point& b) {
    return std::real(std::conj(a) * b);
}

struct Line {
    Point a;
    Point b;
};

struct LineSeg {
    Point a;
    Point b;
};

struct Circle {
    Point p;
    double r;
};

enum CCWiseState {
    ONLINE_FRONT = -2,
    CLOCKWISE,
    ON_SEGMENT,
    COUNTER_CLOCKWISE,
    ONLINE_BACK,
};

CCWiseState ccwise(const Point& a, const Point& b, const Point& c) {
    Point b_minus_a = b - a;
    Point c_minus_a = c - a;
    double cross = cross_prod(b_minus_a, c_minus_a);
    double dot = dot_prod(b_minus_a, c_minus_a);

    if (cross > 0) {
        return COUNTER_CLOCKWISE;
    } else if (cross < 0) {
        return CLOCKWISE;
    } else if (dot < 0) {
        return ONLINE_BACK;
    } else if (dot < std::norm(b_minus_a)) {
        return ONLINE_FRONT;
    } else {
        return ON_SEGMENT;
    }
}

bool testcase_ends() {
    double x, y;
    if (!(std::cin >> x >> y)) {
        return true;
    }
    Point A(x, y);
    std::cin >> x >> y;
    Point B(x, y);
    std::cin >> x >> y;
    Point C(x, y);
    std::cin >> x >> y;
    Point P(x, y);

    CCWiseState tmp = ccwise(A, P, B);
    if (tmp != ccwise(B, P, C)) {
        std::cout << "NO\n";
        return false;
    } else if (tmp != ccwise(C, P, A)) {
        std::cout << "NO\n";
        return false;
    }

    std::cout << "YES\n";
    return false;
}

int main() {
    int solved = 0;
    while (!testcase_ends()) {
        ++solved;
    }
    return !solved;
}