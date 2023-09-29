#include <bits/stdc++.h>
using namespace std;

constexpr int maxN = 50;
constexpr int maxA = 100;

int N, M;
int A[3];
vector<int> G[maxN + 1];
bool used[maxN + 1];
bitset<maxN + 1> dp[maxA + 1][maxN + 1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for (auto &a : A) cin >> a;
    for (int i = 0; i < M; ++i) {
        int f, t;
        cin >> f >> t;
        --f, --t;
        G[f].push_back(t);
    }

    for (int i = 0; i < N; ++i)
        dp[0][i][i] = 1;

    for (int i = 1; i <= maxA; ++i)
        for (int j = 0; j < N; ++j)
            for (const auto &k : G[j])
                dp[i][j] |= dp[i - 1][j] << k;

    used[N - 1] = true;
    for (int ite = 1;; ++ite) {
        bool ok = false;
        vector<int> idx;
        for (int i = 0; i < N; ++i) {
            if (used[i]) continue;
            int cnt = count_if(begin(A), end(A), [&](const auto &a) { return (dp[a][i] & used).any(); });
            if (cnt == 3) {
                ok = true;
                idx.push_back(i);
            }
        }
        if (ok) {
            for (const auto &i : idx)
                used[i] = true;
            if (used[0]) {
                cout << ite << '\n';
                return 0;
            }
        } else {
            break;
        }
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}