#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

class Solver {
private:
    int n, m;
    double dp[101][101];
    vector<vector<double>> t;

public:
    Solver(int n, int m, vector<vector<double>> &t): n(n), m(m), t(t) {
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                dp[i][j] = -1;
            }
        }
    }

    double solve() {
        for (int times = 1; times <= m; times++) {
            for (int prev = 0; prev < n; prev++) {
                double tmp = -1;
                for (int i = 0; i < n; i++) {
                    if (times == 1) {
                        tmp = max(tmp, 1.0);
                    } else {
                        tmp = max(tmp, dp[times - 1][i] * t[prev][i]);
                    }
                }
                dp[times][prev] = tmp;
            }
        }
        return dp[m][0];
    }
};

int main(void) {
    int n, m;
    while (cin >> n >> m) {
        if (!(n | m))
            break;
        vector<vector<double>> t(n, vector<double>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> t[i][j];
            }
        }
        Solver solver(n, m, t);
        double retd = solver.solve() * 100;
        printf("%.2lf\n", round(retd) / 100);
    }
}