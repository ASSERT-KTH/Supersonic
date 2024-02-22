#include<bits/stdc++.h>
using namespace std;

int mp[1001][1001], dp[1001][1001];
int h, w, n;

void saiki(int x, int y) {
  int dx[] = {0, 1}, dy[] = {1, 0};
  while (y != h && x != w)
  {
    int temp = mp[y][x];
    x += dx[temp];
    y += dy[temp];
  }
  printf("%d %d\n", y + 1, x + 1);
}

int main() {
  while (1) {
    scanf("%d %d %d", &h, &w, &n);
    if (!h && !w && !n)
      break;

    for (int i = 0; i < h; i++)
      for (int j = 0; j < w; j++)
        scanf("%d", &mp[i][j]);

    vector<pair<int, int>> used;
    dp[0][0] = n - 1;
    used.emplace_back(0, 0);
    for (int i = 0; i < h; i++)
      for (int j = 0; j < w; j++) {
        if(dp[i][j]) {
          dp[i][j + 1] += dp[i][j] / 2 + mp[i][j] * dp[i][j] % 2;
          dp[i + 1][j] += dp[i][j] / 2 + !mp[i][j] * dp[i][j] % 2;
          if (dp[i][j] % 2)
            mp[i][j] = !mp[i][j];
          used.emplace_back(i, j + 1);
          used.emplace_back(i + 1, j);
        }
      }
    saiki(0, 0);
    
    for (auto &p: used)
      dp[p.first][p.second] = 0;
  }
  return 0;
}