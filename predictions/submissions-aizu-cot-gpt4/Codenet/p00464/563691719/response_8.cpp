#include <bits/stdc++.h>
using namespace std;

int mp[1001][1001], dp[1001][1001];
int h, w, n;

void saiki(int x, int y) {
  int dx[] = {0, 1}, dy[] = {1, 0};
  while (x != w && y != h) {
    int direction = mp[y][x];
    x += dx[direction];
    y += dy[direction];
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
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        int half = dp[i][j] / 2;
        int remainder = dp[i][j] % 2;
        dp[i][j + 1] += half + mp[i][j] * remainder;
        dp[i + 1][j] += half + !mp[i][j] * remainder;
        if (remainder)
          mp[i][j] = !mp[i][j];
      }
    }
    saiki(0, 0);
  }
  return 0;
}