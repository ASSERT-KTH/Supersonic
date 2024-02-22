#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

const double eps = 1e-10;

struct Point {
    double x, y;
};

struct Circle {
    double rad;
    Point pnt;
};

Circle smallest_enclosing_disc(const std::vector<Point>& ps) {
    auto c3 = [](const Point& a, const Point& b, const Point& c) {
        double A = (b.x - c.x) * (b.x - c.x) + (b.y - c.y) * (b.y - c.y);
        double B = (c.x - a.x) * (c.x - a.x) + (c.y - a.y) * (c.y - a.y);
        double C = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
        double S = std::abs((b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x));
        Point p{ (A * (B + C - A) * a.x + B * (C + A - B) * b.x + C * (A + B - C) * c.x) / (4 * S * S),
                 (A * (B + C - A) * a.y + B * (C + A - B) * b.y + C * (A + B - C) * c.y) / (4 * S * S) };
        double r = std::sqrt((p.x - a.x) * (p.x - a.x) + (p.y - a.y) * (p.y - a.y));
        return Circle{ r, p };
    };

    auto c2 = [](const Point& a, const Point& b) {
        Point c{ (a.x + b.x) / 2, (a.y + b.y) / 2 };
        double r = std::sqrt((a.x - c.x) * (a.x - c.x) + (a.y - c.y) * (a.y - c.y));
        return Circle{ r, c };
    };

    auto in_circle = [](const Point& a, const Circle& c) {
        double dist_sq = (a.x - c.pnt.x) * (a.x - c.pnt.x) + (a.y - c.pnt.y) * (a.y - c.pnt.y);
        return dist_sq <= c.rad * c.rad + eps;
    };

    int n = ps.size();
    std::random_shuffle(ps.begin(), ps.end());
    Circle c = c2(ps[0], ps[1]);
    for (int i = 2; i < n; ++i) {
        if (!in_circle(ps[i], c)) {
            c = c2(ps[0], ps[i]);
            for (int j = 1; j < i; ++j) {
                if (!in_circle(ps[j], c)) {
                    c = c2(ps[j], ps[i]);
                    for (int k = 0; k < j; ++k) {
                        if (!in_circle(ps[k], c)) {
                            c = c3(ps[i], ps[j], ps[k]);
                        }
                    }
                }
            }
        }
    }
    return c;
}

int n, m;
double r[111], mb[111];
bool used[111];

bool chk(int s) {
    int b_size = n;
    int a_size = m - s;
    int b_idx = 0;
    int a_idx = 0;
    std::sort(r, r + n);
    std::sort(mb + s, mb + m);
    int last = -1;
    for (int i = 0; i < a_size; ++i) {
        bool found = false;
        for (int j = last + 1; j < b_size; ++j) {
            if (mb[s + i] < r[j] + eps) {
                found = true;
                last = j;
                break;
            }
        }
        if (!found)
            return false;
    }
    return true;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    int ans[111];
    std::cin >> n >> m;
    for (int i = 0; i < n; ++i)
        std::cin >> r[i];
    for (int i = 0; i < m; ++i) {
        int k;
        std::cin >> k;
        std::vector<Point> g(k);
        for (int j = 0; j < k; ++j)
            std::cin >> g[j].x >> g[j].y;
        mb[i] = smallest_enclosing_disc(g).rad;
    }
    std::fill(used, used + n, false);
    bool f = true;
    for (int i = 0; i < m; ++i) {
        bool found = false;
        for (int j = 0; j < n; ++j) {
            if (used[j])
                continue;
            if (!(mb[i] < r[j] + eps))
                continue;
            used[j] = true;
            if (chk(i + 1)) {
                ans[i] = j;
                found = true;
                break;
            }
            used[j] = false;
        }
        if (!found) {
            f = false;
            break;
        }
    }
    if (f) {
        for (int i = 0; i < m; ++i)
            std::cout << ans[i] + 1 << "\n";
    } else {
        std::cout << "NG" << std::endl;
    }
    return 0;
}