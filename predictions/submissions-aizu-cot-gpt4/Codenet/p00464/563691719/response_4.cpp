#include <iostream>
#include <cstring>
using namespace std;

int mp[1001][1001];
int h, w, n;

int main() {
  while (1) {
    cin >> h >> w >> n;
    if (!h && !w && !n)
      break;
    for (int i = 0; i < h; i++)
      for (int j = 0; j < w; j++)
        cin >> mp[i][j];
    int dp[1001][1001] = {0};
    dp[0][0] = n - 1;
    for (int i = 0; i < h; i++)
      for (int j = 0; j < w; j++) {
        int half = dp[i][j] / 2;
        int mod = dp[i][j] % 2;
        dp[i][j + 1] += half + mp[i][j] * mod;
        dp[i + 1][j] += half + !mp[i][j] * mod;
        if (mod)
          mp[i][j] = !mp[i][j];
      }
    int x = 0, y = 0;
    int dx[] = {0, 1}, dy[] = {1, 0};
    while (y != h && x != w) {
        int temp = x;
        x = x + dx[mp[y][x]];
        y = y + dy[mp[temp][y]];
    }
    cout << y + 1 << " " << x + 1 << endl;
  }
  return 0;
}