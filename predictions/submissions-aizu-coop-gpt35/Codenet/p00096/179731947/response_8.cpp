#include <iostream>
using namespace std;

int main() {
  unsigned int dp[1001][5];
  
  for (int i = 2; i <= 4; i++) {
    for (int j = 0; j <= 1000; j++) {
      dp[j][i] = 0;
      for (int k = 0; k <= j && k <= 1000; k++) {
        dp[j][i] += dp[j - k][i - 1];
      }
    }
  }
  
  int n;
  while (cin >> n) {
    cout << dp[n][4] << endl;
  }
  
  return 0;
}