#include <iostream>
#include <algorithm>
#define MAX 150

bool dp[MAX][MAX][2];

int main() {
    int T;
    std::cin >> T;
    while (T--) {
        int N;
        std::cin >> N;
        int input[N];

        for (int i = 0; i < N; ++i) {
            std::cin >> input[i];
        }
        std::fill(&dp[0][0][0], &dp[0][0][0] + sizeof(dp), false);

        if (N <= 2) {
            std::cout << input[N - 1] << "\n";
            continue;
        }

        int ans = input[N - 1];
        for (int cur = 1; cur < N - 1; ++cur) {
            dp[input[cur - 1]][input[cur]][cur & 1] = true;
            int R = input[cur + 1];
            for (int L = 0; L < MAX; ++L) {
                for (int M = 0; M < MAX; ++M) {
                    if (!dp[L][M][cur & 1])
                        continue;
                    if (M == 0) {
                        if (cur + 2 < N) {
                            dp[M][R][(cur + 1) & 1] = true;
                        } else
                            ans = std::max(ans, R);
                    } else {
                        if (cur + 2 < N) {
                            dp[M][R][(cur + 1) & 1] = true;
                            dp[M - 1][R + L][(cur + 1) & 1] = true;
                        } else {
                            ans = std::max(ans, R + L);
                        }
                    }
                }
            }
            std::fill(&dp[0][0][cur & 1], &dp[0][0][cur & 1] + MAX * MAX, false);
        }
        std::cout << ans << "\n";
    }
    return 0;
}