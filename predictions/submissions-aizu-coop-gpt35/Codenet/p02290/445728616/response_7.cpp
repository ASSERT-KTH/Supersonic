#include <iostream>
#include <complex>
using namespace std;

struct Point {
    float x, y;
};

complex<float> project(Point a, Point b, Point c) {
    complex<float> bComplex(b.x, b.y), cComplex(c.x, c.y);
    bComplex -= complex<float>(a.x, a.y);
    cComplex -= complex<float>(a.x, a.y);
    return complex<float>(a.x, a.y) + bComplex * real(cComplex / bComplex);
}

int main() {
    int n;
    float ax, ay, bx, by, cx, cy;
    cin >> ax >> ay >> bx >> by >> n;
    while (n--) {
        cin >> cx >> cy;
        Point a = {ax, ay};
        Point b = {bx, by};
        Point c = {cx, cy};
        complex<float> p = project(a, b, c);
        printf("%.8f %.8f\n", p.real(), p.imag());
    }
    return 0;
}