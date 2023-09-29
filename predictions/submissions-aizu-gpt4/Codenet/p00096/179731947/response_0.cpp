#include <iostream>
using namespace std;

int main() {
  static unsigned long long dp[4001][5]{};
  for (int i = 0; i <= 1000; i++){
    dp[i][1] = 1;
  }
  for (int i = 2; i <= 4; i++){
    for (int j = 0; j <= 4000; j++){
      dp[j][i] = dp[j][i-1];
      if(j >= i){
        dp[j][i] += dp[j - i][i];
      }
    }
  }
  int n;
  while (cin >> n){
    cout << dp[n][4] << "\n";
  }
  return 0;
}