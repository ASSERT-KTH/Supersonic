#include "bits/stdc++.h"
#include <cassert>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define all(a) (a).begin(), (a).end()
#define vi vector<int>
#define pb push_back
#define INF 999999999
#define EPS (1e-10)
class P {
public:
    double x, y;
    P(double _x = 0, double _y = 0) : x(_x), y(_y){};
    P operator+(const P &p) const { return P(x + p.x, y + p.y); }
    P operator-(const P &p) const { return P(x - p.x, y - p.y); }
    P operator*(double k) const { return P(x * k, y * k); }
    P operator/(double k) const { return P(x / k, y / k); }
    bool operator==(const P &p) const {
        return (fabs(x - p.x) < EPS && fabs(y - p.y) < EPS);
    }
    double norm() const { return x * x + y * y; }
    double abs() const { return sqrt(norm()); }
};
struct C {
    P cent;
    double r;
};
struct L {
    P p1, p2;
};
typedef vector<P> Polygon;
typedef P Vector;
double dot(const Vector &a, const Vector &b) { return a.x * b.x + a.y * b.y; }
double cross(const Vector &a, const Vector &b) { return a.x * b.y - a.y * b.x; }
int ccw(const P &p0, const P &p1, const P &p2) {
    Vector a = p1 - p0;
    Vector b = p2 - p0;
    if (cross(a, b) > EPS)
        return 1;
    if (cross(a, b) < -EPS)
        return -1;
    if (dot(a, b) < -EPS)
        return 2;
    if (a.norm() < b.norm())
        return -2;
    return 0;
}
bool orthogonal(const P &p1, const P &p2, const P &p3, const P &p4) {
    return abs(dot(p1 - p2, p3 - p4)) < EPS;
}
bool intersect(const P &p1, const P &p2, const P &p3, const P &p4) {
    return (ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 &&
            ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0);
}
double distance_l_p(const L &l, const P &p) {
    return abs(cross(l.p2 - l.p1, p - l.p1)) / (l.p2 - l.p1).abs();
}
bool intersect_circle_point(const P &center, double r, const L &line) {
    return distance_l_p(line, center) <= r + EPS;
}
bool isSimple(const Polygon &pol) {
    size_t pol_size = pol.size() - 1;
    rep(i, pol_size) {
        for (int j = i + 2; j < pol_size; j++) {
            if (i == j || i == (j - 1 + pol_size) % pol_size || i == (j + 1 + pol_size) % pol_size)
                continue;
            if (intersect(pol[i], pol[i + 1], pol[j], pol[j + 1]))
                return false;
        }
    }
    return true;
}
bool isPointInsidePolygon(const vector<L> &side, const P &p) {
    int c = 0, sideSum = side.size();
    rep(i, sideSum) {
        if (cross(side[i].p2 - side[i].p1, p - side[i].p1) > 0)
            c++;
    }
    return !(c % sideSum);
}
#define MAX_N 100
bool cmp_x(const P &p, const P &q) {
    if (p.x != q.x)
        return p.x < q.x;
    return p.y < q.y;
}
vector<P> convex_hull(const P *ps, int n) {
    vector<int> idx(n);
    for (int i = 0; i < n; ++i) idx[i] = i;
    sort(all(idx), [&](int i, int j){ return ps[i].x < ps[j].x; });
    vector<int> stk(n);
    int sz = 0;
    for (int i = 0; i < n; ++i) {
        while (sz >= 2) {
            int l1 = stk[sz - 2], l2 = stk[sz - 1];
            if (cross(ps[l2] - ps[l1], ps[idx[i]] - ps[l1]) < 0) break;
            --sz;
        }
        stk[sz++] = idx[i];
    }
    for (int i = n - 2, t = sz; i >= 0; --i) {
        while (sz > t) {
            int l1 = stk[sz - 2], l2 = stk[sz - 1];
            if (cross(ps[l2] - ps[l1], ps[idx[i]] - ps[l1]) < 0) break;
            --sz;
        }
        stk[sz++] = idx[i];
    }
    vector<P> qs(sz - 1);
    for (int i = 0; i < sz - 1; ++i) qs[i] = ps[stk[i]];
    return qs;
}
int N;
P ps[MAX_N];
int main() {
    while (cin >> N && N) {
        rep(i, N) {
            char ch;
            cin >> ps[i].x >> ch >> ps[i].y;
        }
        vector<P> res = convex_hull(ps, N);
        cout << N - res.size() << endl;
    }
}