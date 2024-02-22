#include <iostream>
#include <vector>
using namespace std;

vector<int> N;
int n;

bool subset_sum(int sum) {
    vector<vector<bool>> dp(n+1, vector<bool>(sum+1, false));

    // If sum is 0, the answer is true
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;

    // If sum is not 0 and set is empty, then answer is false
    for (int i = 1; i <= sum; i++)
        dp[0][i] = false;

    // Fill the subset table in bottom-up manner
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if(j<N[i-1])
                dp[i][j] = dp[i-1][j];
            if (j >= N[i-1])
                dp[i][j] = dp[i-1][j] || dp[i - 1][j-N[i-1]];
        }
    }
    return dp[n][sum];
}

int main() {
    int t;
    cin >> n;
    N.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> N[i];
    }
    cin >> t;
    for (int i = 0; i < t; i++) {
        int p;
        cin >> p;
        if (subset_sum(p)) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
    return 0;
}