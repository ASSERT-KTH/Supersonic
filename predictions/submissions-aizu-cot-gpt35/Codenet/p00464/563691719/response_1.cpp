#include <iostream>
using namespace std;

const int MAX = 1001;

int main() {
  int h, w, n;
  
  while (1) {
    cin >> h >> w >> n;
    if (!h && !w && !n)
      break;
    
    int mp[MAX][MAX], dp[MAX][MAX];
    
    for (int i = 0; i < h; i++)
      for (int j = 0; j < w; j++)
        cin >> mp[i][j];
    
    memset(dp, 0, sizeof(dp));
    dp[h-1][w-1] = n - 1;
    
    for (int i = h-1; i >= 0; i--) {
      for (int j = w-1; j >= 0; j--) {
        dp[i][j] += dp[i][j+1]/2 + mp[i][j] * dp[i][j+1] % 2;
        dp[i][j] += dp[i+1][j]/2 + !mp[i][j] * dp[i+1][j] % 2;
        mp[i][j] = (dp[i][j] % 2) ? !mp[i][j] : mp[i][j];
      }
    }
  }
  
  return 0;
}