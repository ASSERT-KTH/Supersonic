#include <iostream>
using namespace std;

int a[101];
long long dp[2][21];

int main() {
    int N;
    cin >> N;

    for (int i = 0; i <= 20; i++) {
        dp[0][i] = 0;
    }

    int curr = 1, prev = 0;
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
        for (int j = 0; j <= 20; j++) {
            dp[curr][j] = 0;
        }

        if (i == 1) {
            dp[curr][a[i]] = 1;
            continue;
        }

        for (int j = 0; j <= 20; j++) {
            if (j - a[i] >= 0)
                dp[curr][j] += dp[prev][j - a[i]];
            if (j + a[i] <= 20)
                dp[curr][j] += dp[prev][j + a[i]];
        }

        swap(curr, prev);
    }
    
    cout << dp[prev][a[N]] << endl;

    return 0;
}