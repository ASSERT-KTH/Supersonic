#include <iostream>
using namespace std;

const int MAX_H = 1001;
const int MAX_W = 1001;

int mp[MAX_H][MAX_W];
int dp[MAX_H][MAX_W];

int h, w, n;

void saiki(int x, int y) {
  int dx[] = {0, 1};
  int dy[] = {1, 0};
  
  if (y == h || x == w)
    return;

  saiki(x + dx[mp[y][x]], y + dy[mp[y][x]]);
}

int main() {
  while (true) {
    cin >> h >> w >> n;
    if (!h && !w && !n)
      break;

    for (int i = 0; i < h; i++)
      for (int j = 0; j < w; j++)
        cin >> mp[i][j];

    for (int i = 0; i < h; i++)
      for (int j = 0; j < w; j++) {
        dp[i][j + 1] += dp[i][j] >> 1 + mp[i][j] * (dp[i][j] & 1);
        dp[i + 1][j] += dp[i][j] >> 1 + !mp[i][j] * (dp[i][j] & 1);
      }

    saiki(0, 0);
  }

  return 0;
}