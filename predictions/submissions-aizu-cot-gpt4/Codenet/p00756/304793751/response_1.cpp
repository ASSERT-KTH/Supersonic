#include <bits/stdc++.h>
using namespace std;

constexpr int MAX = 24;
bitset<1 << MAX> memo;

inline bool ok(int a, int bit, int* x, int* y, int* r) {
    for (int i = 0; i < a; i++) {
        if (((bit >> i) & 1) == 0)
            continue;
        int dist = (x[i] - x[a]) * (x[i] - x[a]) + (y[i] - y[a]) * (y[i] - y[a]);
        int sum = (r[i] + r[a]) * (r[i] + r[a]);
        if (dist < sum)
            return false;
    }
    return true;
}

int dfs(int bit, int n, int* x, int* y, int* r, int* c) {
    memo[bit] = true;
    int ret = n;
    for (int i = 0; i < n; i++)
        if ((bit >> i) & 1)
            ret--;
    for (int i = 0; i < n; i++) {
        if (((bit >> i) & 1) == 0 || !ok(i, bit, x, y, r))
            continue;
        for (int j = i + 1; j < n; j++) {
            if (((bit >> j) & 1) == 0 || c[i] != c[j])
                continue;
            int to_bit = (bit ^ (1 << i)) ^ (1 << j);
            if (ok(j, bit, x, y, r) && !memo[to_bit]) {
                ret = max(ret, dfs(to_bit, n, x, y, r, c));
            }
        }
    }
    return ret;
}

void solve(int n, int* x, int* y, int* r, int* c) {
    memo.reset();
    cout << dfs((1 << n) - 1, n, x, y, r, c) << '\n';
}

bool input() {
    int n;
    cin >> n;
    if (!n)
        return false;
    int x[MAX], y[MAX], r[MAX], c[MAX];
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i] >> r[i] >> c[i];
    solve(n, x, y, r, c);
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    while (input());
    return 0;
}