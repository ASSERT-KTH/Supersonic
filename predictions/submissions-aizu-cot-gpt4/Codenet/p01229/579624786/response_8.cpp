#include <algorithm>
#include <iostream>
#include <vector>
#define REP(i, s, n) for (int i = s; i < n; i++)
#define rep(i, n) REP(i, 0, n)
#define MAX 150
using namespace std;
bool dp[MAX][MAX];
vector<pair<int, int>> used;
int main() {
  int T;
  while (cin >> T) {
    while (T--) {
      used.clear();
      int N;
      cin >> N;
      int input[N];
      rep(i, N) cin >> input[i];
      if (N <= 2) {
        cout << input[N - 1] << endl;
        continue;
      }
      int ans = input[N - 1];
      REP(cur, 1, N - 1) {
        dp[input[cur - 1]][input[cur]] = true;
        used.push_back({input[cur - 1], input[cur]});
        int R = input[cur + 1];
        rep(L, MAX) {
          if (dp[L][0]) {
            if (cur + 2 < N) {
              dp[0][R] = true;
              used.push_back({0, R});
            } else
              ans = max(ans, R);
          }
        }
        REP(M, 1, MAX) {
          rep(L, MAX) {
            if (!dp[L][M]) continue;
            if (cur + 2 < N) {
              dp[M][R] = true;
              used.push_back({M, R});
              dp[M - 1][R + L] = true;
              used.push_back({M - 1, R + L});
            } else {
              ans = max(ans, R + L);
            }
          }
        }
        for (auto &p : used) dp[p.first][p.second] = false;
        used.clear();
      }
      cout << ans << endl;
    }
  }
  return 0;
}