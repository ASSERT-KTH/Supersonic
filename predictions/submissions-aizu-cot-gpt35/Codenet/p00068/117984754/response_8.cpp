#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class P {
public:
    double x, y;
    P(double _x = 0, double _y = 0) : x(_x), y(_y){};
};

bool cmp_x(const P &p, const P &q) {
    if (p.x != q.x)
        return p.x < q.x;
    return p.y < q.y;
}

vector<P> convex_hull(P *ps, int n) {
    sort(ps, ps + n, cmp_x);
    vector<P> qs;
    qs.push_back(ps[0]);
    int k = 1;
    for (int i = 1; i < n; i++) {
        while (k > 1 && ((qs[k - 1].x - qs[k - 2].x) * (ps[i].y - qs[k - 2].y) - (qs[k - 1].y - qs[k - 2].y) * (ps[i].x - qs[k - 2].x)) <= 0)
            k--;
        qs.push_back(ps[i]);
        k++;
    }
    return qs;
}

int main() {
    int N;
    while (cin >> N && N) {
        P ps[N];
        for (int i = 0; i < N; i++) {
            char ch;
            cin >> ps[i].x >> ch >> ps[i].y;
        }
        vector<P> res = convex_hull(ps, N);
        cout << N - res.size() << endl;
    }
    return 0;
}