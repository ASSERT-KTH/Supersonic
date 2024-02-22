#include <iostream>
#include <vector>
#include <algorithm>
#include <omp.h> // for OpenMP
using namespace std;

int main() {
    int N, W;
    cin >> N >> W;
    vector<int> v(N), w(N);
    for (int i = 0; i < N; i++)
        cin >> v[i] >> w[i];

    vector<vector<int>> dp(N+1, vector<int>(W+1, 0)); // dynamic dp array

    for (int i = 0; i < N; i++) {
        #pragma omp parallel for // parallelize inner loop
        for (int j = 0; j <= W; j++) {
            if (j - w[i] < 0) {
                dp[i + 1][j] = dp[i][j];
            } else {
                dp[i + 1][j] = max(dp[i][j], dp[i][j - w[i]] + v[i]);
            }
        }
    }

    cout << dp[N][W] << endl;
    return 0;
}