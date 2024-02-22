#include <iostream>
#include <vector>
using namespace std;

int main() {
  int h, w, n;
  while (1) {
    cin >> h >> w >> n;
    if (!h && !w && !n)
      break;

    // Dynamic memory allocation based on h, w
    vector<vector<int>> mp(h, vector<int>(w));
    vector<vector<int>> dp(h, vector<int>(w));

    for (int i = 0; i < h; i++)
      for (int j = 0; j < w; j++)
        cin >> mp[i][j];

    dp[0][0] = n - 1;
    for (int i = 0; i < h; i++)
      for (int j = 0; j < w; j++) {
        int mod_val = dp[i][j] % 2; // Remove redundant computation
        dp[i][j + 1] += dp[i][j] / 2 + mp[i][j] * mod_val;
        dp[i + 1][j] += dp[i][j] / 2 + !mp[i][j] * mod_val;
        if (mod_val)
          mp[i][j] = !mp[i][j];
      }

    // Inline saiki() function and replace recursion with while loop
    int x = 0, y = 0, dx[] = {0, 1}, dy[] = {1, 0};
    while (y != h && x != w) {
      int temp = x + dx[mp[y][x]];
      y = y + dy[mp[y][x]];
      x = temp;
    }
    cout << y + 1 << " " << x + 1 << endl;
  }
  return 0;
}