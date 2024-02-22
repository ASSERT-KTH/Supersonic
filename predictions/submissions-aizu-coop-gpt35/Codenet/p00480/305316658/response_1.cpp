#include <iostream>
using namespace std;

int a[101];
long long dp[21];

int main() {
  int N;
  cin >> N;
  
  for (int i = 1; i <= N; i++) {
    cin >> a[i];
  }
  
  for (int i = 0; i <= 20; i++) {
    dp[i] = 0;
  }
  
  dp[a[1]] = 1;
  
  for (int i = 2; i < N; i++) {
    int left = max(0, j - a[i]);
    int right = min(20, j + a[i]);
    
    for (int j = 0; j <= 20; j += 2) {
      dp[j] += dp[left] + dp[right];
      dp[j + 1] += dp[left] + dp[right + 1];
      
      left = max(0, left - a[i]);
      right = min(20, right + a[i]);
    }
  }
  
  cout << dp[a[N]] << endl;
  return 0;
}