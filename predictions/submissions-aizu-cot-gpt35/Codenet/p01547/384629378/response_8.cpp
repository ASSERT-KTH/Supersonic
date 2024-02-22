#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

typedef double D;
typedef std::complex<D> P;
typedef std::pair<P, P> L;
typedef std::vector<P> VP;
typedef std::vector<VP> Vcon;

const D EPS = 1e-7;

D cross(P a, P b) { return (std::conj(a) * b).imag(); }
int ccw(P a, P b, P c) {
    b -= a;
    c -= a;
    D cross_product = cross(b, c);
    if (cross_product > EPS)
        return +1;
    if (cross_product < -EPS)
        return -1;
    if (std::real(b * std::conj(c)) < -EPS)
        return +2;
    if (std::norm(b) < std::norm(c))
        return -2;
    return 0;
}

VP convexHull(VP ps) {
    int n = ps.size(), k = 0;
    std::sort(ps.begin(), ps.end());
    VP ch(2 * n);
    for (int i = 0; i < n; i++) {
        while (k >= 2 && ccw(ch[k - 2], ch[k - 1], ps[i]) <= 0)
            --k;
        ch[k++] = ps[i];
    }
    for (int i = n - 2, t = k + 1; i >= 0; i--) {
        while (k >= t && ccw(ch[k - 2], ch[k - 1], ps[i]) <= 0)
            --k;
        ch[k++] = ps[i];
    }
    ch.resize(k - 1);
    return ch;
}

int main() {
    int n, m, q;
    std::cin >> n;
    VP V[n];
    for (int i = 0; i < n; i++) {
        std::cin >> m;
        V[i].resize(m);
        for (int j = 0; j < m; j++) {
            D x, y;
            std::cin >> x >> y;
            V[i][j] = P(x, y);
        }
    }
    VP s1, s2;
    for (int i = 0; i < n; i++) {