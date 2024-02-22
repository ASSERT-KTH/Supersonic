#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> pint;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int dpru(vector<int> &c, vector<int> &v, int n, int m) {
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
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
        for (int i = 0; i < n; ++i) {
            string s;
            int t;
            getline(cin, s);
            getline(cin, s);
            cin >> t;
            c[i] = t;
            for (int j = 0; j < 3; ++j) {
                cin >> v[j][i];
            }
        }
        int res = 0;
        for (int i = 0; i < 3; ++i) {
            res = max(res, dpru(c, v[i], n, m));
        }
        cout << res << endl;
    }
}