#include <bits/stdc++.h>
using namespace std;
int K;
double P, E, T;
double dfs(int d, double l, double r) {
    double mid = (l + r) * 0.5;
    if (d == 0)
        return (fabs(mid - T) <= E) ? 1.0 : 0.0;
    if (r < T - E || T + E < l)
        return 0.0;
    if (mid >= T)
        return (1.0 - P) * dfs(d - 1, l, mid) + P * dfs(d - 1, mid, r);
    return (1.0 - P) * dfs(d - 1, mid, r) + P * dfs(d - 1, l, mid);
}
int main() {
    double L, R;
    cin >> K >> L >> R >> P >> E >> T;
    cout << fixed << setprecision(9) << dfs(K, L, R) << "\n";
    return 0;
}