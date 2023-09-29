#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>

constexpr double EPS = 1e-6;

double add(double a, double b) {
    if (std::abs(a + b) < EPS * (std::abs(a) + std::abs(b)))
        return 0;
    return a + b;
}

struct point {
    double x, y;
    point() {}
    point(double x, double y) : x(x), y(y) {}
    point operator+(const point& p) const { return point(add(x, p.x), add(y, p.y)); }
    point operator-(const point& p) const { return point(add(x, -p.x), add(y, -p.y)); }
    point operator*(double d) const { return point(x * d, y * d); }
    point operator/(double d) const { return point(x / d, y / d); }
    double distance(const point& p) const { return std::sqrt(std::pow(x - p.x, 2) + std::pow(y - p.y, 2)); }
};

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, x, y, v;
    std::vector<point> P;
    std::vector<double> V;
    while (std::cin >> n, n) {
        P.resize(n);
        V.resize(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> x >> y >> v;
            P[i] = point(x, y);
            V[i] = v;
        }
        double r = 0.98;
        point now(0, 0);
        for (double d = 10; d > EPS; d *= r) {
            int mx = 0;
            double mxd = 0;
            for (int j = 0; j < n; ++j) {
                const double dist = now.distance(P[j]) / V[j];
                if (dist > mxd) {
                    mx = j;
                    mxd = dist;
                }
            }
            now = now + ((P[mx] - now) / P[mx].distance(now) * d);
        }
        double ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = std::max(ans, now.distance(P[i]) / V[i]);
        }
        printf("%.8f\n", ans);
    }
    return 0;
}