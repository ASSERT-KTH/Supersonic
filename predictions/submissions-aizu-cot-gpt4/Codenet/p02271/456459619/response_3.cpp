#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, t;
  cin >> n;
  vector<int> N(n);
  for (int i = 0; i < n; i++) {
    cin >> N[i];
  }
  cin >> t;
  int max_sum = 2000;  // Assume a reasonable maximum sum here
  vector<vector<bool>> dp(n+1, vector<bool>(max_sum+1, false));
  dp[0][0] = true;
  for(int i=1; i<=n; i++){
    for(int j=0; j<=max_sum; j++){
      if(j < N[i-1]) dp[i][j] = dp[i-1][j];
      else dp[i][j] = dp[i-1][j] || dp[i-1][j-N[i-1]];
    }
  }
  for (int i = 0; i < t; i++) {
    int p;
    cin >> p;
    if (p <= max_sum && dp[n][p]) {
      cout << "yes" << endl;
    } else {
      cout << "no" << endl;
    }
  }
  return 0;
}