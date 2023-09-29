#include <iostream>
#include <vector>
using namespace std;

const int MAX_H_W = 1000;
vector<vector<int>> mp(MAX_H_W, vector<int>(MAX_H_W, 0));
vector<vector<int>> dp(MAX_H_W, vector<int>(MAX_H_W, 0));
int h, w, n;

void saiki(int x, int y) {
  int dx[] = {0, 1}, dy[] = {1, 0};
  if (y == h || x == w)
    cout << y + 1 << " " << x + 1 << endl;
  else
    saiki(x + dx[mp[y][x]], y + dy[mp[y][x]]);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while (1) {
    cin >> h >> w >> n;
    if (!h && !w && !n)
      break;
    for (int i = 0; i < h; i++)
      for (int j = 0; j < w; j++)
        cin >> mp[i][j];
    fill(dp.begin(), dp.end(), vector<int>(MAX_H_W, 0));
    dp[0][0] = n - 1;
    for (int i = 0; i < h; i++)
      for (int j = 0; j < w; j++) {
        if(j+1 < MAX_H_W) dp[i][j + 1] += dp[i][j] / 2 + mp[i][j] * dp[i][j] % 2;
        if(i+1 < MAX_H_W) dp[i + 1][j] += dp[i][j] / 2 + !mp[i][j] * dp[i][j] % 2;
        if (dp[i][j] % 2)
          mp[i][j] = !mp[i][j];
      }
    saiki(0, 0);
  }
  return 0;
}