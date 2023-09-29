#include <cstdio>
#include <complex>

using namespace std;
using Point = complex<double>;

inline double cross_prod(const Point &a, const Point &b) { return imag(conj(a) * b); }
inline double dot_prod(const Point &a, const Point &b) { return real(conj(a) * b); }

enum CCWiseState{
    ONLINE_FRONT = -2,
    CLOCKWISE,
    ON_SEGMENT,
    COUNTER_CLOCKWISE,
    ONLINE_BACK,
};

inline CCWiseState ccwise(Point a, Point b, Point c) {
    b -= a;
    c -= a;
    if (cross_prod(b, c) > 0) return COUNTER_CLOCKWISE;
    if (cross_prod(b, c) < 0) return CLOCKWISE;
    if (dot_prod(b, c) < 0) return ONLINE_BACK;
    if (norm(b) < norm(c)) return ONLINE_FRONT;
    return ON_SEGMENT;
}

bool testcase_ends() {
    double x, y; 
    if (scanf("%lf %lf", &x, &y) == EOF) return true;
    Point A(x, y);
    scanf("%lf %lf", &x, &y);
    Point B(x, y);
    scanf("%lf %lf", &x, &y);
    Point C(x, y);
    scanf("%lf %lf", &x, &y);
    Point P(x, y);
    CCWiseState state = ccwise(A, P, B);
    if (state != ccwise(B, P, C) || state != ccwise(C, P, A)) {
        printf("NO\n");
        return false;
    }
    printf("YES\n");
    return false;
}

int main() {
    int solved = 0;
    while (!testcase_ends()) ++solved;
    return solved == 0;
}