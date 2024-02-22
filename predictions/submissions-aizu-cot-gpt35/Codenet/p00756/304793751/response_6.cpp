#include <iostream>
#include <vector>
using namespace std;

bool ok(int a, int bit, const vector<int>& x, const vector<int>& y, const vector<int>& r) {
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

int dfs(int bit, vector<bool>& memo, const vector<int>& c, const vector<int>& r) {
    memo[bit] = true;
    int n = memo.size();
    int ret = n;
    for (int i = 0; i < n; i++)
        if ((bit >> i) & 1)
            ret--;
    for (int i = 0; i < n; i++) {
        if (((bit >> i) & 1) == 0 || ok(i, bit, c, r) == false)
            continue;
        for (int j = i + 1; j < n; j++) {
            if (((bit >> j) & 1) == 0 || c[i] != c[j])
                continue;
            int to_bit = (bit ^ (1 << i)) ^ (1 << j);
            if (ok(j, bit, c, r) && !memo[to_bit]) {
                ret = max(ret, dfs(to_bit, memo, c, r));
            }
        }
    }
    return ret;
}

void solve() {
    int n;
    cin >> n;
    if (n == 0)
        return;
    vector<int> x(n), y(n), r(n), c(n);
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i] >> r[i] >> c[i];
    vector<bool> memo(1 << n, false);
    cout << dfs((1 << n) - 1, memo, c, r) << endl;
}

int main() {
    while (true)
        solve();
    return 0;
}