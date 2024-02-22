#include <iostream>
#include <vector>
using namespace std;

int mp[1001][1001];
int dp[1001][1001];

void saiki(int x, int y) {
  int dx[] = {0, 1};
  int dy[] = {1, 0};
  
  while (y != h && x != w) {
    x += dx[mp[y][x]];
    y += dy[mp[y][x]];
  }

  cout << y + 1 << " " << x + 1 << endl;
}

int main() {
  int h, w, n;
  
  while (true) {
    cin >> h >> w >> n;
    if (h == 0 && w == 0 && n == 0)
      break;

    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        cin >> mp[i][j];
      }
    }

    fill(&dp[0][0], &dp[0][0] + sizeof(dp) / sizeof(int), 0);
    dp[0][0] = n - 1;

    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        dp[i][j + 1] += dp[i][j] >> 1 + mp[i][j] * (dp[i][j] & 1);
        dp[i + 1][j] += dp[i][j] >> 1 + (!mp[i][j] * (dp[i][j] & 1));

        if (dp[i][j] & 1) {
          mp[i][j] = !mp[i][j];
        }
      }
    }

    saiki(0, 0);
  }

  return 0;
}