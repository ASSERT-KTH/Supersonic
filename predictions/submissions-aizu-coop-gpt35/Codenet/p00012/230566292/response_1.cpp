#include <iostream>
#include <complex>

static const double EPS = 1e-12;
static const double INF = 1e24;

using Point = std::complex<double>;

double cross_prod(const Point& a, const Point& b) {
    return imag(conj(a) * b);
}

double dot_prod(const Point& a, const Point& b) {
    return real(conj(a) * b);
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

const int ONLINE_FRONT = -2;
const int CLOCKWISE = -1;
const int ON_SEGMENT = 0;
const int COUNTER_CLOCKWISE = 1;
const int ONLINE_BACK = 2;

int ccwise(const Point& a, const Point& b, const Point& c) {
    Point ba = b - a;
    Point ca = c - a;
    double cross = cross_prod(ba, ca);
    double dot = dot_prod(ba, ca);

    if (cross > 0) {
        return COUNTER_CLOCKWISE;
    } else if (cross < 0) {
        return CLOCKWISE;
    } else if (dot < 0) {
        return ONLINE_BACK;
    } else if (norm(ba) < norm(ca)) {
        return ONLINE_FRONT;
    } else {
        return ON_SEGMENT;
    }
}

bool testcase_ends() {
    double x, y;
    if (!(std::cin >> x >> y))
        return true;
    Point A(x, y);
    std::cin >> x >> y;
    Point B(x, y);
    std::cin >> x >> y;
    Point C(x, y);
    std::cin >> x >> y;
    Point P(x, y);
    
    int tmp = ccwise(A, P, B);
    if (tmp != ccwise(B, P, C)) {
        std::cout << "NO" << std::endl;
    } else if (tmp != ccwise(C, P, A)) {
        std::cout << "NO" << std::endl;
    } else {
        std::cout << "YES" << std::endl;
    }
    
    return false;
}

int main() {
    int solved = 0;
    while (!testcase_ends()) {
        ++solved;
    }
    
    return !solved;
}