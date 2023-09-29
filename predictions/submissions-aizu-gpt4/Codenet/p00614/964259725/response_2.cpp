#include <iostream>
#include <deque>
#include <algorithm>

#define int long long
#define rep(i, n) for (int i = 0; i < (n); i++)
#define each(it, v) for (auto it = (v).begin(); it != (v).end(); it++)
#define fi first
#define se second

constexpr int T = 10000;
constexpr int INF = 1001001001;
constexpr int C[6] = {1, 5, 10, 50, 100, 500};
int P, N[6], dp[2][T];

inline void chmin(int& a, int b) { a = std::min(a, b); }

int calc(int v) {
    int ans = 0;
    for (int i = 5; i >= 0; i--) {
        ans += v / C[i];
        v %= C[i];
    }
    return ans;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    while (std::cin >> P) {
        rep(i, 6) std::cin >> N[i];
        if (P == 0) break;
        std::fill(*dp, *dp + 2 * T, INF);
        int cnt = 0;
        for (int i = 5; i >= 0; i--) {
            while (P - C[i] >= 2500 && N[i]) {
                cnt++; N[i]--; P -= C[i];
            }
            if (N[i]) break;
        }
        dp[0][0] = 0;
        rep(i, 6) {
            rep(j, C[i]) {
                std::deque<std::pair<int,int>> deq;
                for (int k = j; k < T; k += C[i]) {
                    int w = T - k / C[i];
                    chmin(dp[(i + 1) & 1][k], dp[i & 1][k]);
                    while (!deq.empty() && deq.front().se + C[i] * N[i] < k)
                        deq.pop_front();
                    if (!deq.empty())
                        chmin(dp[(i + 1) & 1][k], deq.front().fi - w);
                    deq.emplace_back(dp[i & 1][k] + w, k);
                }
            }
        }
        int mi = INF;
        for (int i = P; i < T; i++) {
            chmin(mi, dp[0][i] + calc(i - P));
        }
        std::cout << mi + cnt << '\n';
    }
    return 0;
}