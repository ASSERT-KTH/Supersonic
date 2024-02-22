#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

typedef double D;
struct P {
    D x, y;
};

const D EPS = 1e-7;

D dot(P a, P b) { return a.x * b.x + a.y * b.y; }
D cross(P a, P b) { return a.x * b.y - a.y * b.x; }
int ccw(P a, P b, P c) {
    D val = cross(b - a, c - a);
    if (abs(val) < EPS) return 0;
    return (val > 0) ? 1 : -1;
}

int main() {
    int n, m, q;
    cin >> n;
    vector<vector<P>> V(n);

    for (int i = 0; i < n; i++) {
        cin >> m;
        vector<P> polygon(m);
        for (int j = 0; j < m; j++) {