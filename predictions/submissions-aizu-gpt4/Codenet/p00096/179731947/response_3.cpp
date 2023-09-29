#include <iostream>
using namespace std;

const int MAX_N = 4001;
const int MAX_I = 5;
unsigned long long dp[MAX_N][MAX_I];

void initialize_dp() {
    for (int i = 0; i < MAX_I; ++i)
        for (int j = 0; j < MAX_N; ++j)
            dp[j][i] = (i == 1 && j <= 1000) ? 1 : 0;
}

void calculate_dp() {
    for (int i = 2; i < MAX_I; ++i)
        for (int j = 0; j < MAX_N; ++j)
            for (int k = 0; k <= min(j, 1000); ++k)
                dp[j][i] += dp[j - k][i - 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    initialize_dp();
    calculate_dp();

    int n;
    while (cin >> n)
        cout << dp[n][4] << "\n";
    
    return 0;
}