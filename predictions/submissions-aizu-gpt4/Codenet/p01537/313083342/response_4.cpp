#include <bits/stdc++.h>
using namespace std;
constexpr double eps = 1e-10;
using P = complex<double>;
struct Circle {
    P p; double r; 
    Circle(const P &p, double r) : p(p), r(r) { }
};
bool in_circle(const Circle &c, const P &p) {
    return norm(p - c.p) <= c.r * c.r + eps;
}
Circle c2(const P &a, const P &b) {
    P c = (a + b) / 2.0;
    double r = abs(a - c);
    return Circle(c, r);
}
Circle c3(const P &a, const P &b, const P &c) {
    double A = norm(b - c);
    double B = norm(c - a);
    double C = norm(a - b);
    double S = abs((conj(b - a) * (c - a)).imag()) * 2.0;
    P p = (A * (B + C - A) * a + B * (C + A - B) * b + C * (A + B - C) * c) / (4.0 * S * S);
    double r = abs(p - a);
    return Circle(p, r);
}
Circle smallest_enclosing_disc(vector<P> &ps) {
    int n = ps.size();
    random_shuffle(ps.begin(), ps.end());
    Circle c = c2(ps[0], ps[1]);
    for (int i = 2; i < n; ++i) {
        if (!in_circle(c, ps[i])) {
            c = c2(ps[0], ps[i]);
            for (int j = 1; j < i; ++j) {
                if (!in_circle(c, ps[j])) {
                    c = c2(ps[j], ps[i]);
                    for (int k = 0; k < j; ++k) {
                        if (!in_circle(c, ps[k])) {
                            c = c3(ps[i], ps[j], ps[k]);
                        }
                    }
                }
            }
        }
    }
    return c;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<double> r(n);
    for (auto &x : r) cin >> x;
    sort(r.begin(), r.end());
    vector<int> ans;
    vector<bool> used(n);
    for (int i = 0; i < m; ++i) {
        int k;
        cin >> k;
        vector<P> g(k);
        for (auto &p : g) {
            double x, y;
            cin >> x >> y;
            p = P(x, y);
        }
        double rad = smallest_enclosing_disc(g).r;
        auto it = lower_bound(r.begin(), r.end(), rad - eps);
        if (it == r.end()) {
            cout << "NG\n";
            return 0;
        }
        ans.push_back(distance(r.begin(), it) + 1);
        r.erase(it);
    }
    for (auto &x : ans) cout << x << "\n";
    return 0;
}