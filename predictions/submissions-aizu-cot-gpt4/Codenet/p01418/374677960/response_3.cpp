#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int K, R, L;
double P, E, T;

double dfs(int d, double l, double r) {
    double mid = (l + r) / 2;

    if (fabs(mid - T) <= E)
        return 1;

    if (!d)
        return 0;

    if (r < T - E || T + E < l)
        return 0;

    if (mid >= T)
        return (1.0 - P) * dfs(d - 1, l, mid) + P * dfs(d - 1, mid, r);

    return (1.0 - P) * dfs(d - 1, mid, r) + P * dfs(d - 1, l, mid);
}

int main() {
    scanf("%d %d %d %lf %lf %lf", &K, &L, &R, &P, &E, &T);
    printf("%.9f\n", dfs(K, L, R));
    return 0;
}