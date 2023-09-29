#include <iostream>
using namespace std;
const int MAX = 1001;
int mp[MAX][MAX], dp[MAX][MAX];
int h, w, n;
void saiki(int x, int y) {
  int dx[] = {0, 1}, dy[] = {1, 0};
  if (x == h || y == w)
    cout << y + 1 << " " << x + 1 << endl;
  else
    saiki(x + dx[mp[y][x]], y + dy[mp[y][x]]);
}
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  while (cin >> h >> w >> n, h || w || n) {
    for (int i = 0; i < h; i++)
      for (int j = 0; j < w; j++)
        cin >> mp[i][j];
    fill(&dp[0][0], &dp[0][0] + sizeof(dp) / sizeof(int), 0);
    dp[0][0] = n - 1;
    for (int i = 0; i < h; i++)
      for (int j = 0; j < w; j++) {
        int mod = dp[i][j] & 1;
        dp[i][j + 1] += dp[i][j] >> 1;
        dp[i + 1][j] += dp[i][j] >> 1;
        if (mp[i][j] == mod) {
          ++dp[i][j + 1];
        } else {
          ++dp[i + 1][j];
        }
        mp[i][j] ^= mod;
      }
    saiki(0, 0);
  }
  return 0;
}