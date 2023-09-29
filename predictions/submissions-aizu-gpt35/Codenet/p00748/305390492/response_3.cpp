#include <algorithm>
#include <iostream>
#include <vector>
#define INF 1 << 28
using namespace std;

const int MAXN = 1000000;

int p[MAXN+1];
int memo[MAXN+1][6];
int memo2[MAXN+1];

int solve(int n, int count) {
    if (!n) return 0;
    if (n <= 0 || !count) return INF;
    if (memo[n][count]) return memo[n][count];
    int ans = INF;
    for (int i = 0; p[i] <= n; i++)
        ans = min(ans, solve(n - p[i], count - 1) + 1);
    return memo[n][count] = ans;
}

int solve2(int n) {
    if (!n) return 0;
    if (n < 0) return INF;
    if (memo2[n]) return memo2[n];
    int ans = INF;
    for (int i = 0; p[i] <= n; i++) {
        if (!(p[i] % 2)) continue;
        ans = min(ans, solve2(n - p[i]) + 1);
    }
    return memo2[n] = ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> cube;
    for (int i = 1; i <= 100; i++)
        cube.push_back(i * i * i);
    int idx = 0;
    for (int i = 1; i <= MAXN; i++) {
        while (cube[idx] <= i && idx < cube.size()) idx++;
        p[i] = idx;
    }

    for (int i = 1; i <= MAXN; i++)
        solve2(i);

    int n;
    while (cin >> n, n) {
        int ans1 = solve(n, 5);
        int ans2 = solve2(n);
        cout << ans1 << " " << ans2 << "\n";
    }

    return 0;
}