#include <iostream>
#include <vector>
using namespace std;

int main() {
  int h, w, n;
  while (1) {
    cin >> h >> w >> n;
    if (!h && !w && !n)
      break;

    vector<int> mp(h * w);  // Use a 1D vector instead of a 2D array

    for (int i = 0; i < h; i++)
      for (int j = 0; j < w; j++)
        cin >> mp[i * w + j];  // Store values in the 1D vector

    vector<int> dp(h * w);  // Use a 1D vector instead of a 2D array

    // No need to initialize dp array, as it will be completely overwritten

    dp[0] = n - 1;

    for (int i = 0; i < h; i++)
      for (int j = 0; j < w; j++) {
        // Calculate indices for the neighboring cells
        int idx_right = i * w + j + 1;
        int idx_bottom = (i + 1) * w + j;

        dp[idx_right] += dp[i * w + j] / 2 + mp[i * w + j] * dp[i * w + j] % 2;
        dp[idx_bottom] += dp[i * w + j] / 2 + !mp[i * w + j] * dp[i * w + j] % 2;
        if (dp[i * w + j] % 2)
          mp[i * w + j] = !mp[i * w + j];
      }

    int x = 0, y = 0;

    // Traverse the grid iteratively instead of using recursion
    while (y != h && x != w) {
      int dx[] = {0, 1}, dy[] = {1, 0};
      cout << y + 1 << " " << x + 1 << endl;
      int next_x = x + dx[mp[y * w + x]];
      int next_y = y + dy[mp[y * w + x]];
      x = next_x;
      y = next_y;
    }
  }
  return 0;
}