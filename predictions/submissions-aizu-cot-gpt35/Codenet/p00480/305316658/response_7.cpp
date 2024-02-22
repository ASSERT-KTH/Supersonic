#include <iostream>
using namespace std;

int main() {
  int a[101];
  long long dp[2][21] = {0}; // Use a 2D array of size [2][21]
  int N;
  cin >> N;
  
  for (int i = 1; i <= N; i++) {
    cin >> a[i];
  }
  
  dp[1][a[1]] = 1;
  
  for (int i = 2; i < N; i++) {
    for (int j = 0; j <= 20 - a[i]; j++) { // Adjusted inner loop limit
      if (j - a[i] >= 0)
        dp[i % 2][j] += dp[(i - 1) % 2][j - a[i]]; // Use modulo operator to access previous row
      if (j + a[i] <= 20)
        dp[i % 2][j] += dp[(i - 1) % 2][j + a[i]]; // Use modulo operator to access previous row
    }
  }
  
  cout << dp[(N - 1) % 2][a[N]] << endl; // Use modulo operator to access last row
  
  return 0;
}