#include <algorithm>
#include <cstdio>
#include <vector>
#define MAX 150
using namespace std;
bool dp[MAX][MAX][2];
vector<pair<int, int>> changed;

int main() {
  for(int i = 0; i < MAX; i++)
    for(int j = 0; j < MAX; j++)
      for(int l = 0; l < 2; l++)
        dp[i][j][l] = false;
  
  int T;
  scanf("%d", &T);
  while (T--) {
    int N;
    scanf("%d", &N);
    int input[N];
    for(int i = 0; i < N; i++)
      scanf("%d", &input[i]);
    if (N <= 2) {
      printf("%d\n", input[N - 1]);
      continue;
    }
    int ans = input[N - 1];
    for(int cur = 1; cur < N - 1; cur++) {
      dp[input[cur - 1]][input[cur]][cur % 2] = true;
      changed.push_back({input[cur - 1], input[cur]});
      int R = input[cur + 1];
      for(int L = 0; L < MAX; L++) {
        for(int M = 0; M < MAX; M++) {
          if (!dp[L][M][cur % 2])
            continue;
          if (M == 0) {
            if (cur + 2 < N) {
              dp[M][R][(cur + 1) % 2] = true;
              changed.push_back({M, R});
            } else
              ans = max(ans, R);
          } else {
            if (cur + 2 < N) {
              dp[M][R][(cur + 1) % 2] = true;
              dp[M - 1][R + L][(cur + 1) % 2] = true;
              changed.push_back({M, R});
              changed.push_back({M - 1, R + L});
            } else {
              ans = max(ans, R + L);
            }
          }
        }
      }
      for(auto p : changed)
        dp[p.first][p.second][cur % 2] = false;
      changed.clear();
    }
    printf("%d\n", ans);
  }
  return 0;
}