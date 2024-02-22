#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solver {
    int n;
    vector<int> x, y, r, c;
    vector<bool> memo;
    vector<vector<bool>> ok;

public:
    Solver(int n) : n(n), x(n), y(n), r(n), c(n), memo(1 << n, false), ok(n, vector<bool>(n, true)) {}

    bool check(int a, int bit) {
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

    void preprocess() {
        for (int i = 0; i < n; i++)
            for (int j = i+1; j < n; j++)
                ok[i][j] = ok[j][i] = check(i, (1 << n) - 1);
    }

    int iddfs(int bit, int depth) {
        if (depth == 0 || memo[bit])
            return 0;
        memo[bit] = true;
        int ret = n;
        for (int i = 0; i < n; i++)
            if ((bit >> i) & 1)
                ret--;
        for (int i = 0; i < n; i++) {
            if (((bit >> i) & 1) == 0 || !ok[i][bit])
                continue;
            for (int j = i + 1; j < n; j++) {
                if (((bit >> j) & 1) == 0 || c[i] != c[j])
                    continue;
                int to_bit = (bit ^ (1 << i)) ^ (1 << j);
                if (ok[j][bit] && !memo[to_bit]) {
                    ret = max(ret, iddfs(to_bit, depth - 1));
                }
            }
        }
        return ret;
    }

    void solve() {
        preprocess();
        cout << iddfs((1 << n) - 1, n) << endl;
    }

    void input() {
        for (int i = 0; i < n; i++)
            cin >> x[i] >> y[i] >> r[i] >> c[i];
    }
};

int main() {
    int n;
    while (cin >> n && n) {
        Solver solver(n);
        solver.input();
        solver.solve();
    }
    return 0;
}