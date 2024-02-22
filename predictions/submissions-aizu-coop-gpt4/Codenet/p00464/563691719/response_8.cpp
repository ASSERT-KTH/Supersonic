#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> mp(1001, vector<int>(1001));
vector<vector<int>> dp(1001, vector<int>(1001));

int h, w, n;

void saiki() {
  int x = 0, y = 0;
  int dx[] = {0, 1}, dy[] = {1, 0};
  while (y != h && x != w) {
    int new_x = x + dx[mp[y][x]];
    int new_y = y + dy[mp[y][x]];
    x = new_x;
    y = new_y;
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

    fill(dp.begin(), dp.end(), vector<int>(1001, 0));
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
    saiki();
  }
  return 0;
}