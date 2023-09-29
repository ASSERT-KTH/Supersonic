#include <bits/stdc++.h>
using namespace std;

int N, M;
int A[3];
vector<int> G[51];
bitset<51> used;
bitset<101> dp[51][51];

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < 3; i++)
        cin >> A[i];

    for (int i = 0; i < M; i++) {
        int f, t;
        cin >> f >> t;
        f--; t--;
        G[f].push_back(t);
    }

    for (int i = 0; i < N; i++)
        dp[i][i][0] = 1;

    for (int i = 1; i <= 100; i++) {
        for (int j = 0; j < N; j++) {
            for (int k : G[j]) {
                dp[j][k][i] |= dp[j][k][i - 1];
            }
        }
    }

    used[N - 1] = 1;
    for (int ite = 1;; ite++) {
        bitset<51> nextUsed = used;
        for (int i = 0; i < N; i++) {
            if (used[i])
                continue;
            if ((dp[i][N - 1][A[0]] && dp[i][N - 1][A[1]] && dp[i][N - 1][A[2]]) || (dp[i][N - 1][A[0]] && dp[i][N - 1][A[2]] && dp[i][N - 1][A[1]]) || (dp[i][N - 1][A[1]] && dp[i][N - 1][A[2]] && dp[i][N - 1][A[0]])) {
                nextUsed[i] = 1;
                if (i == 0) {
                    cout << ite << "\n";
                    return 0;
                }
            }
        }
        if (nextUsed == used)
            break;
        used = nextUsed;
    }
    cout << "IMPOSSIBLE\n";

    return 0;
}