#include <bits/stdc++.h>
using namespace std;
int mp[1001][1001], dp[1001][1001];
int h, w, n;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  while (1) {
    scanf("%d %d %d", &h, &w, &n);
    if (!h && !w && !n)
      break;
    
    for (int i = 0; i < h; i++){
      for (int j = 0; j < w; j++){
        scanf("%d", &mp[i][j]);
      }
    }
    
    memset(dp, 0, sizeof(dp));
    dp[0][0] = n - 1;
    int dx[] = {0, 1}, dy[] = {1, 0}, x = 0, y = 0;
    #pragma omp parallel for
    for (int i = 0; i < h; i++){
      for (int j = 0; j < w; j++) {
        dp[i][j + 1] += dp[i][j] / 2 + mp[i][j] * dp[i][j] % 2;
        dp[i + 1][j] += dp[i][j] / 2 + !mp[i][j] * dp[i][j] % 2;
        if (dp[i][j] % 2)
          mp[i][j] = !mp[i][j];
      }
    }
    while (y != h && x != w) {
      int temp = x;
      x = x + dx[mp[y][x]];
      y = y + dy[mp[temp][y]];
    }
    printf("%d %d\n", y + 1, x + 1);
  }
  return 0;
}