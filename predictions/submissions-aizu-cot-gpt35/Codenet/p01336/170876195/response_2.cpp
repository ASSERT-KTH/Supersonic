#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX_N = 333;
const int MAX_M = 333;

int n, m;
int c[MAX_N], v[MAX_N][3];
int dp[MAX_M];

int dpru() {
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; ++i) {
        for (int j = m; j >= c[i]; --j) {
            dp[j] = max(dp[j], dp[j - c[i]] + v[i][0]);
        }
    }
    return dp[m];
}

int main() {
    while (scanf("%d %d", &n, &m) == 2) {
        getchar();
        for (int i = 0; i < n; ++i) {
            string s;
            getline(cin, s);
            getline(cin, s);
            scanf("%d", &c[i]);
            for (int j = 0; j < 3; ++j) {
                scanf("%d", &v[i][j]);
            }
        }
        int res = 0;
        for (int i = 0; i < 3; ++i) {
            res = max(res, dpru());
        }
        cout << res << endl;
    }
    return 0;
}