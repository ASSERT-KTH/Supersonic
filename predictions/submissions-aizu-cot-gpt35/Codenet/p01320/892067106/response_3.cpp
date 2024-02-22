#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

typedef complex<double> P;
typedef vector<P> G;

struct MSQ : public G {
    MSQ() {}
    vector<P> p;
    vector<pair<P, P>> s;
    int m, k;
    MSQ(int m, int k) : m(m), k(k) {
        for (int i = 0; i < m; i++) {
            double angle = 2 * M_PI * i / m + M_PI / 2;
            p.push_back(P(cos(angle), sin(angle)));
        }
        for (int i = 0; i < m; i++) {
            s.emplace_back(p[i], p[(i + k) % m]);
        }
        reverse(begin(), end());
    }
};

bool convex_contains(const MSQ &msq, const P &g, const P &p) {
    int n = msq.size();
    int a = 0, b = n;
    const P pg = p - g;
    while (a + 1 < b) {
        int c = (a + b) / 2;