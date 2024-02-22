#include <complex>
#include <vector>
#include <iostream>

using namespace std;

static const double EPS = 1e-12;
static const double INF = 1e24;

using Point = complex<double>;
using Plane = vector<Point>;

double cross_prod(const Point& a, const Point& b) { return imag(conj(a) * b); }

double dot_prod(const Point& a, const Point& b) { return real(conj(a) * b); }

enum CCWiseState {
    ONLINE_FRONT = -2,
    CLOCKWISE,
    ON_SEGMENT,
    COUNTER_CLOCKWISE,
    ONLINE_BACK,
};

CCWiseState ccwise(const Point& a, const Point& b, const Point& c, const double& norm_b) {
    double cross = cross_prod(b, c);
    double dot = dot_prod(b, c);

    if (cross > 0) {
        return COUNTER_CLOCKWISE;
    } else if (cross < 0) {
        return CLOCKWISE;
    } else if (dot < 0) {
        return ONLINE_BACK;
    } else if (norm_b < norm(c)) {
        return ONLINE_FRONT;
    } else {
        return ON_SEGMENT;
    }
}

bool testcase_ends() {
    double x, y;
    if (scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &x, &y, &x, &y, &x, &y, &x, &y) == EOF) {
        return true;
    }

    Point A(x, y), B(x, y), C(x, y), P(x, y);
    double norm_b = norm(B - A);

    CCWiseState tmp = ccwise(A, B - A, P - A, norm_b);
    bool flag = true;

    if (tmp != ccwise(B, C - B, P - B, norm_b)) {
        flag = false;
    } else if (tmp != ccwise(C, A - C, P - C, norm_b)) {
        flag = false;
    }

    cout << (flag ? "YES" : "NO") << endl;

    return false;
}

int main() {
    int solved = 0;
    while (!testcase_ends()) {
        ++solved;
    }
    return !solved;
}