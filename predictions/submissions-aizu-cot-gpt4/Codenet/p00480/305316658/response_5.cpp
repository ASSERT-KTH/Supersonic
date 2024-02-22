#include <iostream>
using namespace std;
long long dp[21];
int main() {
    int N;
    cin >> N;
    int prev_a, a;
    cin >> prev_a;
    dp[prev_a] = 1;
    for (int i = 2; i <= N; i++) {
        long long new_dp[21] = {};
        cin >> a;
        for (int j = 0; j <= 20; j++) {
            if (j - prev_a >= 0) {
                new_dp[j] += dp[j - prev_a];
            }
            if (j + prev_a <= 20) {
                new_dp[j] += dp[j + prev_a];
            }
        }
        for (int j = 0; j <= 20; j++) {
            dp[j] = new_dp[j]; // Update dp for next iteration
        }
        prev_a = a; // Update prev_a for next iteration
    }
    cout << dp[a] << endl;
    return 0;
}