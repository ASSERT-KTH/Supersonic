#include <iostream>
#include <vector>
using namespace std;

int dp[10001]; // Use a 1D array instead of a 2D array

int main() {
  int N, W;
  scanf("%d %d", &N, &W); // Use faster I/O methods
  
  vector<int> v(N), w(N);
  for (int i = 0; i < N; i++)
    scanf("%d %d", &v[i], &w[i]); // Use faster I/O methods
  
  for (int i = 0; i < N; i++) {
    for (int j = W; j >= w[i]; j--) { // Unroll the inner loop and reverse the loop
      dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
    }
  }
  
  printf("%d\n", dp[W]); // Use faster I/O methods
  return 0;
}