#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> N(n);
    for (int i = 0; i < n; i++) {
        cin >> N[i];
    }
    int t;
    cin >> t;
    while (t--) {
        int p;
        cin >> p;
        vector<vector<bool>> dp(n + 1, vector<bool>(p + 1, false));
        dp[0][0] = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= p; j++) {
                if (j < N[i]) {
                    dp[i + 1][j] = dp[i][j];
                } else {
                    dp[i + 1][j] = dp[i][j] || dp[i][j - N[i]];
                }
            }
        }
        if (dp[n][p]) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
    return 0;
}