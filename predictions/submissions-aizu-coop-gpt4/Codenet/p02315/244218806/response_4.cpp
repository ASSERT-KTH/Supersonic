#include <iostream>
#include <vector>
using namespace std;
int main() {
  int N, W;
  cin >> N >> W;
  vector<int> v(N), w(N);
  vector<int> dp(W+1, 0);  // 1D array to replace original 2D array
  for (int i = 0; i < N; i++)
    cin >> v[i] >> w[i];
  for (int i = 0; i < N; i++) {
    for (int j = W; j >= w[i]; j--) {  // Reversed loop
      dp[j] = max(dp[j], dp[j - w[i]] + v[i]);  // No need for if-else condition
    }
  }
  cout << dp[W] << endl;
  return 0;
}