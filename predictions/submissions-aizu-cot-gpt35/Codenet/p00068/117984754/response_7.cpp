#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class P {
public:
    double x, y;
};

bool cmp_x(const P &p, const P &q) {
    return p.x < q.x;
}

double cross(const P &a, const P &b, const P &c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

vector<P> convex_hull(P *ps, int n) {
    sort(ps, ps + n, cmp_x);
    int k = 0;
    vector<P> qs(n * 2);
    for (int i = 0; i < n; i++) {
        while (k > 1 && cross(qs[k - 2], qs[k - 1], ps[i]) <= 0)
            k--;
        qs[k++] = ps[i];
    }
    for (int i = n - 2, t = k; i >= 0; i--) {
        while (k > t && cross(qs[k - 2], qs[k - 1], ps[i]) <= 0)
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
        vector<P> res = convex_hull(ps.data(), N);
        cout << N - res.size() << endl;
    }
    return 0;
}