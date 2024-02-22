#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  unsigned long long dp[4001];
  for (int j = 0; j < 4001; j++)
    dp[j] = j <= 1000 ? 1 : 0;
  
  for (int i = 2; i <= 4; i++) {
    for (int j = 0; j <= 4000 - i; j++) {
      unsigned long long temp = 0;
      for (int k = 0; k <= 1000; k++) {
        temp += dp[j - k];
      }
      dp[j] = temp;
    }
  }
  
  int n;
  while (cin >> n)
    cout << dp[n] << endl;
  
  return 0;
}