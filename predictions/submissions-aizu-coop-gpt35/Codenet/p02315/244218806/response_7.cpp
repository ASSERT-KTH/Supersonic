#include <iostream>
#include <vector>
using namespace std;

int dp[1000][1000];

int main() {
  int N, W;
  cin >> N >> W;
  
  vector<int> v(N), w(N);
  v.reserve(N); // Reserve memory for N elements
  w.reserve(N); // Reserve memory for N elements
  
  for (int i = 0; i < N; i++)
    cin >> v[i] >> w[i];
  
  register int i, j; // Suggest storing i and j in registers
  register int max_value;
  
  for (i = 0; i < N; i++) {
    for (j = 0; j <= W; j++) {
      register int weight_diff = j - w[i]; // Move the condition outside the loop
      
      if (weight_diff < 0) {
        dp[i + 1][j] = dp[i][j];
      } else {
        max_value = dp[i][j];
        
        // Unroll the loop for better performance (can be done using pragma directive)
        for (int k = 0; k <= weight_diff; k += w[i]) {
          max_value = max(max_value, dp[i][weight_diff - k] + v[i]);
        }
        
        dp[i + 1][j] = max_value;
      }
    }
  }
  
  cout << dp[N][W] << endl;
  return 0;
}