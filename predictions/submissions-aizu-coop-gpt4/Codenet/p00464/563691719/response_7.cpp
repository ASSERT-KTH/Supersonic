#include <bits/stdc++.h>
using namespace std;
int mp[1001][1001], dp[1001][1001] = {0};
;
int h, w, n;

void saiki(int x, int y) {
  int dx[] = {0, 1}, dy[] = {1, 0};
  while (y != h && x != w)
  {
    x += dx[mp[y][x]];
    y += dy[mp[y][x]];
  }
  cout << y + 1 << " " << x + 1 << endl;
}

int main() {
  while (1) {
    cin >> h >> w >> n;
    if (!h && !w && !n)
      break;
    for (int i = 0; i < h; i++)
      for (int j = 0; j < w; j++)
        cin >> mp[i][j];

    dp[0][0] = n - 1;

    #pragma omp parallel for
    for (int i = 0; i < h; i++)
      for (int j = 0; j < w; j++) {
        dp[i][j + 1] += dp[i][j] / 2 + mp[i][j] * dp[i][j] % 2;
        dp[i + 1][j] += dp[i][j] / 2 + !mp[i][j] * dp[i][j] % 2;
        if (dp[i][j] % 2)
          mp[i][j] = !mp[i][j];
      }
    saiki(0, 0);
  }
  return 0;
}