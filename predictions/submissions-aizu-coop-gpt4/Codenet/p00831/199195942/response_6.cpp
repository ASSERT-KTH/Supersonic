#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int damerau_levenshtein_distance(const string &a, const string &b) {
    int m = a.size();
    int n = b.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    for (int i = 0; i <= m; i++)
        dp[i][0] = i;
    for (int j = 1; j <= n; j++)
        dp[0][j] = j;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            int cost = a[i-1] == b[j-1] ? 0 : 1;
            dp[i][j] = min({dp[i-1][j] + 1, dp[i][j-1] + 1, dp[i-1][j-1] + cost});
            if (i > 1 && j > 1 && a[i-1] == b[j-2] && a[i-2] == b[j-1])
                dp[i][j] = min(dp[i][j], dp[i-2][j-2] + cost);
        }
    }
    return dp[m][n];
}

void solve(int n) {
    int d;
    vector<string> name(n);
    cin >> d;
    for (int i = 0; i < n; i++)
        cin >> name[i];
    sort(name.begin(), name.end());
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (abs((int)name[i].size() - (int)name[j].size()) > d)
                continue;
            if (damerau_levenshtein_distance(name[i], name[j]) <= d) {
                ++count;
                cout << name[i] << "," << name[j] << endl;
            }
        }
    }
    cout << count << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for (;;) {
        int n;
        cin >> n;
        if (!n)
            break;
        solve(n);
    }
    return 0;
}