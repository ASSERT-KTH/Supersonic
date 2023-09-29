#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;

const double EPS = 1e-10;

class P {
public:
    double x, y;
    P(double _x = 0, double _y = 0) : x(_x), y(_y){};
    P operator+(P &p) { return P(x + p.x, y + p.y); }
    P operator-(P &p) { return P(x - p.x, y - p.y); }
    P operator*(double k) { return P(x * k, y * k); }
    P operator/(double k) { return P(x / k, y / k); }
    bool operator==(const P &p) {
        return (fabs(x - p.x) < EPS && fabs(y - p.y) < EPS);
    }
    double norm() { return x * x + y * y; }
    double abs() { return sqrt(norm()); }
};

struct C {
    P cent;
    double r;
};

struct L {
    P p1, p2;
};

double dot(P a, P b) { return a.x * b.x + a.y * b.y; }

double cross(P a, P b) { return a.x * b.y - a.y * b.x; }

int ccw(P p0, P p1, P p2) {
    P a = p1 - p0;
    P b = p2 - p0;
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

bool orthogonal(P p1, P p2, P p3, P p4) {
    return abs(dot(p1 - p2, p3 - p4)) < EPS;
}

bool intersect(P p1, P p2, P p3, P p4) {
    return (ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 &&
            ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0);
}

double distance_l_p(L l, P p) {
    return abs(cross(l.p2 - l.p1, p - l.p1)) / (l.p2 - l.p1).abs();
}

bool intersect_circle_point(P center, double r, L line) {
    if (distance_l_p(line, center) <= r + EPS)
        return true;
    return false;
}

bool isSimple(vector<P> pol) {
    size_t pol_size = pol.size() - 1;
    for (size_t i = 0; i < pol_size; i++) {
        for (size_t j = i + 2; j < pol_size; j++) {
            if (i == j || i == (j - 1 + pol_size) % pol_size ||
                i == (j + 1 + pol_size) % pol_size)
                continue;
            if (intersect(pol[i], pol[i + 1], pol[j], pol[j + 1]))
                return false;
        }
    }
    return true;
}

bool isPointInsidePolygon(vector<L> side, P p) {
    int c = 0, sideSum = side.size();
    for (int i = 0; i < sideSum; i++) {
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

vector<P> convex_hull(P *ps, int n) {
    sort(ps, ps + n, cmp_x);
    int k = 0;
    vector<P> qs(n * 2);
    for (int i = 0; i < n; i++) {
        while (k > 1 && cross((qs[k - 1] - qs[k - 2]), (ps[i] - qs[k - 1])) <= 0)
            k--;
        qs[k++] = ps[i];
    }
    for (int i = n - 2, t = k; i >= 0; i--) {
        while (k > t && cross((qs[k - 1] - qs[k - 2]), (ps[i] - qs[k - 1])) <= 0)
            k--;
        qs[k++] = ps[i];
    }
    qs.resize(k - 1);
    return qs;
}

int main() {
    int N;
    while (cin >> N && N) {
        vector<P> ps(N);
        for (int i = 0; i < N; i++) {
            char ch;
            cin >> ps[i].x >> ch >> ps[i].y;
        }
        vector<P> res = convex_hull(&ps[0], N);
        cout << N - res.size() << endl;
    }
}