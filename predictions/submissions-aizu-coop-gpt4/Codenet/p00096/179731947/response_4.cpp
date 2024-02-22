#include <iostream>
using namespace std;

unsigned long long dp[4001][4] = {0};

void initialize() {
    // Initialize dp array
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4001; j++) {
            dp[j][i] = (i == 1 && j <= 1000) ? 1 : 0;
        }
    }

    // Compute dp values
    for (int i = 2; i <= 4; i++) {
        for (int j = 0; j <= 4000; j++) {
            for (int k = 0; k <= j; k++) {
                dp[j][i] += dp[j - k][i - 1];
            }
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);  // speed up cin and cout operations
    initialize();  // compute dp values once outside the main loop

    int n;
    while (cin >> n) {
        cout << dp[n][3] << '\n';
    }

    return 0;
}