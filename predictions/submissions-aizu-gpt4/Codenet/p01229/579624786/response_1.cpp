#include <algorithm>
#include <iostream>
#include <vector>
#define REP(i, s, n) for (int i = s; i < n; i++)
#define MAX 150
using namespace std;
bool dp[MAX][MAX][2];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int T;
  cin >> T;
  while (T--) {
    REP(i, 0, MAX) REP(j, 0, MAX) REP(l, 0, 2) dp[i][j][l] = false;
    int N;
    cin >> N;
    vector<int> input(N);
    REP(i, 0, N) cin >> input[i];
    if (N <= 2) {
        cout << input[N - 1] << '\n';
        continue;
    }
    int ans = input[N - 1];
    REP(cur, 1, N - 1) {
      dp[input[cur - 1]][input[cur]][cur & 1] = true;
      int R = input[cur + 1];
      REP(L, 0, MAX) {
        REP(M, 0, MAX) {
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
      REP(i, 0, MAX) REP(j, 0, MAX) dp[i][j][cur & 1] = false;
    }
    cout << ans << '\n';
  }
  return 0;
}