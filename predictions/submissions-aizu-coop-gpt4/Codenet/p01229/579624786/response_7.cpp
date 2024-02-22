#include <algorithm>
#include <iostream>
#include <vector>
#define REP(i, s, n) for (int i = s; i < n; i++)
#define MAX 150
using namespace std;
bool dp[2][MAX][MAX];
vector<pair<int, int>> marked[MAX];
int main() {
  int T;
  while (cin >> T) {
    while (T--) {
      int N;
      cin >> N;
      int input[N];
      REP(i, 0, N) cin >> input[i];
      if (N <= 2) {
        cout << input[N - 1] << endl;
        continue;
      }
      int ans = input[N - 1];
      REP(cur, 1, N - 1) {
        for (auto &cell : marked[cur & 1]) dp[cur & 1][cell.first][cell.second] = false;
        marked[cur & 1].clear();
        dp[cur & 1][input[cur - 1]][input[cur]] = true;
        marked[cur & 1].push_back({input[cur - 1], input[cur]});
        int R = input[cur + 1];
        for (auto &cell : marked[!(cur & 1)]) {
          int L = cell.first, M = cell.second;
          if (!dp[!(cur & 1)][L][M]) continue;
          if (M == 0) {
            if (cur + 2 < N) {
              dp[(cur + 1) & 1][M][R] = true;
              marked[(cur + 1) & 1].push_back({M, R});
            } else
              ans = max(ans, R);
          } else {
            if (cur + 2 < N) {
              dp[(cur + 1) & 1][M][R] = true;
              marked[(cur + 1) & 1].push_back({M, R});
              dp[(cur + 1) & 1][M - 1][R + L] = true;
              marked[(cur + 1) & 1].push_back({M - 1, R + L});
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