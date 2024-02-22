#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#define REP(i, s, n) for (int i = s; i < n; i++)
#define rep(i, n) REP(i, 0, n)
#define inf (1 << 29)
#define MAX 150
using namespace std;

bool dp[MAX][MAX][2]; // Reduced to 2 layers instead of MAX
vector<pair<int, int>> active[MAX]; // To keep track of L and M that have dp[L][M][cur & 1] = true

int main() {
  int T;
  while (cin >> T) {
    while (T--) {
      rep(i, MAX) rep(j, MAX) rep(l, 2) dp[i][j][l] = false;
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
        dp[input[cur - 1]][input[cur]][cur & 1] = true;
        active[cur & 1].clear();
        active[cur & 1].push_back({input[cur - 1], input[cur]});
        int R = input[cur + 1];
        for (auto &p : active[cur & 1]) {
          int L = p.first;
          int M = p.second;
          if (M == 0) {
            if (cur + 2 < N) {
              dp[M][R][(cur + 1) & 1] = true;
              active[(cur + 1) & 1].push_back({M, R});
            } else
              ans = max(ans, R);
          } else {
            if (cur + 2 < N) {
              dp[M][R][(cur + 1) & 1] = true;
              dp[M - 1][R + L][(cur + 1) & 1] = true;
              active[(cur + 1) & 1].push_back({M, R});
              active[(cur + 1) & 1].push_back({M - 1, R + L});
            } else {
              ans = max(ans, R + L);
            }
          }
        }
      }
      cout << ans << endl;
    }
  }
  return 0;
}