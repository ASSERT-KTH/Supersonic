#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

const int MAXN = 51;
const int MAXM = 101;
int N, M;
int A[3];
vector<int> G[MAXN];
bitset<MAXN> used = 0;
bitset<MAXM> dp[MAXM][MAXN];

int main() {
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
        dp[0][i][i] = 1;
    for (int i = 1; i < MAXM; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                if (dp[i - 1][j][k]) {
                    for (int to : G[k]) {
                        dp[i][j][to] = 1;
                    }
                }
            }
        }
    }
    used[N - 1] = 1;
    for (int ite = 1;; ite++) {
        bool ok = false;
        vector<int> idx;
        idx.clear();
        for (int i = 0; i < N; i++) {
            if (used[i])
                continue;
            int cnt = 0;
            for (int j = 0; j < 3; j++) {
                int a = A[j];
                for (int k = 0; k < N; k++) {
                    if (dp[a][i][k] && used[k]) {
                        cnt++;
                        break;
                    }
                }
                if (cnt == 3) {
                    ok = true;
                    idx.push_back(i);
                    break;
                }
            }
        }
        if (ok) {
            for (int i : idx) {
                used[i] = 1;
            }
            if (used[0]) {
                cout << ite << endl;
                return 0;
            }
        } else {
            break;
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}