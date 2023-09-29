#include <algorithm>
#include <iostream>
#include <vector>
#define MAX 150
using namespace std;
bool dp[MAX][MAX][2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        fill(&dp[0][0][0], &dp[0][0][0] + sizeof(dp)/sizeof(dp[0][0][0]), false);
        int N;
        cin >> N;
        vector<int> input(N);
        for (auto& i : input) cin >> i;
        if (N <= 2) {
            cout << input[N - 1] << "\n";
            continue;
        }
        int ans = input[N - 1];
        for (int cur = 1; cur < N - 1; ++cur) {
            dp[input[cur - 1]][input[cur]][cur & 1] = true;
            int R = input[cur + 1];
            for(int L = 0; L < MAX; ++L) {
                for(int M = 0; M < MAX; ++M) {
                    if (!dp[L][M][cur & 1])
                        continue;
                    if (M == 0) {
                        if (cur + 2 < N) {
                            dp[M][R][(cur + 1) & 1] = true;
                        } else
                            ans = max(ans, R);
                    } else {
                        if (cur + 2 < N) {
                            dp[M][R][(cur + 1) & 1] = true;
                            dp[M - 1][R + L][(cur + 1) & 1] = true;
                        } else {
                            ans = max(ans, R + L);
                        }
                    }
                }
            }
            fill(&dp[0][0][cur & 1], &dp[0][0][cur & 1] + sizeof(dp)/sizeof(dp[0][0][0])/2, false);
        }
        cout << ans << "\n";
    }
    return 0;
}