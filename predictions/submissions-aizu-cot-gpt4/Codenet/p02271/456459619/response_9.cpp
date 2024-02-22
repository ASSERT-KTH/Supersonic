#include <iostream>
#include <vector>
using namespace std;

bool isSubsetSum(vector<int>& set, int sum) {
    int n = set.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));

    for (int i = 0; i <= n; i++)
        dp[i][0] = true;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (j >= set[i-1])
                dp[i][j] = dp[i-1][j] || dp[i-1][j-set[i-1]];
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    return dp[n][sum];
}

int main() {
    int n, t, p;
    cin >> n;
    vector<int> set(n);
    for (int i = 0; i < n; i++) {
        cin >> set[i];
    }
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> p;
        if (isSubsetSum(set, p)) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
    return 0;
}