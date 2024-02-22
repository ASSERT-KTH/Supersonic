#include <iostream>
using namespace std;

int main() {
  unsigned short dp[4001][5];
  
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 4001; j++) {
      dp[j][i] = (i == 1 && j <= 1000) ? 1 : 0;
    }
  }
  
  for (int i = 2; i <= 4; i++) {
    for (int j = 0; j <= 4000; j++) {
      for (int k = 0; k <= j && k <= 1000; k++) {
        unsigned short prev = dp[j - k][i - 1];
        dp[j][i] += prev;
      }
    }
  }
  
  int n;
  while (cin >> n) {
    cout << dp[n][4] << endl;
  }
  
  return 0;
}