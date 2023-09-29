#include <bits/stdc++.h>
using namespace std;

int n;
int x[24], y[24], r[24], c[24];
bool memo[1 << 24];

bool ok(int a, int bit, int& dist, int& sum) {
    if (((bit >> a) & 1) == 0) {
        return false;
    }
    dist = x[a] * x[a] + y[a] * y[a];
    sum = r[a] * r[a];
    for (int i = 0; i < n; i++) {
        if (i == a) {
            continue;
        }
        if (((bit >> i) & 1) == 0) {
            continue;
        }
        int dx = x[a] - x[i];
        int dy = y[a] - y[i];
        dist = dx * dx + dy * dy;
        sum = (r[i] + r[a]) * (r[i] + r[a]);
        if (dist < sum) {
            return false;
        }
    }
    return true;
}

int dfs(int bit) {
    memo[bit] = true;
    int ret = n;
    for (int i = 0; i < n; i++) {
        if ((bit >> i) & 1) {
            ret--;
        }
    }
    for (int i = 0; i < n; i++) {
        if (!ok(i, bit, dist, sum)) {
            continue;
        }
        for (int j = i + 1; j < n; j++) {
            if (((bit >> j) & 1) == 0 || c[i] != c[j]) {
                continue;
            }
            int to_bit = (bit ^ (1 << i)) ^ (1 << j);
            if (!memo[to_bit] && ok(j, bit, dist, sum)) {
                ret = max(ret, dfs(to_bit));
            }
        }
    }
    return ret;
}

void solve() {
    fill_n(memo, 1 << n, false);
    cout << dfs((1 << n) - 1) << endl;
}

bool input() {
    cin >> n;
    if (!n) {
        return false;
    }
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i] >> r[i] >> c[i];
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while (input()) {
        solve();
    }
    return 0;
}