#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int dpru(const vector<int>& c, const vector<int>& v, int n, int m) {
    int dp[333][333];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= m; ++j) {
            dp[i + 1][j] = dp[i][j];
            if (j >= c[i])
                dp[i + 1][j] = max(dp[i + 1][j], dp[i + 1][j - c[i]] + v[i]);
        }
    }
    return dp[n][m];
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        vector<int> c(n);
        vector<vector<int>> v(3, vector<int>(n));
        for(int i = 0; i < n; i++){
            string s;
            int t;
            cin.ignore();
            getline(cin, s);
            cin >> t;
            c[i] = t;
            for(int j = 0; j < 3; j++){
                cin >> v[j][i];
            }
        }
        int res = 0;
        for(int i = 0; i < 3; i++) {
            res = max(res, dpru(c, v[i], n, m));
        }
        cout << res << endl;
    }
}