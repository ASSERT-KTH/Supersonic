#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> mp(1001, vector<int>(1001)), dp(1001, vector<int>(1001));
int h, w, n;

void saiki(int x, int y) {
  int dx[] = {0, 1}, dy[] = {1, 0};
  if (y == h || x == w)
    cout << y + 1 << " " << x + 1 << endl;
  else
    saiki(x + dx[mp[y][x]], y + dy[mp[y][x]]);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  while (true) {
    cin >> h >> w >> n;
    if (!h && !w && !n)
      break;

    for (int i = 0; i < h; ++i)
      for (int j = 0; j < w; ++j)
        cin >> mp[i][j];

    for (auto& row : dp)
      fill(row.begin(), row.end(), 0);

    dp[0][0] = n - 1;
    for (int i = 0; i < h; ++i)
      for (int j = 0; j < w; ++j) {
        int rem = dp[i][j] % 2;
        dp[i][j + 1] += dp[i][j] / 2 + mp[i][j] * rem;
        dp[i + 1][j] += dp[i][j] / 2 + !mp[i][j] * rem;
        if (rem)
          mp[i][j] = !mp[i][j];
      }
    saiki(0, 0);
  }
  return 0;
}