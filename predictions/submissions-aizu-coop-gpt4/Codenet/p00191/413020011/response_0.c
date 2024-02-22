#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <tuple>

using namespace std;

double solve(int n, int m, vector<vector<double>>& a) {
    map<tuple<int, int, int>, double> memo;
    for(int p = 0; p < n; p++) {
        for(int k = 0; k < n; k++) {
            memo[make_tuple(p, 1, k)] = 1;
        }
    }
    for(int m_i = 2; m_i <= m; m_i++) {
        for(int p = 0; p < n; p++) {
            for(int k = 0; k < n; k++) {
                double res = 0;
                for(int i = 0; i < n; i++) {
                    res = max(res, memo[make_tuple(p, m_i - 1, i)] * a[p][i]);
                }
                memo[make_tuple(p, m_i, k)] = res;
            }
        }
    }
    double max_res = 0;
    for(int p = 0; p < n; p++) {
        for(int k = 0; k < n; k++) {
            max_res = max(max_res, memo[make_tuple(p, m, k)]);
        }
    }
    return max_res;
}

int main() {
    int n, m;
    while(cin >> n >> m, n | m) {
        vector<vector<double>> a(n, vector<double>(n));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cin >> a[i][j];
            }
        }
        double res = solve(n, m, a);
        printf("%.2f\n", res);
    }
    return 0;
}