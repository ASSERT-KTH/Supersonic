#include <algorithm>
#include <iostream>
#include <vector>
#define REP(i, s, n) for (int i = s; i < n; i++)
#define rep(i, n) REP(i, 0, n)
#define inf (1 << 29)
#define MAX 150
using namespace std;

bool dp[MAX][MAX][2];
vector<pair<int, int>> used[MAX][MAX][2];

void reset(int cur) {
  for (auto& p : used[cur & 1]) {
    dp[p.first][p.second][cur & 1] = false;
  }
  used[cur & 1].clear();
}

int main() {
  int T;
  while (cin >> T) {
    while (T--) {
      int N;
      cin >> N;
      vector<int> input(N);
      for (int& x : input) cin >> x;
      if (N <= 2) {
        cout << input[N - 1] << endl;
        continue;
      }
      int ans = input[N - 1];
      REP(cur, 1, N - 1) {
        reset(cur & 1);
        dp[input[cur - 1]][input[cur]][cur & 1] = true;
        used[cur & 1].push_back({input[cur - 1], input[cur]});
        int R = input[cur + 1];
        for (auto& p : used[!(cur & 1)]) {
          int L = p.first, M = p.second;
          if (!dp[L][M][!(cur & 1)])
            continue;
          if (M == 0) {
            if (cur + 2 < N) {
              dp[M][R][(cur + 1) & 1] = true;
              used[(cur + 1) & 1].push_back({M, R});
            } else
              ans = max(ans, R);
          } else {
            if (cur + 2 < N) {
              dp[M][R][(cur + 1) & 1] = true;
              dp[M - 1][R + L][(cur + 1) & 1] = true;
              used[(cur + 1) & 1].push_back({M, R});
              used[(cur + 1) & 1].push_back({M - 1, R + L});
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